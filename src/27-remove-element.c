/* https://leetcode.com/problems/remove-element/
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

// unittest with cmocka
static void verify(int* nums, int numsSize, int val, int* expect, int expectSize)
{
        assert_int_equal(removeElement(nums, numsSize, val), expectSize);
        for (int i = 0; i < expectSize; i++) {
                assert_int_equal(nums[i], expect[i]);
        }
}

#define ASIZE(x)  (sizeof(x) / sizeof((x)[0]))
static void Test0(void **state)
{
        int t1[] = {1, 2, 3, 4, 5, 6}, t1e[] = {1, 2, 3, 4, 6};
        verify(t1,  ASIZE(t1),    // nums, numsSize
               5,                 // remove val
               t1e, ASIZE(t1e));  // expect, expectSize

        int t2[] = {2}, t2e[] = {2};
        verify(t2,  ASIZE(t2),    // nums, numsSize
               3,                 // remove val
               t2e, ASIZE(t2e));  // expect, expectSize

        int t3[] = {4, 5}, t3e[] = {5};
        verify(t3,  ASIZE(t3),    // nums, numsSize
               4,                 // remove val
               t3e, ASIZE(t3e));  // expect, expectSize
}

int main(int argc, char *argv[])
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test(Test0)
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
