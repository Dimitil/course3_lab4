#pragma once
#include "Node.h"
#include <iostream>

class List
{

    Node Head;
    Node Tail;
    size_t m_size;

public:

    List() : m_size(0)
    {
        Head.m_pNext = &Tail;
        Tail.m_pPrev = &Head;
    }

    ~List()
    {
        while (Head.m_pNext != &Tail)
        {
            delete Head.m_pNext;
        }
    }

    void AddToHead(const Circle& data)
    {
        new Node(&Head, &data);
        m_size++;
    }

    void AddToHead(int x, int y, int Radius)
    {
        AddToHead(Circle(x, y, Radius));
    }

    void AddToTail(const Circle& data)
    {
        new Node(Tail.m_pPrev, &data);
        m_size++;
    }

    void AddToTail(int x, int y, unsigned int Radius)
    {
        AddToTail(Circle(x, y, Radius));
    }

    bool RemoveOne(const Circle& data)//ищет и удаляет все копии
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

    bool RemoveOne(int x, int y, unsigned int Radius)//ищет и удаляет все копии
    {
        return RemoveOne(Circle(x, y, Radius));
    }

    size_t Remove(const Circle& data)//ищет и удаляет все копии возвращает количество удаленных
    {
        Node* p = Head.m_pNext;
        size_t deleted_count = 0;
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

    size_t Remove(int x, int y, unsigned int Radius)//ищет и удаляет все копии возвращает количество удаленных
    {
        return Remove(Circle(x, y, Radius));
    }

    void printAll()
    {
        Node* p = Head.m_pNext;
        int count=1;
        while (p != &Tail)
        {
            std::cout << '\n'<<count <<". "<< p->m_Data;
            p = p->m_pNext;
            count++;
        }
    }

    List(const List& other) : m_size(other.m_size)//конструктор копирования
    {
        Head.m_pNext = &Tail;
        Tail.m_pPrev = &Head;
    }


    //реализовать весь набор перемещающих и копирующих операторов и конструкторов
    //сделать список пустым??? как понять это???

};
