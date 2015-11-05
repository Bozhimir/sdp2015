// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>

template<typename T>
struct Elem
{
	T inf;
	Elem<T>* link;
	Elem(const T&, Elem<T>*);
};

template <typename T>
class Queue
{
public:
	Queue()
	{
		start = NULL; end = NULL; count = 0;
	}
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	~Queue();

	bool empty() const;
	size_t getCount() const;

	void push(const T& newVal)
	{
		Elem<T>* newElem = new Elem(newVal, NULL);
		if (empty())
		{
			start = newElem;
		}
		else
		{
			end->link = newElem;
		}
		end = newElem;
		++count;
	}

	//void pop(T&) safer than T& pop() because what if the queue is empty???
	void pop()
	{
		assert(!empty());
		Elem<T>* temp = start;
		start = start->link;
		if (!start) end = NULL;
		delete temp;
		--count;
	}

private:
	Elem<T>* start, *end;
	size_t count;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
