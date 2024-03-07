#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#include <string>
#define Maxsize 128

struct Vex {
	int vexCount;            //景点编号
	std::wstring name;      //景点名字
	std::wstring desc;    //景点介绍
};
struct Edge {
	int vex1;    //边的第一个顶点
	int vex2;    //边的第二个顶点
	int weight;  //权值
};
typedef struct Graph {
	int m_aAdjMatrix[Maxsize][Maxsize];//领接矩阵
	Vex m_aVexs[Maxsize];              //顶点数组
	int m_nVexNum = 0;                     //当前顶点个数
}m_Graph;  //Graph对象，用于存储景区景点图

#endif // !_GLOBAL_H
