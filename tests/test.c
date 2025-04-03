#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "../solutions/solution.c"  // Include your solution file

// Function to run individual test cases
void runTestCase(int arr[], int n, bool expected, int *passedCount, int *total) {
    (*total)++;
    bool actual = containsDuplicate(arr, n);

    if (actual == expected) {
        (*passedCount)++;
        printf("\n✅ %d", *passedCount);
    } else {
        printf("\n❌ Test failed for input: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nActual: %s, Expected: %s\n", actual ? "true" : "false", expected ? "true" : "false");
    }
}

// ✅ Main function to run all test cases
int main() {
    int passedCount = 0;
    int total = 0;

    // ✅ Basic Cases
    int arr1[] = {1, 2, 3, 4, 5};
    runTestCase(arr1, 5, false, &passedCount, &total);

    int arr2[] = {1, 2, 3, 1};
    runTestCase(arr2, 4, true, &passedCount, &total);

    int arr3[] = {5, 5, 5, 5, 5};
    runTestCase(arr3, 5, true, &passedCount, &total);

    // ✅ Edge Cases
    int arr4[] = {}; // Empty array
    runTestCase(arr4, 0, false, &passedCount, &total);

    int arr5[] = {42}; // Single element
    runTestCase(arr5, 1, false, &passedCount, &total);

    int arr6[] = {1, 1}; // Smallest possible duplicate case
    runTestCase(arr6, 2, true, &passedCount, &total);

    int arr7[] = {INT_MAX, INT_MIN, 0, -1, 1}; // Min/max values, no duplicates
    runTestCase(arr7, 5, false, &passedCount, &total);

    int arr8[] = {INT_MAX, INT_MAX}; // Duplicates of the largest int
    runTestCase(arr8, 2, true, &passedCount, &total);

    int arr9[] = {INT_MIN, INT_MIN}; // Duplicates of the smallest int
    runTestCase(arr9, 2, true, &passedCount, &total);

    // ✅ Large Cases
    int largeUnique[100000]; // Large input with unique elements
    for (int i = 0; i < 100000; i++) {
        largeUnique[i] = i;
    }
    runTestCase(largeUnique, 100000, false, &passedCount, &total);

    int largeDuplicate[100000]; // Large input with all duplicates
    for (int i = 0; i < 100000; i++) {
        largeDuplicate[i] = 1;
    }
    runTestCase(largeDuplicate, 100000, true, &passedCount, &total);

    // ✅ Summary
    printf("\nPassed %d / %d test cases!\n", passedCount, total);
    if (passedCount != total) {
        assert(0); // Force failure if any test fails
    }

    return 0;
}
