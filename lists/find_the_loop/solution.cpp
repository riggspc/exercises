#include <iostream>
#include "../common/LinkedList.h"

using std::cout;

// Enter any assumptions you're making about the problem or any notes you want taken into account here
/*
*/

template <typename T>
SinglyLinkedList<T>* FindTheLoop(SinglyLinkedList<T>* ll)
{
    // Fill me in
    return nullptr;
}

// Helper method declarations. Definitions near the bottom of the file.
void RunSingleTestCase(int testCaseNumber, SinglyLinkedList<int>* ll, int expectedValue);
void RunTestCases();

// This method shouldn't be very interesting to you
int main(int argc, char const *argv[])
{
    RunTestCases();

    return 0;
}

// Helper methods for running tests
void RunSingleTestCase(int testCaseNumber, SinglyLinkedList<int>* ll, int expectedValue)
{
    auto result = FindTheLoop(ll);

    if (result != nullptr && result->data != nullptr && *(result->data) == expectedValue)
    {
        cout << "Testcase " << testCaseNumber << " PASSED\n";
    }
    else if (result != nullptr && result->data != nullptr)
    {
        cout << "Testcase " << testCaseNumber << " FAILED: expected " << expectedValue << " but got " << *(result->data) << "\n";
    }
    else if (result != nullptr)
    {
        cout << "Testcase " << testCaseNumber << " FAILED: data member variable of the returned list was null. How did this happen?\n";
    }
    else
    {
        cout << "Testcase " << testCaseNumber << " FAILED: received a null return result from FindTheLoop\n";
    }

}

void RunTestCases()
{
    // Note that since the problem guarantees that the method will be given a linked list with a 
    // loop that removes several test cases that would otherwise be of interest - namely a null list,
    // a list without a loop, etc. It's great if your method can handle these gracefully but they
    // won't be tested

    // Testcase 1: loop from the end to the second element
    auto simpleLinkedList = CreateSequentialSinglyLinkedList(5);
    auto simpleLinkedListLastNode = simpleLinkedList->next->next->next->next;
    simpleLinkedListLastNode->next = simpleLinkedList->next;
    RunSingleTestCase(/*testCaseNumber*/1, simpleLinkedList, /*expectedValue*/1);

    // Testcase 2: loop from the end to the beginning
    simpleLinkedListLastNode->next = simpleLinkedList;
    RunSingleTestCase(/*testCaseNumber*/2, simpleLinkedList, /*expectedValue*/0);

    // Testcase 3: loop from the end to itself
    simpleLinkedListLastNode->next = simpleLinkedListLastNode;
    RunSingleTestCase(/*testCaseNumber*/3, simpleLinkedList, /*expectedValue*/4);

    // Reset the end pointer so it can be properly deletd by DeleteSinglyLinkedListAndContents
    simpleLinkedListLastNode->next = nullptr;
    DeleteSinglyLinkedListAndContents(simpleLinkedList);
}
