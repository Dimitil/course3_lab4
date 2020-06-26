#include <iostream>
#include "List.h"

int main()
{
	List l;
	l.AddToHead(1, 2, 3);
    l.AddToHead(1, 2, 5);
	l.AddToHead(3, 2, 2);
	l.AddToTail(3, 2, 2);
    l.AddToTail(2, 3, 4);
    l.selectionSort();
	return 0;
}
