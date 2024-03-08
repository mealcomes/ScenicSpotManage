#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <io.h>
#include <fcntl.h>

#include "Tourism.h"
#include "Graph.h"
#include "global.h"
#include "Tool.h"

m_Graph graph;

/*建图*/
bool CreateGraph() {
	Init(graph);

	//设置图的顶点
	std::wcout << "-----顶点-----\n";
	if ((graph.m_nVexNum = readVex(graph)) == -1)
		return false;

	//设置图的边
	std::wcout << "-----边-----\n";
	if (!readEdge(graph))
		return false;

	return true;
}

/*查询景点信息*/
void GetSpotInfo() {
	if (graph.m_nVexNum == 0) {
		std::cout << "当前无景点信息，请录入后查询!";
		return;
	}
	
	int previous = _setmode(_fileno(stdout), _O_U8TEXT);	//转化为utf-8解码输出，并保留先前的解码模式
	for (int i = 0; i < graph.m_nVexNum; i++) {
		std::wcout << graph.m_aVexs[i].vexCount << L"-" << graph.m_aVexs[i].name << "\n";
	}
	std::wcout << L"请输入想要查询的景点编号:";
	int nVex = OptionInput(graph.m_nVexNum);
	Vex vex = GetVex(graph, nVex);
	std::wcout << vex.name << "\n" << vex.desc << "\n";
	std::wcout << L"-----周边景区-----\n";
	for (int i = 0; i < graph.m_nVexNum; i++) {
		if (graph.m_aAdjMatrix[vex.vexCount][i] != 0 && vex.vexCount != i) {
			std::wcout << vex.name << L"->" << graph.m_aVexs[i].name << L" " << graph.m_aAdjMatrix[vex.vexCount][i] << L'\n';
		}
	}
	_setmode(_fileno(stdout), previous);        //输出解码模式恢复
}

/*旅游景点导航*/
void travelPath() {
	for (int i = 0; i < graph.m_nVexNum; i++)
		std::wcout << graph.m_aVexs[i].vexCount << "-" << graph.m_aVexs[i].name[0] << "区\n";
	std::cout << "请输入起始编号:";
	int nVex = OptionInput(graph.m_nVexNum);

	std::vector<std::vector<int>> Path;
	Path = dfsTravel(graph, nVex);
	if (!Path.size()) {
		std::cout << "暂时还没有能游览所有景区的路线!\n";
		return;
	}
	std::cout << "导航路线为:\n";
	for (int i = 0; i < Path.size(); i++) {
		if(Path[i].size() != 0)
			std::cout << "路线" << i + 1 << "：";
		for (int j = 0; j < Path[i].size(); j++) {
			if (j == 0) {
				std::wcout << graph.m_aVexs[Path[i][j]].name[0] << "区";
			}
			else {
				std::wcout<< " -> " << graph.m_aVexs[Path[i][j]].name[0] << "区";
			}
		}
		std::cout << '\n';
	}
}

void findShortPath() {
	for (int i = 0; i < graph.m_nVexNum; i++)
		std::wcout << graph.m_aVexs[i].vexCount << "-" << graph.m_aVexs[i].name[0] << "区\n";
	std::cout << "请输入起点编号:";
	int start = OptionInput(graph.m_nVexNum);
	std::cout << "请输入终点编号:";
	int end = OptionInput(graph.m_nVexNum);

	std::vector<int> shortPath(graph.m_nVexNum);
	int length = findShortPath(graph, start, end, shortPath);
	std::cout << "最短路线为：";
	int shortDis = 0;
	int previous = _setmode(_fileno(stdout), _O_U8TEXT);	//转化为utf-8解码输出，并保留先前的解码模式
	for (int i = length - 1; i >= 0; i--) {
		if(i == length - 1)
			std::wcout << graph.m_aVexs[shortPath[i]].name[0] << L"区";
		else
			std::wcout << L"->" << graph.m_aVexs[shortPath[i]].name[0] << L"区";
		if(i > 0)
			shortDis += graph.m_aAdjMatrix[shortPath[i]][shortPath[i - 1]];
	}
	_setmode(_fileno(stdout), previous);        //输出解码模式恢复
	std::cout << "\n最短距离为：" << shortDis << '\n';
}