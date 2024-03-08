#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <fcntl.h>
#include <io.h>

#include "Tool.h"
#include "Graph.h"
#include "global.h"

/*�˵����*/
void MenuPrint() {
	std::cout << "=====������Ϣ����ϵͳ====\n";
	std::cout << "1.������������ͼ\n";
	std::cout << "2.��ѯ������Ϣ\n";
	std::cout << "3.���ξ��㵼��\n";
	std::cout << "4.�������·��\n";
	std::cout << "5.�����·�滮\n";
	std::cout << "0.�˳�\n";
	std::cout << "=========================\n";
}

/*ѡ������(max��ʾѡ�����ֵ)*/
int OptionInput(int max) {
	std::string input;
	std::cin >> input;
	input.erase(0, input.find_first_not_of(" \t")); // ȥ��ͷ���ո�
	input.erase(input.find_last_not_of(" \t") + 1); // ȥ��β���ո�
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

/*��ȡ�ļ��еĵ�*/
int readVex(m_Graph& graph) {
	std::wifstream wifs;

	wifs.open("data\\Vex.txt");
	if (!wifs.is_open()) {
		return -1;
	}
	//��ȡUTF-8�ļ�
	int vexCount;
	wifs.imbue(std::locale(wifs.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::codecvt_mode::consume_header>()));
	wifs >> vexCount;
	std::wcout << vexCount << L'\n';
	while (!wifs.eof()) {
		Vex vex;
		wifs >> vex.vexCount;
		wifs >> vex.name;
		wifs >> vex.desc;
		std::wcout << vex.vexCount << "-" << vex.name[0] << "��\n";
		InsertVex(graph, vex);
	}
	wifs.close();
	return vexCount;
}

/*��ȡ�ļ��б�*/
bool readEdge(m_Graph& graph) {
	std::wifstream wifs;
	wifs.open("data\\Edge.txt");
	if (!wifs.is_open()) {
		return false;
	}
	//��ȡUTF-8�ļ�
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