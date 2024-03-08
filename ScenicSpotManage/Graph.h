#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <vector>
#include "global.h"
void Init(m_Graph& graph);
bool InsertVex(m_Graph& graph, Vex vex);
bool InsertEdge(m_Graph& graph, Edge edge);
Vex GetVex(m_Graph& graph, int nVex);
std::vector<std::vector<int>> dfsTravel(m_Graph& graph, int nVex);
void dfs(m_Graph& graph, int nVex, std::vector<bool>& visited);
int findShortPath(m_Graph& graph, int start, int end, std::vector<int>& shortPath);
int finfMinTree(m_Graph graph, std::vector<Edge>& treeEdge);


#endif // !1