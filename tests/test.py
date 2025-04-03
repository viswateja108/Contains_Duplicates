import sys
import os

# Ensure the parent directory is in the Python path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from solutions.solution import Solution


def run_test_case(nums, expected, passed_count, total):
    total[0] += 1
    solution = Solution()  # Create an instance of Solution
    actual = solution.containsDuplicate(nums)  # Call the instance method

    if actual == expected:
        passed_count[0] += 1
        print(f"\n✅ {passed_count[0]}")
    else:
        print("\n❌ Test failed for input:", nums)
        print(f"Actual: {actual}, Expected: {expected}")

# ✅ Main function to run all test cases
def main():
    passed_count = [0]
    total = [0]

    # ✅ Basic Cases
    run_test_case([1, 2, 3, 4, 5], False, passed_count, total)
    run_test_case([1, 2, 3, 1], True, passed_count, total)
    run_test_case([], False, passed_count, total)
    run_test_case([42], False, passed_count, total)
    run_test_case([5, 5, 5, 5, 5], True, passed_count, total)

    # ✅ Edge Cases
    run_test_case([2**31 - 1, -2**31, 0, -1, 1], False, passed_count, total)  # INT_MAX, INT_MIN, etc.
    run_test_case([-1000000, 1000000, 0, -1000000, 5000], True, passed_count, total)  # Duplicate -1000000
    run_test_case([999999999, -999999999, 0], False, passed_count, total)  # Large values, no duplicates
    run_test_case([1] * 1000000, True, passed_count, total)  # Large input, all duplicates
    run_test_case(list(range(1000000)), False, passed_count, total)  # Large input, no duplicates

    # ✅ Summary
    print(f"\nPassed {passed_count[0]} / {total[0]} test cases!")
    if passed_count[0] != total[0]:
        raise AssertionError("Some test cases failed!")

if __name__ == "__main__":
    main()
