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

    bool RemoveOne(const Circle& data);//ищет и удаляет все копии

    bool RemoveOne(int x, int y, unsigned int Radius);//ищет и удаляет все копии
    
    unsigned int Remove(const Circle& data);//ищет и удаляет все копии возвращает количество удаленных
   
    unsigned int Remove(int x, int y, unsigned int Radius);//ищет и удаляет все копии возвращает количество удаленных

    friend std::ostream& operator<<(std::ostream& os, const List& l);

    void removeAll();

    List(const List& other);//конструктор копирования
    
    List& operator=(const List& other); //оператор копирования

    List(List&& other); //перемещающий конструктор

    List& operator=(List&& other); //оператор присваивания перемещением;

    void selectionSort();

    void outInFile(const char* filename);

    void inputFromFile(const char* filename);
    
};
#endif
