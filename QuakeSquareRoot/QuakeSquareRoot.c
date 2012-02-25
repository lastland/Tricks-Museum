#include <stdio.h>

/*
 * This is a fast method to calculate number's sqaure root.
 * Chris Lomont's essay said it could produce an inverse square root 4 times
 * faster than (1.0/sqrt(x)).
 * The most incredible part of this code is the magic constant 0x5f3759df,
 * which no one could ever tell what it is. However, with its help, we could
 * get a number which could produce the correct inverse square root in only
 * one step of Newton's iterative method.
 * This method was found in the source code of Quake 3, the game.
 */
float QuakeSquareRoot(float number)
{
    long i;
    float x, y;
    const float f = 1.5F;

    x = number * 0.5F; // This number would be used in the Newton's method.
    y = number;
    i = *(long *)&y; // Evil floating point bit level hacking.
    i = 0x5f3759df - (i >> 1); // What the fuck?
    y = *(float*)&i;
    y = y * (f - (x * y * y)); // The Newton's method.

    return number * y; // y is the inverse square root.
}

int main()
{
    float number;

    scanf("%f", &number);
    printf("%f\n", QuakeSquareRoot(number));

    return 0;
}
