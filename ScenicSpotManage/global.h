#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#include <string>
#define Maxsize 128

struct Vex {
	int vexCount;            //������
	std::wstring name;      //��������
	std::wstring desc;    //�������
};
struct Edge {
	int vex1;    //�ߵĵ�һ������
	int vex2;    //�ߵĵڶ�������
	int weight;  //Ȩֵ
};
typedef struct Graph {
	int m_aAdjMatrix[Maxsize][Maxsize];//��Ӿ���
	Vex m_aVexs[Maxsize];              //��������
	int m_nVexNum = 0;                     //��ǰ�������
}m_Graph;  //Graph�������ڴ洢��������ͼ

#endif // !_GLOBAL_H
