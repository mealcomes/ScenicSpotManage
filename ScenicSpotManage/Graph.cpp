#include <string.h>
#include <vector>

#include "global.h"
#include "Tool.h"
#include "Graph.h"

std::vector<std::vector<int>> Path;
int ans = 0;

/*��ʼ��ͼ*/
void Init(m_Graph& graph) {
	for (int i = 0; i < Maxsize; i++) {
		for (int j = 0; j < Maxsize; j++)
			graph.m_aAdjMatrix[i][j] = ((i == j) ? 0 : INT_MAX);
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
	return { -1, L"", L"" };
}

/*����dfsͼ�ĸ�������*/
std::vector<std::vector<int>> dfsTravel(m_Graph& graph, int nVex) {
	std::vector<bool> visited(graph.m_nVexNum, false);
	visited[nVex] = true;
	Path.clear();
	Path.push_back(std::vector<int>());
	ans = 0;
	dfs(graph, nVex, visited);
	return Path;
}

/*dfsͼ��ĳһ����*/
void dfs(m_Graph& graph, int nVex, std::vector<bool>& visited) {
	Path[ans].push_back(nVex);   //���õ����·��
	for (int i = 0; i < graph.m_nVexNum; i++) {
		if (!visited[i] && i != nVex && graph.m_aAdjMatrix[nVex][i] < INT_MAX) {
			visited[i] = true;
			dfs(graph, i, visited);
			visited[i] = false;
		}
	}
	Path[ans].pop_back();   //������õ�֮��ı������� ���õ�ӵ�ǰ·�����Ƴ�
	for (int i = 0; i < graph.m_nVexNum; i++) {
		if (!visited[i])
			return;
	}
	Path.push_back(std::vector<int>(Path[ans]));  //�������һ������·�� ����Path��Ҫ�¼�һ��vector �Ա���µ�·�� ͬʱ����һ��·��ֵ�������µ�·��
	Path[ans].push_back(nVex); //�������һ������·�� ���������Ƴ��˸õ� ����������Ҫ�ٴν��õ����
	ans++;
}

/*Dijkstra�����·��*/
int findShortPath(m_Graph& graph, int start, int end, Edge shortPath[]) {
	std::vector<bool> isAdded(graph.m_nVexNum, false);
	std::vector<int> minDis(graph.m_nVexNum);
	isAdded[start] = true;
	for (int i = 0; i < graph.m_nVexNum; i++) {
		minDis[i] = graph.m_aAdjMatrix[start][i];
	}
	for (int i = 0; i < graph.m_nVexNum - 1; i++) {
		int minVex = -1;
		int Dis = INT_MAX;
		for (int i = 0; i < graph.m_nVexNum; i++) {
			if (minDis[i] < Dis && !isAdded[i])
				minVex = i;
		}
		isAdded[minVex] = true;
		for (int i = 0; i < graph.m_nVexNum; i++) {
			
		}
	}
	return 0;
}