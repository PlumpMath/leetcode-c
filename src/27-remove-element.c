/* https://leetcode.com/problems/remove-element/
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

int removeElement(int* nums, int numsSize, int val) {
        int ptr = 0;

        for (int i = 0; i < numsSize; i++) {
                if (nums[i] == val) continue;

                nums[ptr] = nums[i];
                ptr++;
        }
        return ptr;
}

static void test(void **state)
{
        int arr[5] = {1, 2, 3, 4, 5};
        assert_int_equal(removeElement(arr, 5, 5), 4); // {1, 2, 3, 4, 5}  => {1, 2, 3, 4}
        assert_int_equal(removeElement(arr, 4, 5), 4); // {1, 2, 3, 4}     => {1, 2, 3, 4}
        assert_int_equal(removeElement(arr, 4, 3), 3); // {1, 2, 3, 4}     => {1, 2, 4}
        assert_int_equal(removeElement(arr, 3, 1), 2); // {1, 2, 3, 4}     => {2, 4}
}

int main(int argc, char *argv[])
{
        const UnitTest tests[] = {
                unit_test(test)
        };

        return run_tests(tests);
}
