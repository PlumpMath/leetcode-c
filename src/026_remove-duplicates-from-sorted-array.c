/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new
 * length.
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

int removeDuplicates(int* nums, int numsSize) {
        if (0 == numsSize) return 0;

        int ptr = 0;
        for (int i = 0; i < numsSize; i++) {
                if (nums[ptr] != nums[i])
                        nums[++ptr] = nums[i];
        }
        return (ptr + 1);
}

// unittest with cmocka
static void verify(int* nums, int numsSize, int* expect, int expectSize)
{
        assert_int_equal(removeDuplicates(nums, numsSize), expectSize);
        for (int i = 0; i < expectSize; i++) {
                assert_int_equal(nums[i], expect[i]);
        }
}

#define ASIZE(x)  (sizeof(x) / sizeof((x)[0]))
static void Test0(void **state)
{
        int t1[] = {1, 1, 2, 3}, t1e[] = {1, 2, 3};
        verify(t1,  ASIZE(t1),    // nums, numsSize
               t1e, ASIZE(t1e));  // expect, expectSize

        int t2[] = {1, 2, 2, 2, 3, 5}, t2e[] = {1, 2, 3, 5};
        verify(t2,  ASIZE(t2),    // nums, numsSize
               t2e, ASIZE(t2e));  // expect, expectSize
}

int main(int argc, char *argv[])
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test(Test0)
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
