#include <stdio.h>

/*
 * This is very smart method to implement Euclidean Algorithm in just one
 * line of code!
 * This method was first found on Renren.com. (The original writer is unknown)
 */
int gcd(int a, int b)
{
    while (a %= b ^= a ^= b ^= a);
    return b;
}

int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = gcd(b, a);
    printf("%d\n", c);
    return 0;
}
