#include "Node.h"

Node::~Node()
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

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Node::Node(Node* beforeNew, const Circle* data) : m_Data(*data)
{
    m_pPrev = beforeNew;
    m_pNext = beforeNew->m_pNext;
    beforeNew->m_pNext = this;
    m_pNext->m_pPrev = this;
}
