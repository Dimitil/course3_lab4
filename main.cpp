#include <iostream>
#include "List.h"
#include <random>
#include <ctime>

int main()
{
	const int maxX = 1080;
	const int maxY = 720;
	const unsigned int maxRadius = 500;

	srand(time(0));

	List l;

	for (size_t i = 0; i < 3; i++)
	{
		l.AddToTail(rand()%maxX, rand()%maxY, rand()%maxRadius);
	}



	List m;

	for (size_t i = 0; i < 6; i++)
	{
		m.AddToTail(rand() % maxX, rand() % maxY, rand() % maxRadius);
	}

	m = l;

	std::cout << m;

	std::cout << l;

	return 0;
}