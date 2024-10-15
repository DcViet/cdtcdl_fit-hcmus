#include <stdio.h>
#include "BigInt.h"

int main()
{
    BigInt a = initBigInt("123456789012345678901234567890", 10);
    BigInt b = initBigInt("987654321098765432109876543210", 10);
    BigInt numHex = initBigInt("1A2B3C4D5E6F", 16);

    printf("a (base 10): ");
    printBigInt(a, 10);

    printf("b (base 10): ");
    printBigInt(b, 10);

    printf("numHex (base 16): ");
    printBigInt(numHex, 16);

    BigInt c = fromInt(123456789);
    printf("c (from int): ");
    printBigInt(c, 10);

    int value = toInt(c);
    printf("c (to int): %d\n", value);

    BigInt sum = addBigInt(a, b);
    printf("a + b = ");
    printBigInt(sum, 10);

    BigInt diff = subtractBigInt(b, a);
    printf("b - a = ");
    printBigInt(diff, 10);

    BigInt product = multiplyBigInt(a, b);
    printf("a * b = ");
    printBigInt(product, 10);

    BigInt quotient = divideBigInt(b, a);
    printf("b / a = ");
    printBigInt(quotient, 10);

    BigInt remainder = modBigInt(b, a);
    printf("b %% a = ");
    printBigInt(remainder, 10);

    BigInt nega = negateBigInt(a);
    printf("negate(a) = ");
    printBigInt(nega, 10);

    BigInt absValue = absBigInt(a);
    printf("abs(a) = ");
    printBigInt(absValue, 10);

    BigInt powerResult = powerBigInt(a, 2);
    printf("a ^ 2 = ");
    printBigInt(powerResult, 10);

    BigInt a1 = fromInt(16);
    BigInt b1 = fromInt(27);

    BigInt sqrtResult = sqrtBigInt(a1);
    printf("sqrt(a1) = ");
    printBigInt(sqrtResult, 10);

    BigInt cbrtResult = cbrtBigInt(b1);
    printf("cbrt(b1) = ");
    printBigInt(cbrtResult, 10);

    int cmpResult = compareBigInt(a, b);
    if (cmpResult < 0)
    {
        printf("-1(a<b)\n");
    }
    else if (cmpResult > 0)
    {
        printf("1(a>b)\n");
    }
    else
    {
        printf("0(a=b)\n");
    }

    return 0;
}
