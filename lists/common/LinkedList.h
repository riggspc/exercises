#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// This class defines two extremely simple linked list node classes, one for a singly linked list
// (with only a 'next' pointer) and one for a doubly linked list ('previous' pointer in addition
// to the 'next' pointer
// These are templated so they can hold a pointer to any type of information you'd like. It's
// important to note though that the data pointers should be considered weak - these classes 
// take no ownership of the data they're given

template <typename T>
struct SinglyLinkedList
{
    SinglyLinkedList* next;
    T* data;
};

template <typename T>
struct DoublyLinkedList
{
    DoublyLinkedList* previous;
    DoublyLinkedList* next;
    T* data;
};

#endif /* LINKEDLIST_H */