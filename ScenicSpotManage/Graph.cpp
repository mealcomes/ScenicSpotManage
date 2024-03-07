#include <string.h>

#include "global.h"
#include "Tool.h"
#include "Graph.h"

/*��ʼ��ͼ*/
void Init(m_Graph& graph){
	for (int i = 0; i < Maxsize; i++) {
		for (int j = 0; j < Maxsize; j++)
			graph.m_aAdjMatrix[i][j] = 0;
	}
	graph.m_nVexNum = 0;
}

/*��������ӵ���������*/
bool InsertVex(m_Graph& graph, Vex vex) {
	if (graph.m_nVexNum == Maxsize)
		return false;
	graph.m_aVexs[graph.m_nVexNum++] = vex;
	return true;
}

/*���߱��浽�ڽӾ�����*/
bool InsertEdge(m_Graph& graph, Edge edge) {
	int a = edge.vex1, b = edge.vex2;
	if (a >= Maxsize || b >= Maxsize || a < 0 || b < 0)
		return false;
	graph.m_aAdjMatrix[a][b] = edge.weight;
	graph.m_aAdjMatrix[b][a] = edge.weight;
	return true;
}

/*��ѯָ��������Ϣ*/
Vex GetVex(m_Graph& graph, int nVex) {
	for (int i = 0; i < graph.m_nVexNum; i++)
		if (graph.m_aVexs[i].vexCount == nVex)
			return graph.m_aVexs[i];
	return { -1, L"", L""};
}