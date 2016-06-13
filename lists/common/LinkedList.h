#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <assert.h>

using std::cout;

// This file defines two extremely simple linked list node structs, one for a singly linked list
// (with only a 'next' pointer) and one for a doubly linked list ('previous' pointer in addition
// to the 'next' pointer
// These are templated so they can hold a pointer to any type of information you'd like. It's
// important to note though that the data pointers should be considered weak - these structs 
// take no ownership of the data they're given

template <typename T>
struct SinglyLinkedList
{
    SinglyLinkedList* next = nullptr;
    T* data = nullptr;
};

template <typename T>
struct DoublyLinkedList
{
    DoublyLinkedList* previous = nullptr;
    DoublyLinkedList* next = nullptr;
    T* data = nullptr;
};

// Helper methods for singly linked lists. Create more as needed
SinglyLinkedList<int>* CreateSequentialSinglyLinkedList(int length);


// For best results give this method the pointer to the first node in a linked list
// This will not work if the list has any loops etc.
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

#endif /* LINKEDLIST_H */
