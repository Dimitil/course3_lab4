#include "List.h"

List::List() : m_size(0)
{
    Head.m_pNext = &Tail;
    Tail.m_pPrev = &Head;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

List::~List()
{
    while (Head.m_pNext != &Tail)
    {
        delete Head.m_pNext;
    }
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void List::AddToHead(const Circle& data)
{
    new Node(&Head, &data);
    m_size++;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void List::AddToHead(int x, int y, int Radius)
{
    AddToHead(Circle(x, y, Radius));
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void List::AddToTail(const Circle& data)
{
    new Node(Tail.m_pPrev, &data);
    m_size++;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void List::AddToTail(int x, int y, unsigned int Radius)
{
    AddToTail(Circle(x, y, Radius));
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

bool List::RemoveOne(const Circle& data)//ищет и удаляет все копии
{
    Node* p = Head.m_pNext;
    while (p != &Tail)
    {
        if (p->m_Data == data)
        {
            m_size--;
            delete p;
            return true;
        }
        p = p->m_pNext;
    }
    return false;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

bool List::RemoveOne(int x, int y, unsigned int Radius)//ищет и удаляет все копии
{
    return RemoveOne(Circle(x, y, Radius));
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

unsigned int List::Remove(const Circle& data)//ищет и удаляет все копии возвращает количество удаленных
{
    Node* p = Head.m_pNext;
    unsigned int deleted_count = 0;
    while (p != &Tail)
    {
        if (p->m_Data == data)
        {
            m_size--;
            p = p->m_pPrev;
            delete p->m_pNext;
            deleted_count++;
        }
        p = p->m_pNext;
    }
    return deleted_count;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

unsigned int List::Remove(int x, int y, unsigned int Radius)//ищет и удаляет все копии возвращает количество удаленных
{
    return Remove(Circle(x, y, Radius));
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void List::printAll()
{
    if (m_size == 0) 
    { 
        std::cout << "\nList is empty\n"; 
        return;
    }
    Node* p = Head.m_pNext;
    int count = 1;
    while (p != &Tail)
    {
        std::cout << '\n' << count << ". " << p->m_Data;
        p = p->m_pNext;
        count++;
    }
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void List::removeAll()
{
    while (Head.m_pNext != &Tail)
    {
        delete Head.m_pNext;
    }

    m_size = 0;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

List::List(const List& other) : m_size(other.m_size)//конструктор копированием
{
    Head.m_pNext = &Tail;
    Tail.m_pPrev = &Head;

    Node* pThis = &Head;
    Node* pOther = other.Head.m_pNext;
    for (size_t i = 0; i < m_size; i++)
    {
        pThis = new Node(pThis, &pOther->m_Data);
        pOther = pOther->m_pNext;
    }
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

List& List::operator=(const List& other)//оператор копирования
{
    if (this==&other) //самоприсваевание
    {
        return *this;    
    }

    if (other.Head.m_pNext == &other.Tail)  //если other пустой или m_size==0
    {
        Head.m_pNext = &Tail;
        Tail.m_pPrev = &Head;
        m_size = other.m_size;
    }

    removeAll(); //почистить все что было тут раньше

    Node* pThis = &Head;
    Node* pOther = other.Head.m_pNext;

    for (size_t i = 0; i < other.m_size; i++)
    {
        pThis = new Node(pThis, &pOther->m_Data);  //скопировать
        pOther = pOther->m_pNext;
    }

    m_size = other.m_size;
    return *this;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

List::List(List&& other) : m_size(other.m_size) //перемещающий конструктор
{
    if (other.Head.m_pNext == &other.Tail)  //если other пустой или m_size==0
    {
        Head.m_pNext = &Tail;
        Tail.m_pPrev = &Head;
    }
    else
    {
        Head.m_pNext = other.Head.m_pNext;
        Tail.m_pPrev = other.Tail.m_pPrev;

        Head.m_pNext->m_pPrev = &Head;
        Tail.m_pPrev->m_pNext = &Tail;

        other.Head.m_pNext = &other.Tail;
        other.Tail.m_pPrev = &other.Head;
        other.m_size = 0;
    }
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

List& List::operator=(List&& other) //оператор присваивания перемещением
{
    if (this == &other)//самоприсваивание
    {
        return *this;
    }

    removeAll();

    if (other.Head.m_pNext == &other.Tail)  //если other пустой или m_size==0
    {
        m_size = other.m_size;      //0 должны быть

        Head.m_pNext = &Tail;
        Tail.m_pPrev = &Head;
    }
    else
    {
        Head.m_pNext = other.Head.m_pNext;
        Tail.m_pPrev = other.Tail.m_pPrev;

        Head.m_pNext->m_pPrev = &Head;
        Tail.m_pPrev->m_pNext = &Tail;

        other.Head.m_pNext = &other.Tail;
        other.Tail.m_pPrev = &other.Head;
        other.m_size = 0;
    }
    
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//

void List::sort()
{
    
}
