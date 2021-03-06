#ifndef define
#include "Circle.h"

class List;
class Node
{

	Node* m_pPrev;
	Node* m_pNext;
	Circle m_Data;

public:

	Node() : m_pPrev(nullptr), m_pNext(nullptr)	{}

	~Node();

    Node(Node* beforeNew, const Circle* data);

    friend class List;

	friend std::ostream& operator<<(std::ostream& os, const List& l);

};
#endif
