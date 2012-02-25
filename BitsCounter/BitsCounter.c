#include <stdio.h>

/*
 * This function would return how many 1s are there in the binary mode of the
 * given number. This code is not difficult to understand, for it simply uses an
 * elegant binary method.
 * This method was found in a post of Matrix67's blog:
 * http://www.matrix67.com/blog/archives/263
 */
unsigned long BitsCounter(unsigned long number)
{
    unsigned long x = number;

    /* Let's take the 8-bit number 0b10110100 as an example.
     *
     * The original number:
     *	1   0	1   1	0   1	0   0
     *
     * After the first step, it would be:
     *	0   1	1   0	0   1	0   0
     *
     * Notice that the leftmost 01 stands for the number of 1s in left-order
     * digits 1-2, and 10 the number of 1s in digits 3-4, etc.
     *
     * And after the second step, it would be:
     *	0   0	1   1	0   0	0   1
     *
     * And after the third step:
     *	0   0	0   0	0   1	0   0
     *
     * The final result 4 is exactly the number we want.
     */
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
    x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);

    return x;
}

int main()
{
    unsigned long number;

    scanf("%lu", &number);
    printf("%lu\n", BitsCounter(number));

    return 0;
}
