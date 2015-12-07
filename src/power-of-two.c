/* https://leetcode.com/problems/power-of-two/
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n - 1));
}

int main(int argc, char *argv[])
{
        assert(isPowerOfTwo(1) == true);
        assert(isPowerOfTwo(2) == true);
        assert(isPowerOfTwo(6) == false);
        return 0;
}
