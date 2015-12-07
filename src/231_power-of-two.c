/* https://leetcode.com/problems/power-of-two/
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
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

bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n - 1));
}

// unittest with cmocka
static void verify(int n, bool result)
{
        if (result)
                assert_true(isPowerOfTwo(n));
        else
                assert_false(isPowerOfTwo(n));
}

static void Test0(void **state)
{
        verify(isPowerOfTwo(1), true);
        verify(isPowerOfTwo(2), true);
        verify(isPowerOfTwo(3), false);
        verify(isPowerOfTwo(6), false);
}

int main(int argc, char *argv[])
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test(Test0)
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
