#ifndef define
class Point
{
		int m_x;
		int m_y;

	public:

		Point(int x = 0, int y = 0) : m_x(x), m_y(y) {};
		int getX() const { return m_x; }
		int getY() const { return m_y; }
		bool operator==(const Point& P) { return m_x == P.m_x && m_y == P.m_y; }
};
#endif

