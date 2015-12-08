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
#define VERIFY(a, b, val) verify(a, ASIZE(a), val, b, ASIZE(b))
static void Test0(void **state)
{
        int a1[] = {1, 2, 3, 4, 5, 6}, b1[] = {1, 2, 3, 4, 6};
        VERIFY(a1, b1, 5);

        int a2[] = {2}, b2[] = {2};
        VERIFY(a2, b2, 3);

        int a3[] = {4, 5}, b3[] = {5};
        VERIFY(a3, b3, 4);
}

int main(int argc, char *argv[])
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test(Test0)
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
