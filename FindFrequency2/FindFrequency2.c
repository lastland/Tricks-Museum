#include <stdio.h>

/*
 * This is a method to find the only number that appears twice among other
 * numbers appear three times. It uses bit computation method to record
 * all bits that appear once and twice, so it can be used to find the number
 * appears once as well.
 * The code is simple and elegant.
 * This method was found in Zhihu: http://www.zhihu.com/question/19659409
 */
unsigned long FindFrequency2(unsigned long *lst, unsigned long length)
{
    unsigned long *num;
    unsigned long ones = 0, twos = 0, not_threes;

    for (num = lst; num < lst + length; num++)
    {
	twos |= ones & *num;	// Record all bits appear twice
	ones ^= *num;		// Record all bits appear once
	/*
	 * If a number appears three times, all bits of it are in both ones
	 * and twos. So we wipe out all bits in both of them from them.
	 */
	not_threes = ~(ones & twos);
	ones &= not_threes;
	twos &= not_threes; 
    }

    return twos; // Return ones if you want the number appears once
}

int main()
{
    unsigned long lst[] = {1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4};
    printf("%lu\n", FindFrequency2(lst, 11));
    return 0;
}
