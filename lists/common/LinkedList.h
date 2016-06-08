#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
template <typename T>
void DeleteSinglyLinkedListAndContents(SinglyLinkedList<T>* linkedList);
template <typename T>
void PrintSinglyLinkedList(SinglyLinkedList<T>* linkedList);

#endif /* LINKEDLIST_H */
