#include <iostream>
#include <Windows.h>

//#include "Graph.h"
#include "Tourism.h"
#include "Tool.h"

int main() {
	std::string choice;
	do {
		MenuPrint();
		std::cout << "请输入您的选择(0-5):";
		switch (OptionInput(5)) {
		case 1:
			std::cout << "=====创建景区景点图=====\n";
			CreateGraph();
			std::cout << "\n\n";
			break;
		case 2:
			std::cout << "=====查询景点信息=====\n";
			GetSpotInfo();
			std::cout << "\n\n";
			break;
		case 3:
			std::cout << "=====旅游景点导航=====\n";
			travelPath();
			std::cout << "\n\n";
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			std::cout << "欢迎下次使用！";
			exit(0);
		default:
			std::cout << "选项无效!\n";
			break;
		}
		Sleep(800);
	} while (true);
}