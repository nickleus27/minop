#include <stdio.h>

/**
 * @brief
 * We are looking at powers of 2 so this will translate
 * into binary operations with the underlying bits.
 *
 * Basic operations to reduce a binary number:
 *
 * Any power of 2 will be 1 operation, so any
 * bit pattern starting with a 1 and ending in zero or more 0's
 * will be one subtraction by 2^k
 * ex. 1, 10, 100, 1000
 *
 * we can further break down this process into the smallest component
 * removing all the trailing 0's leaves us with a single least significant bit
 *
 * The other most basic component will be a value of 3 or a bit with consecutive
 * 1's (11). This basic unit of the bit string will need an addition to give us 4
 * a 2 operation process
 *
 * So that covers the two possible operations to consider:
 *
 * a subtraction of 2^k (-2^k) will be a single 1 followed by 0 or more zeros
 *
 * an addition of 2^k (+2^k) for the value of the least significant bits = 3
 *
 * the algorithm will consist of adding to or subtracting depending on the lsb being a 1 or 3
 * removing 0's at the lsb will not warrant another operation
 *
 * lsb = 3 (11) +2^k
 * lsb = 1 (1)  -2^k
 * lsb = 0 (0*)  2^k (the operation count will end up with a single 1)
 *
 * 54:
 * 110110 (0) >> (1 shift)
 * 11011  (3) +1 +operation (2^1 + 54 = 56)
 * 11100  (0) >> (2 shift)
 * 1110   (0) >> (3 shift)
 * 111    (3) +1 +operation (2^3) + 56 = 64)
 * 1000   (0) >> (4 shift)
 * 100    (0) >> (5 shift)
 * 10     (0) >> (6 shift)
 * 1      (1) -1 -operation (2^6) -64 =0   (2^shifts right)
 *
 * 39:
 * 100111 (3) +1 +operation (2^0)
 * 101000 (0) >> (1 shift)
 * 10100  (0) >> (2 shift)
 * 1010   (0) >> (3 shift)
 * 101    (1) -1 -operation (2^3 - 40 = 32)
 * 100    (0) >> (4 shift)
 * 10     (0) >> (5 shift)
 * 1      (1) -1 -operation (2^5 - 32 = 0) (2^shifts right)
 *
 *
 * @param n
 * @return int
 */
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