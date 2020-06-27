#ifndef define
#include "Node.h"
#include <iostream>
#include <fstream>
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

    friend std::ostream& operator<<(std::ostream& os, const List& l);

    void removeAll();

    List(const List& other);//����������� �����������
    
    List& operator=(const List& other); //�������� �����������

    List(List&& other); //������������ �����������

    List& operator=(List&& other); //�������� ������������ ������������;

    void selectionSort();

    void outInFile(const char* filename);

    void inputFromFile(const char* filename);
    
};
#endif
