#ifndef define
#include "Node.h"
#include <iostream>

class List
{

    Node Head;
    Node Tail;
    size_t m_size;

public:

    List();

    ~List();

    void AddToHead(const Circle& data);

    void AddToHead(int x, int y, int Radius);

    void AddToTail(const Circle& data);

    void AddToTail(int x, int y, unsigned int Radius);

    bool RemoveOne(const Circle& data);//���� � ������� ��� �����

    bool RemoveOne(int x, int y, unsigned int Radius);//���� � ������� ��� �����
    
    unsigned int Remove(const Circle& data);//���� � ������� ��� ����� ���������� ���������� ���������
   
    unsigned int Remove(int x, int y, unsigned int Radius);//���� � ������� ��� ����� ���������� ���������� ���������
    
    void printAll();

    void removeAll();

    List(const List& other);//����������� �����������
    
    List& operator=(const List& other); //�������� �����������

    List(List&& other); //������������ �����������

    List& operator=(List&& other); //�������� ������������ ������������;

    void selectionSort();
};
#endif
