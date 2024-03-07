#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "global.h"
void Init(m_Graph& graph);
bool InsertVex(m_Graph& graph, Vex vex);
bool InsertEdge(m_Graph& graph, Edge edge);
Vex GetVex(m_Graph& graph, int nVex);

#endif // !1