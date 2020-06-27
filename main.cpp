#include <iostream>
#include "List.h"
#include <random>
#include <ctime>

int main()
{
	const int maxX = 1080;
	const int maxY = 720;
	const unsigned int maxRadius = 500;
	const size_t numOfElements = 24;

	srand(time(0));

	List l;

	for (size_t i = 0; i < numOfElements; i++)
	{
		l.AddToTail(rand()%maxX, rand()%maxY, rand()%maxRadius);
	}
	
	l.selectionSort();

	l.outInFile("TEST.TXT");

	List m;
	m.inputFromFile("TEST.TXT");
	std::cout << m;
	return 0;
}