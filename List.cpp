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

bool List::RemoveOne(const Circle& data)//���� � ������� ��� �����
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

bool List::RemoveOne(int x, int y, unsigned int Radius)//���� � ������� ��� �����
{
    return RemoveOne(Circle(x, y, Radius));
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

unsigned int List::Remove(const Circle& data)//���� � ������� ��� ����� ���������� ���������� ���������
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

unsigned int List::Remove(int x, int y, unsigned int Radius)//���� � ������� ��� ����� ���������� ���������� ���������
{
    return Remove(Circle(x, y, Radius));
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

std::ostream& operator<<(std::ostream& os, const List& L)
{
    if (L.m_size == 0)
    {
        os << "\nList is empty\n";
        return os;
    }
    Node* p = L.Head.m_pNext;

    unsigned int count = 1;
    while (p != &L.Tail)
    {
        os <<count<<'.'<< p->m_Data;
        p = p->m_pNext;
        count++;
    }
    return os;
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

List::List(const List& other) : m_size(other.m_size)//����������� ������������
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

List& List::operator=(const List& other)//�������� �����������
{
    if (this==&other) //����������������
    {
        return *this;    
    }

    if (other.Head.m_pNext == &other.Tail)  //���� other ������ ��� m_size==0
    {
        Head.m_pNext = &Tail;
        Tail.m_pPrev = &Head;
        m_size = other.m_size;
    }

    removeAll(); //��������� ��� ��� ���� ��� ������

    Node* pThis = &Head;
    Node* pOther = other.Head.m_pNext;

    for (size_t i = 0; i < other.m_size; i++)
    {
        pThis = new Node(pThis, &pOther->m_Data);  //�����������
        pOther = pOther->m_pNext;
    }

    m_size = other.m_size;
    return *this;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

List::List(List&& other) : m_size(other.m_size) //������������ �����������
{
    if (other.Head.m_pNext == &other.Tail)  //���� other ������ ��� m_size==0
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

List& List::operator=(List&& other) //�������� ������������ ������������
{
    if (this == &other)//����������������
    {
        return *this;
    }

    removeAll();

    if (other.Head.m_pNext == &other.Tail)  //���� other ������ ��� m_size==0
    {
        m_size = other.m_size;      //0 ������ ����

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

void List::selectionSort()
{
    Node* p=Head.m_pNext;
    
    while(p != Tail.m_pPrev)
    {
        Node* minimal=p;
        Node* d=p->m_pNext;
        
        while(d != &Tail)
        {
            if(minimal->m_Data.getRadius()> d->m_Data.getRadius())
            {
                minimal=d;
            }
             d=d->m_pNext;
        }

        if(minimal!=p)
        {
            std::swap(minimal->m_Data, p->m_Data);  
        }
        p=p->m_pNext;
    }
}


//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void List::outInFile(const char* filename)
{
    std::ofstream fout(filename);
    if (fout)
    {
        fout << m_size << '\n';
        fout << *this << std::endl;

        std::cout << "\nWrite compeled\n";
        fout.close();
    }
    else
        std::cerr << "\nWriting error\n";
}


void List::inputFromFile(const char* filename)
{
    size_t size;
    char bufCh;
    char bufWord[80];
    unsigned int  bufCount;
    int bufX;
    int bufY;
    unsigned int bufRadius;

    std::ifstream fin(filename);
    if (fin)
    {
        fin >> size;
        for(size_t i=0; i<size; i++)
        {
            fin >> bufCount;
            fin >> bufWord; //   .Center: 
            fin >> bufCh;
            fin >> bufX;
            fin >> bufCh;
            fin >> bufY;
            fin >> bufCh;
            fin >> bufWord;
            fin >> bufRadius;
            this->AddToTail(bufX, bufY, bufRadius);
        }
        fin.close();
        std::cout << "\nRead compeled\n";
    }
    else
        std::cerr << "\nCannot open file\n";
}