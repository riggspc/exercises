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

// For best results give this method the pointer to the first method in a linked list
template <typename T>
void DeleteSinglyLinkedListAndContents(SinglyLinkedList<T>* linkedList)
{
    // Base condition for recursion
    if (linkedList == nullptr)
    {
        return;
    }

    DeleteSinglyLinkedListAndContents(linkedList->next);

    // After recursively calling we should be deleted up to this point
    assert(linkedList->next == nullptr);
    if (linkedList->data != nullptr)
    {
        delete linkedList->data;
    }

    delete linkedList;
}

// This method relies on the << method being overloaded for whatever type T makes up the list
template <typename T>
void PrintSinglyLinkedList(SinglyLinkedList<T>* linkedList)
{
    bool isFirstNodeToPrint = true;

    while (linkedList != nullptr)
    {
        if (!isFirstNodeToPrint)
        {
            cout << ", ";
        }

        if (linkedList->data != nullptr)
        {
            cout << *(linkedList->data);
        }
        else
        {
            cout << "null";
        }

        linkedList = linkedList->next;
        isFirstNodeToPrint = false;
    }
    cout << "\n";
}
