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
            // this will be faster to just remove the 1
            // since we will just remove the lsb 0 next iteration
            n >>= 1;
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
            // we know the lsb will change to 0's
            // and removed anyways up until the point
            // of carry to a zero which will become a 1
            // so instead of potentially adding an extra 0
            // due to the carry, just remove the 1's until
            // first zero and then add 1
            while (n & 1)
            {
                n >>= 1;
            }
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