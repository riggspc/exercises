#include <assert.h>
#include <iostream>

#include "LinkedList.h"

using std::cout;

SinglyLinkedList<int>* CreateSequentialSinglyLinkedList(int length)
{
    SinglyLinkedList<int>* result = nullptr;

    if (length > 0)
    {
        result = new SinglyLinkedList<int>;
        result->data = new int(0);
        auto previous = result;
        SinglyLinkedList<int>* current = nullptr;

        for (int i = 1; i < length; i++)
        {
            current = new SinglyLinkedList<int>;
            current->data = new int(i);
            previous->next = current;
            previous = current;
        }
    }

    return result;
}
