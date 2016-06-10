#include <iostream>
#include "../common/LinkedList.h"

using std::cout;

// Enter any assumptions you're making about the problem or any notes you want taken into account here
/*
*/

template <typename T>
SinglyLinkedList<T>* kthFromEnd(SinglyLinkedList<T>* ll, int k)
{
    // Fill me in
    return nullptr;
}

// Helper method declarations. Definitions near the bottom of the file.
void RunSingleTestCase(int testCaseNumber, SinglyLinkedList<int>* ll, int k, int expectedValue, bool expectNull);
void RunTestCases();

// This method shouldn't be very interesting to you
int main(int argc, char const *argv[])
{
    RunTestCases();

    return 0;
}

// Helper method definitions
void RunSingleTestCase(int testCaseNumber, SinglyLinkedList<int>* ll, int k, int expectedValue, bool expectNull)
{
    auto result = kthFromEnd(ll, k);

    if (!expectNull)
    {
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
            cout << "Testcase " << testCaseNumber << " FAILED: received a null return result from kthFromEnd\n";
        }
    }
    else
    {
        if (result == nullptr)
        {
            cout << "Testcase " << testCaseNumber << " PASSED\n";
        }
        else if (result->data == nullptr)
        {
            cout << "Testcase " << testCaseNumber << " FAILED: expected a null result but got a non-null result with null data. How did this happen?\n";
        }
        else
        {
            cout << "Testcase " << testCaseNumber << " FAILED: expected a null result but got " << *(result->data) << "\n";
        }
    }
}

void RunTestCases()
{
    // Testcase 1: standard usage
    auto simpleLinkedList = CreateSequentialSinglyLinkedList(5);
    RunSingleTestCase(/*testCaseNumber*/1, simpleLinkedList, /*k*/2, /*expectedValue*/3, /*expectNull*/false);
    
    // Testcase 2: k of 0
    // Note: behavior for this can be different than as written but you must make the distinction in what you expect
    // this case to return. Expectation here is that k of 1 returns the last result in the list
    RunSingleTestCase(/*testCaseNumber*/2, simpleLinkedList, /*k*/0, /*expectedvalue*/0, /*expectNull*/true);

    // Testcase 3: k of the length of the list
    RunSingleTestCase(/*testCaseNumber*/3, simpleLinkedList, /*k*/5, /*expectedValue*/0, /*expectNull*/false);

    // Testcase 4: k of a negative number. Again, you can define what this error case results in - I expect it to be null
    RunSingleTestCase(/*testCaseNumber*/4, simpleLinkedList, /*k*/-1, /*expectedValue*/0, /*expectNull*/true);

    // Testcase 5: k of a number larger than the length of the list. Same caveat with error case definition as above.
    RunSingleTestCase(/*testCaseNumber*/5, simpleLinkedList, /*k*/100, /*expectedValue*/0, /*expectNull*/true);

    // Testcase 6: a linked list with only one node
    SinglyLinkedList<int> test6;
    int test6_data = 7;
    test6.data = &test6_data;
    RunSingleTestCase(/*testCaseNumber*/6, &test6, /*k*/1, /*expectedValue*/7, /*expectedNull*/false);

    // Testcase 7: a null linked list aka a list with 0 nodes. Error case caveat.
    RunSingleTestCase(/*testCaseNumber*/7, nullptr, /*k*/1, /*expectedValue*/0, /*expectNull*/true);
}
