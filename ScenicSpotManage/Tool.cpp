#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <fcntl.h>
#include <io.h>

#include "Tool.h"
#include "Graph.h"
#include "global.h"

/*菜单输出*/
void MenuPrint() {
	std::cout << "=====景区信息管理系统====\n";
	std::cout << "1.创建景区景点图\n";
	std::cout << "2.查询景点信息\n";
	std::cout << "3.旅游景点导航\n";
	std::cout << "4.搜索最短路径\n";
	std::cout << "5.铺设电路规划\n";
	std::cout << "0.退出\n";
	std::cout << "=========================\n";
}

/*选项输入(max表示选项最大值)*/
int OptionInput(int max) {
	std::string input;
	std::cin >> input;
	input.erase(0, input.find_first_not_of(" \t")); // 去掉头部空格
	input.erase(input.find_last_not_of(" \t") + 1); // 去掉尾部空格
	if (input.length() != 1) {
		return -1;
	}
	else {
		int option = input[0] - '0';
		if (option <= max && option >= 0) {
			return option;
		}
		else {
			return -1;
		}
	}
}

/*读取文件中的点*/
int readVex(m_Graph& graph) {
	std::wifstream wifs;

	wifs.open("data\\Vex.txt");
	if (!wifs.is_open()) {
		return -1;
	}
	//读取UTF-8文件
	int vexCount;
	wifs.imbue(std::locale(wifs.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::codecvt_mode::consume_header>()));
	wifs >> vexCount;
	std::wcout << vexCount << L'\n';
	while (!wifs.eof()) {
		Vex vex;
		wifs >> vex.vexCount;
		wifs >> vex.name;
		wifs >> vex.desc;
		std::wcout << vex.vexCount << "-" << vex.name[0] << "区\n";
		InsertVex(graph, vex);
	}
	wifs.close();
	return vexCount;
}

/*读取文件中边*/
bool readEdge(m_Graph& graph) {
	std::wifstream wifs;
	wifs.open("data\\Edge.txt");
	if (!wifs.is_open()) {
		return false;
	}
	//读取UTF-8文件
	wifs.imbue(std::locale(wifs.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::codecvt_mode::consume_header>()));
	while (!wifs.eof()) {
		Edge edge;
		wifs >> edge.vex1;
		wifs >> edge.vex2;
		wifs >> edge.weight;
		std::wcout << "<v" << edge.vex1 << ",v" << edge.vex2 << "> " << edge.weight << '\n';
		InsertEdge(graph, edge);
	}
	wifs.close();
	return true;
}