// Graph1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include <queue>
#include <stack>

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

void BFS(graph<int>& g, int v, LList<int> visited)// graph i nachalen vryh
{
	queue<int> front;
	front.push(v);
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

void DFS(graph<int>& g, int v, LList<int> visited)// graph i nachalen vryh
{
	stack<int> front;
	front.push(v);
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

bool path(int a, int b, graph<int>& g, LList<int>& visited)
{
	if (a == b)
	{
		visited.toEnd(b);
		return true;
	}
	else
	{
		visited.toEnd(a);
		elem_link1<int>* pA = g.point(a);
		pA = pA->link;
		while (pA)
		{
			if (!isIn(visited, pA->inf))
			{
				if (path(pA->inf, b, g, visited)) return true;
				removeLast(visited); //maha posledniq element ot spisyka
			}
			pA = pA->link;
		}
		return false;
	}
}

int countConnectedComponents(graph<int>& g)
{
	int countComp = 0;
	LList<int> visited;
	if (!g.empty())
	{
		LList<int> v = g.vertexes();
		v.iterStart();
		elem_link1<int>* first = v.iter();
		int vertex = first->inf;
		BFS(g, vertex, visited);
		++countComp;
	}
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
	g.print();
	LList<int> visited;
	BFS(g, 4, visited);

	return 0;
}
