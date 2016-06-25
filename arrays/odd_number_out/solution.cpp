#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

using std::cout;
using std::vector;
using std::unordered_map;

// Enter any assumptions you're making about the problem or any notes you want taken into account here
/*
    - We are assuming that we will always get valid input. If that wasn't the case we could simply
      assert that these invariants hold true at the beginning of FindOddNumberOut or define what error
      cases should return
*/

int GoodSolution(const vector<int>& array);
int BetterSolution(const vector<int>& array);

// To try this problem on your own simply delete GoodSolution and BetterSolution and don't
// read the hints below in FindOddNumberOut

// This method takes an array of integers guaranteed to be of matching pairs and one odd integer
// without a match and returns what that odd integer out is
int FindOddNumberOut(const vector<int>& array)
{
    // There are actually two solutions I'll put here. One of them is a 'good' solution,
    // with O(n) time and space complexity. The other is the 'better' solution, with O(n)
    // time complexity but O(1) space complexity. The better solution is a bit tougher
    // to get.

    // return GoodSolution(array);
    return BetterSolution(array);
}

// This solution uses a hash map to keep track of how many times we've seen each number
// Then after we loop through the array it's easy to go through the hash map and determine
// which number has been seen an odd number of times and is thus the odd man out
// Time complexity: O(n)
// Space complexity: O(n)
int GoodSolution(const vector<int>& array)
{
    unordered_map<int, int> seenNumbers;
    int arraySize = array.size();

    // Store the numbers from array in the hash map
    for (int i = 0; i < arraySize; i++)
    {
        auto it = seenNumbers.find(array[i]);
        if (it == seenNumbers.end())
        {
            seenNumbers[array[i]] = 1;
        }
        else
        {
            it->second++;
        }
    }

    // Iterate through the hash map to find the entry with an odd count
    for (auto it = seenNumbers.begin(); it != seenNumbers.end(); it++)
    {
        if (it->second % 2 == 1)
        {
            return it->first;
        }
    }

    // We should never get here - there should always be an entry in the hash
    // table that has an odd count
    assert(false);
}

// This solution uses bitwise arithmetic (specifically XOR) on all of the elements
// in the array. Since n XOR n == 0 and n XOR 0 == n we should be left with the odd
// number out after all XORing all of the numbers together
// Time complexity: O(n)
// Space complexity: O(1)
int BetterSolution(const vector<int>& array)
{
    int oddNumber = 0;
    int arraySize = array.size();

    for (int i = 0; i < arraySize; i++)
    {
        oddNumber ^= array[i];
    }

    return oddNumber;
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
