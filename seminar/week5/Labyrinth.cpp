#include "stdafx.h"
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

struct Position
{
	size_t row, column;
	Position(size_t i, size_t j)
	{
		row = i; column = j;
	}
};

size_t dx[4] = { -1, 0, 1, 0 };
size_t dy[4] = { 0, -1, 0, 1 };

int main()
{
	ifstream inputFile("maze.txt", std::ios::in);
	if (!inputFile)
	{
		cout << "Cannot open file!" << endl;
		return 1;
	}
	size_t rows, columns;
	inputFile >> rows >> columns;
	if (!inputFile)
	{
		cout << "Cannot read from file!" << endl;
		return 1;
	}

	char** labyrinth = new char*[rows];
	for (size_t row = 0; row < rows; row++)
	{
		labyrinth[row] = new char[columns];
	}

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t column = 0; column < columns; column++)
		{
			inputFile >> labyrinth[row][column];
			if (!inputFile)
			{
				cout << "Error!" << endl;
				return 1;
			}
		}
	}

	size_t startRow, startColumn;
	inputFile >> startRow >> startColumn;
	if (!inputFile)
	{
		cout << "Start position is wrong!" << endl;
		return 1;
	}

	inputFile.close();

	Position start(startRow, startColumn);
	Position currentPos(0,0);

	std::queue<Position> posQueue;
	posQueue.push(start);

	labyrinth[startRow][startColumn] = '0';

	size_t layerIndex = 1;

	while (!posQueue.empty())
	{
		currentPos = posQueue.front();
		posQueue.pop();

		for (size_t i = 0; i < 4; i++)
		{
			Position newPos(currentPos.row + dx[i], currentPos.column + dy[i]);

			if (newPos.row >= 0 && newPos.row < rows && newPos.column >= 0 && newPos.column < columns && labyrinth[newPos.row][newPos.column] == '0')
			{
				char parentS = labyrinth[currentPos.row][currentPos.column];
				labyrinth[newPos.row][newPos.column] = parentS+1;
				posQueue.push(newPos);
			}
		}
		++layerIndex;
	}

	labyrinth[startRow][startColumn] = '*';

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t column = 0; column < columns; column++)
		{
			cout << labyrinth[row][column] << ' ';
		}
		cout << endl;
	}

	for (size_t row = 0; row < rows; row++)
	{
		delete[] labyrinth[row];
	}
	delete[] labyrinth;
	return 0;
}
