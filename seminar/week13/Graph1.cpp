// Graph1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include <queue>
#include <stack>

void BFS(graph<int>& g, int v)// graph i nachalen vryh
{
	queue<int> front;
	front.push(v);
	LList<int> visited;
	visited.toEnd(v);
	int currVertex;
	while (!front.empty())
	{
		currVertex = front.front();
		front.pop();
		elem_link1<int>* pV = g.point(currVertex);
		pV = pV->link;
		while (pV)
		{
			if (!isIn(visited, pV->inf))
			{
				front.push(pV->inf);
				visited.toEnd(pV->inf);
			}
			pV = pV->link;
		}
	}
}

void DFS(graph<int>& g, int v)// graph i nachalen vryh
{
	stack<int> front;
	front.push(v);
	LList<int> visited;
	visited.toEnd(v);
	int currVertex;
	while (!front.empty())
	{
		currVertex = front.top();
		front.pop();
		elem_link1<int>* pV = g.point(currVertex);
		pV = pV->link;
		while (pV)
		{
			if (!isIn(visited, pV->inf))
			{
				front.push(pV->inf);
				visited.toEnd(pV->inf);
			}
			pV = pV->link;
		}
	}
}

bool isIn(LList<int>& l, int x)
{
	l.iterStart();
	elem_link1<int>* current = l.iter();
	while (current)
	{
		if (current->inf == x)
		{
			return true;
		}
		current = current->link;
	}
	return false; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	graph<int> g;
	for (int i = 1; i <= 5; i++)
	{
		g.addTop(i);
	}
	
	g.addRib(1, 2);
	g.addRib(1, 4);
	g.addRib(2, 3);
	g.addRib(3, 4);
	g.addRib(3, 5);

	return 0;
}

