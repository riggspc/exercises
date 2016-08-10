#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// Enter any assumptions you're making about the problem or any notes you want taken into account here
/*
    Time complexity: O(n) where n is the target number of cents. In reality it'll be much less than this but it will scale
    with the size of the input.

    Space complexity: O(n) since we're called upon to output the coins used to make change in a vector. If we simply had
    to output the number of coins needed to make change then it would be O(1).
*/

// Method headers
vector<int> Solution(int numCents);
void RunSingleTestCase(int testCaseNumber, int numCents, vector<int> expected);
void RunTestCases();
void PrintVector(const vector<int>& v);

// This solution is using a simple greedy algorithm. Since the coins are known and pennies exist (making it always possible
// to make change since their value is 1) we can simply add the largest possible coin until we've reached the target value
vector<int> Solution(int numCents)
{
    vector<int> output = {};
    int valueSoFar = 0;

    while (valueSoFar != numCents)
    {
        int centsRemaining = numCents - valueSoFar;

        if (centsRemaining >= 25)
        {
            // Add a quarter
            valueSoFar += 25;
            output.push_back(25);
        }
        else if (centsRemaining >= 10)
        {
            // Add a dime
            valueSoFar += 10;
            output.push_back(10);
        }
        else if (centsRemaining >= 5)
        {
            // Add a nickel
            valueSoFar += 5;
            output.push_back(5);
        }
        else
        {
            // Add a penny
            valueSoFar += 1;
            output.push_back(1);
        }
    }

    return output;
}

int main(int argc, char const *argv[])
{
    RunTestCases();

    return 0;
}

void RunTestCases()
{
    // Note that the problem guarantees that our input will be a positive integer. Otherwise that would
    // be a great edgecase to test error handling. You may choose to handle such input and add tests 
    // to cover it. However, it's not necessary.

    // Testcase 1: simple solution
    vector<int> array1 = {25};
    RunSingleTestCase(/*testCaseNumber*/1, 25, array1);

    // Testcase 2: simple solution with multiple types of coin
    vector<int> array2 = {25, 5, 1};
    RunSingleTestCase(/*testCaseNumber*/2, 31, array2);

    // Testcase 3: solution requiring multiple of the same coin
    vector<int> array3 = {25, 25};
    RunSingleTestCase(/*testCaseNumber*/3, 50, array3);

    // Testcase 4: solution requiring multiples of several types of coin
    vector<int> array4 = {25, 25, 5, 1, 1, 1};
    RunSingleTestCase(/*testCaseNumber*/4, 58, array4);

    // Testcase 5: edge case for 0 cents
    vector<int> array5 = {};
    RunSingleTestCase(/*testCaseNumber*/5, 0, array5);
}

// Helper method for running a single test testCaseNumber
void RunSingleTestCase(int testCaseNumber, int numCents, vector<int> expected)
{
    cout << "Testcase " << testCaseNumber;
    auto result = Solution(numCents);
    bool failed = false;

    if (result.size() != expected.size())
    {
        failed = true;
    }

    for (unsigned int i = 0; i < result.size() && !failed; i++)
    {
        if (result[i] != expected[i])
        {
            failed = true;
        }
    }

    if (failed)
    {
        cout << " FAILED:\n    Expected: ";
        PrintVector(expected);
        cout << "\n    Actual: ";
        PrintVector(result);
        cout << "\n";
    }
    else
    {
        cout << " PASSED!\n";
    }
}

// Prints a pretty vector to stdout
void PrintVector(const vector<int>& v)
{
    cout << "[";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i];

        if (i != v.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}
