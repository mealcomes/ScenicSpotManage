#include <iostream>
#include <Windows.h>

//#include "Graph.h"
#include "Tourism.h"
#include "Tool.h"

int main() {
	std::string choice;
	do {
		MenuPrint();
		std::cout << "����������ѡ��(0-5):";
		switch (OptionInput(5)) {
		case 1:
			std::cout << "=====������������ͼ=====\n";
			CreateGraph();
			std::cout << "\n\n";
			break;
		case 2:
			std::cout << "=====��ѯ������Ϣ=====\n";
			GetSpotInfo();
			std::cout << "\n\n";
			break;
		case 3:
			std::cout << "=====���ξ��㵼��=====\n";
			travelPath();
			std::cout << "\n\n";
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			std::cout << "��ӭ�´�ʹ�ã�";
			exit(0);
		default:
			std::cout << "ѡ����Ч!\n";
			break;
		}
		Sleep(800);
	} while (true);
}