#include <stdio.h>

/*
 * This is a clever and fast method of getting a ceiling log2 of a number,
 * which could keep you away from the awful and slow (int)(log(x) / log(2)).
 * This method simply uses the machanism of how a float number is stored in
 * computer, making it easily understood to those who have had a knowledge of
 * it.
 * This method was first found in http://http://stereopsis.com/log2.html
 */
int FastLog2(int x)
{
    float fx;
    unsigned long ix, exp;

    fx = (float)x;
    ix = *(unsigned long*)&fx; // Flag for time of evil hacking.
    exp = (ix >> 23) & 0xFF;

    return exp - 127;
}

int main()
{
    int number;

    scanf("%d", &number);
    printf("%d\n", FastLog2(number));

    return 0;
}
