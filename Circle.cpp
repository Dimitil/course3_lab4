#include "Circle.h"

bool Circle::operator==(const Circle& C)
{
	return m_radius == C.m_radius && m_center == C.m_center;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

std::ostream& operator<<(std::ostream& os, const Circle& C)
{
	os << "Center: (" << C.m_center.getX() << ", "
		<< C.m_center.getY() << ")\n"
		<< "Radius: " << C.m_radius << '\n';
	return os;
}