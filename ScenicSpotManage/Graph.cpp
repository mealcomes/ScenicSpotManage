#include <string.h>
#include <vector>

#include "global.h"
#include "Tool.h"
#include "Graph.h"

std::vector<std::vector<int>> Path;
int ans = 0;

/*初始化图*/
void Init(m_Graph& graph) {
	for (int i = 0; i < Maxsize; i++) {
		for (int j = 0; j < Maxsize; j++)
			graph.m_aAdjMatrix[i][j] = 0;
	}
	graph.m_nVexNum = 0;
}

/*将顶点添加到顶点数组*/
bool InsertVex(m_Graph& graph, Vex vex) {
	if (graph.m_nVexNum == Maxsize)
		return false;
	graph.m_aVexs[graph.m_nVexNum++] = vex;
	return true;
}

/*将边保存到邻接矩阵中*/
bool InsertEdge(m_Graph& graph, Edge edge) {
	int a = edge.vex1, b = edge.vex2;
	if (a >= Maxsize || b >= Maxsize || a < 0 || b < 0)
		return false;
	graph.m_aAdjMatrix[a][b] = edge.weight;
	graph.m_aAdjMatrix[b][a] = edge.weight;
	return true;
}

/*查询指定顶点信息*/
Vex GetVex(m_Graph& graph, int nVex) {
	for (int i = 0; i < graph.m_nVexNum; i++)
		if (graph.m_aVexs[i].vexCount == nVex)
			return graph.m_aVexs[i];
	return { -1, L"", L"" };
}

/*遍历dfs图的各个部分*/
std::vector<std::vector<int>> dfsTravel(m_Graph& graph, int nVex) {
	std::vector<bool> visited(graph.m_nVexNum, false);
	visited[nVex] = true;
	Path.clear();
	Path.push_back(std::vector<int>());
	ans = 0;
	dfs(graph, nVex, visited);
	return Path;
}

/*dfs图的某一部分*/
void dfs(m_Graph& graph, int nVex, std::vector<bool>& visited) {
	Path[ans].push_back(nVex);   //将该点加入路径
	for (int i = 0; i < graph.m_nVexNum; i++) {
		if (!visited[i] && i != nVex && graph.m_aAdjMatrix[nVex][i] != 0) {
			visited[i] = true;
			dfs(graph, i, visited);
			visited[i] = false;
		}
	}
	Path[ans].pop_back();   //该情况该点之后的遍历结束 将该点从当前路径中移除
	for (int i = 0; i < graph.m_nVexNum; i++) {
		if (!visited[i])
			return;
	}
	Path.push_back(std::vector<int>(Path[ans]));  //该情况是一条可行路径 所以Path需要新加一个vector 以便存新的路径 同时将上一次路径值拷贝到新的路径
	Path[ans].push_back(nVex); //该情况是一条可行路径 由于上面移除了该点 所以这里需要再次将该点加入
	ans++;
}

/*Dijkstra找最短路径*/
int findShortPath(m_Graph& graph, int start, int end, std::vector<int>& shortPath) {
	std::vector<bool> isAdded(graph.m_nVexNum, false);
	std::vector<int> preVex(graph.m_nVexNum);
	std::vector<int> minDis(graph.m_nVexNum);
	isAdded[start] = true;
	for (int i = 0; i < graph.m_nVexNum; i++) {
		minDis[i] = ((graph.m_aAdjMatrix[start][i] == 0 && start != i) ? INT_MAX : graph.m_aAdjMatrix[start][i]);
		if (minDis[i] != INT_MAX && i != start)
			preVex[i] = start;
		else if (i == start)
			preVex[i] = i;
		else
			preVex[i] = -1;
	}
	for (int j = 0; j < graph.m_nVexNum - 1; j++) {
		int minVex = -1;
		for (int i = 0; i < graph.m_nVexNum; i++) {
			if(!isAdded[i] && (minVex == -1 || minDis[i] < minDis[minVex]))
				minVex = i;
		}
		isAdded[minVex] = true;
		for (int i = 0; i < graph.m_nVexNum; i++) {
			if (graph.m_aAdjMatrix[minVex][i] && minDis[i] > minDis[minVex] + graph.m_aAdjMatrix[minVex][i]) {
				minDis[i] = minDis[minVex] + graph.m_aAdjMatrix[minVex][i];
				preVex[i] = minVex;
			}
		}
	}

	int shortPathVex = end;
	shortPath[0] = shortPathVex;
	int length = 1;
	while (shortPathVex != start) {
		shortPath[length++] = preVex[shortPathVex];
		shortPathVex = preVex[shortPathVex];
	}
	return length;
}