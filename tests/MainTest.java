package tests; // ✅ Define package name

import solutions.Main; // ✅ Import the Main class

public class MainTest {
    private static int passed = 0;
    private static int total = 0;

    public static void runTestCase(int[] input, boolean expected) {
        total++;
        boolean actual = Main.containsDuplicate(input);

        if (actual == expected) {
            passed++;
            System.out.println("✅ Test Passed");
        } else {
            System.out.println("❌ Test Failed for input: " + java.util.Arrays.toString(input));
            System.out.println("   Expected: " + expected);
            System.out.println("   Actual  : " + actual);
        }
    }

    public static void main(String[] args) {
        runTestCase(new int[]{1, 2, 3, 4, 5}, false);
        runTestCase(new int[]{1, 2, 3, 1}, true);
        runTestCase(new int[]{}, false);
        runTestCase(new int[]{42}, false);
        runTestCase(new int[]{5, 5, 5, 5, 5}, true);
        runTestCase(new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE, 0, -1, 1}, false);
        runTestCase(new int[]{-1000000, 1000000, 0, -1000000, 5000}, true);
        runTestCase(new int[]{1, 1, 1, 1, 1}, true);
        runTestCase(new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false);

        System.out.printf("\n✅ Passed %d / %d test cases!\n", passed, total);
        if (passed != total) {
            throw new AssertionError("Some test cases failed!");
        }
    }
}
