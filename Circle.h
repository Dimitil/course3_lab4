#pragma once
#include "Point.h"
#include <iostream>

class Circle
{
		Point m_center;
		unsigned int m_radius;

	public:

		Circle(Point center = Point(), unsigned int radius=100) : 
			m_center(center), m_radius(radius){}

		Circle(int x, int y, unsigned int radius) :
			m_center(x, y), m_radius(radius) {}

		bool operator==(const Circle& C);

		friend std::ostream& operator<<(std::ostream& os, const Circle& C);
};