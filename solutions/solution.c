#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Comparator function for sorting.
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check if an array contains duplicates
bool containsDuplicate(int *nums, int numsSize) {
    if (numsSize <= 1) return false;

    // ✅ Sort the array (O(n log n))
    qsort(nums, numsSize, sizeof(int), compare);

    // ✅ Check adjacent elements for duplicates (O(n))
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}
