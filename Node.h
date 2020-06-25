#pragma once
#include "Circle.h"

class Node
{
	Node* m_pPrev;
	Node* m_pNext;
	Circle m_Data;

public:

	Node() : m_pPrev(nullptr), m_pNext(nullptr)	{}

    ~Node()
    {
        if (m_pPrev)
        {
            m_pPrev->m_pNext = this->m_pNext;
        }

        if (m_pNext)
        {
            m_pNext->m_pPrev = this->m_pPrev;
        }
    }

    Node(Node* beforeNew, const Circle* data) : m_Data(*data)
    {
        m_pPrev = beforeNew;
        m_pNext = beforeNew->m_pNext;
        beforeNew->m_pNext = this;
        m_pNext->m_pPrev = this;
    }

    friend class List;
};
