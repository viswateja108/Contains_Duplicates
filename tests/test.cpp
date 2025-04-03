#include <bits/stdc++.h>
#include "../solutions/solution.cpp"  // Include your solution file

using namespace std;

// Function to run individual test cases
void runTestCase(vector<int> arr, bool expected, int *passedCount, int *total)
{
    (*total)++;
    Solution solution;
    bool actual = solution.containsDuplicate(arr);

    if (actual == expected)
    {
        (*passedCount)++;
        cout << "\n✅ " << *(passedCount);
    }
    else
    {
        cout << "\n❌ Test failed for input: ";
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << "\nActual: " << actual << ", Expected: " << expected << endl;
    }
}

// ✅ Main function to run all test cases
int main()
{
    int passedCount = 0;
    int total = 0;

    // ✅ Basic Cases
    runTestCase({1, 2, 3, 4, 5}, false, &passedCount, &total);
    runTestCase({1, 2, 3, 1}, true, &passedCount, &total);
    runTestCase({5, 5, 5, 5, 5}, true, &passedCount, &total);

    // ✅ Edge Cases
    runTestCase({}, false, &passedCount, &total);         // Empty array
    runTestCase({42}, false, &passedCount, &total);       // Single element
    runTestCase({1, 1}, true, &passedCount, &total);      // Smallest possible duplicate case
    runTestCase({INT_MAX, INT_MIN, 0, -1, 1}, false, &passedCount, &total); // Min/max values, no duplicates
    runTestCase({INT_MAX, INT_MAX}, true, &passedCount, &total); // Duplicates of the largest int
    runTestCase({INT_MIN, INT_MIN}, true, &passedCount, &total); // Duplicates of the smallest int

    // ✅ Large Cases
    vector<int> largeUnique(100000); // Large input with unique elements
    iota(largeUnique.begin(), largeUnique.end(), 0);
    runTestCase(largeUnique, false, &passedCount, &total);

    vector<int> largeDuplicate(100000, 1); // Large input with all duplicates
    runTestCase(largeDuplicate, true, &passedCount, &total);

    // ✅ Summary
    cout << "\nPassed " << passedCount << " / " << total << " test cases!" << endl;
    if (passedCount != total)
    {
        assert(false);
    }

    return 0;
}
