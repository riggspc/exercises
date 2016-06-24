#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// Enter any assumptions you're making about the problem or any notes you want taken into account here
/*
*/

int FindOddNumberOut(vector<int> array)
{
    // Fill me in
    return 0;
}

// Helper method declarations. Definitions near the bottom of the file.
void RunSingleTestCase(int testCaseNumber, vector<int> array, int expectedValue);
void RunTestCases();

// This method shouldn't be very interesting to you
int main(int argc, char const *argv[])
{
    RunTestCases();

    return 0;
}

// Helper methods for running testCaseNumber
void RunSingleTestCase(int testCaseNumber, vector<int> array, int expectedValue)
{
    cout << "Testcase " << testCaseNumber;
    int result = FindOddNumberOut(array);

    if (result == expectedValue)
    {
        cout << " PASSED\n";
    }
    else
    {
        cout << " FAILED: expected " << expectedValue << " but got " << result << "\n";
    }
}

void RunTestCases()
{
    // Note that since the problem guarantees that the method will be given an array of
    // odd length and that only one number won't have a twin you won't be tested on cases
    // that don't match that criteria. It's great if your method can handle these cases
    // gracefully but it won't be tested

    // Testcase 1: generic array
    vector<int> array1 = {0, 2, 0, 2, 4};
    RunSingleTestCase(/*testCaseNumber*/1, array1, /*expectedValue*/4);

    // Testcase 2: array where the odd number out is the same as a number that has a partner
    vector<int> array2 = {0, 2, 0, 2, 2};
    RunSingleTestCase(/*testCaseNumber*/2, array2, /*expectedValue*/2);

    // Testcase 3: array of length 1
    vector<int> array3 = {2};
    RunSingleTestCase(/*testCaseNumber*/3, array3, /*expectedValue*/2);

    // Testcase 4: array of odd length of all the same number
    vector<int> array4 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    RunSingleTestCase(/*testCaseNumber*/4, array4, /*expectedValue*/2);

    // Testcases 5 and 6: more complex versions of Testcase 1, with negative numbers
    vector<int> array5 = {0, 6, -4, 9, 9, 9, 2, -4, 9, 7, 0, 6, 2, 0};
    RunSingleTestCase(/*testCaseNumber*/5, array5, /*expectedValue*/7);

    vector<int> array6 = {-10, -10, 5, 2, 5, 2, 99, 0, 100, 0, 99};
    RunSingleTestCase(/*testCaseNumber*/6, array6, /*expectedValue*/100);
}
