#include <fstream>
#include <sstream>
#include <iostream>
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
	std::string choice;
	std::cin >> choice;
	int nVex = OptionInput(choice, graph.m_nVexNum);
	Vex vex = GetVex(graph, nVex);
	std::wcout << vex.name << "\n" << vex.desc << "\n";
	std::wcout << L"-----周边景区-----\n";
	for (int i = 0; i < graph.m_nVexNum; i++) {
		if (graph.m_aAdjMatrix[vex.vexCount][i] != 0) {
			std::wcout << vex.name << L"->" << graph.m_aVexs[i].name << L" " << graph.m_aAdjMatrix[vex.vexCount][i] << L'\n';
		}
	}
	_setmode(_fileno(stdout), previous);        //输出解码模式恢复
}