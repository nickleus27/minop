#include <stdio.h>

int minOperations(int n)
{
    // count operations
    int ops = 0;
    while (n)
    {
        switch (n & 3)
        {
        // case 0 is where the lsb's are 00
        case 0:
            // remove lsb zero
            // will correspond with additions or subtractions
            n >>= 1;
            break;
        // case 1 is where the lsb's are 01
        case 1:
            // subtract 2^k operation
            ops += 1;
            // for the bit algorithm just subtract a 1
            n -= 1;
            break;
        // case 2 is where the lsb's are 10
        case 2:
            // remove lsb zero
            // will correspond with additions or subtractions
            n >>= 1;
            break;
        // case 3 is where the lsb's are 11
        case 3:
            // add 2^k operation
            ops += 1;
            // for the bit algorithm just add a 1
            n += 1;
        }
    }
    return ops;
}

int main()
{
    int k;
    scanf("%d", &k);
    printf("answer %d\n", minOperations(k));
    return 0;
}