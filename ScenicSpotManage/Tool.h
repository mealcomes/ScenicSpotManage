//#include <string>
#ifndef _TOOL_H_
#define _TOOL_H_
#include <string>
#include "global.h"

void MenuPrint();
int OptionInput(std::string input, int max);
int readVex(m_Graph& graph);
bool readEdge(m_Graph& graph);

#endif // !_TOOL_H_