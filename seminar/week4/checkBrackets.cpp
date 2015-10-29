// week4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <string>

using namespace std;

bool CheckString(char* str)
{
	size_t strLength = strlen(str);
	stack<char> st;
	bool flag = true;
	size_t count = 0;
	while (count < strLength & flag)
	{
		if (str[count] == '{' | str[count] == '(')
		{
			st.push(str[count]);
		}
		if (str[count] == ')')
		{
			char symbol = st.top();
			if (symbol != NULL) st.pop();
			if (symbol == '{')
			{
				flag = false;
				break;
			}
		}
		if (str[count] == '}')
		{
			char symbol = st.top();
			if (symbol != NULL) st.pop();
			if (symbol == '(')
			{
				flag = false;
				break;
			}
		}
		count++;
	}
	if (!flag & !st.empty()) return false;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}
