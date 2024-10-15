#include <stdio.h>
#include <string.h>
#include "BigInt.h"

BigInt initBigInt(const char *str, int base)
{
    BigInt num = {{0}, 0, 0};
    int len = strlen(str);
    int start = 0;

    if (str[0] == '-')
    {
        num.is_negative = 1;
        start = 1;
    }

    for (int i = len - 1; i >= start; i--)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            num.digits[num.size++] = str[i] - '0';
        }
        else if (base == 16 && ('a' <= str[i] && str[i] <= 'f'))
        {
            num.digits[num.size++] = str[i] - 'a' + 10;
        }
        else if (base == 16 && ('A' <= str[i] && str[i] <= 'F'))
        {
            num.digits[num.size++] = str[i] - 'A' + 10;
        }
    }

    return num;
}

void toString(BigInt num, char *str, int base)
{
    int index = 0;

    if (num.is_negative)
    {
        str[index++] = '-';
    }

    for (int i = num.size - 1; i >= 0; i--)
    {
        if (base == 16 && num.digits[i] >= 10)
        {
            str[index++] = 'A' + (num.digits[i] - 10);
        }
        else
        {
            str[index++] = '0' + num.digits[i];
        }
    }

    str[index] = '\0';
}

BigInt fromInt(int value)
{
    char str[MAX_DIGITS];
    sprintf(str, "%d", value);
    return initBigInt(str, 10);
}

int toInt(BigInt num)
{
    int result = 0;

    for (int i = num.size - 1; i >= 0; i--)
    {
        result = result * 10 + num.digits[i];
    }

    return num.is_negative ? -result : result;
}

void printBigInt(BigInt num, int base)
{
    char str[MAX_DIGITS + 2];
    toString(num, str, base);
    printf("%s\n", str);
}

BigInt trimLeadingZeros(BigInt num)
{
    if (num.size == 1 && num.digits[0] == 0)
    {
        return num;
    }

    while (num.size > 1 && num.digits[num.size - 1] == 0)
    {
        num.size--;
    }

    return num;
}

BigInt addBigInt(BigInt a, BigInt b)
{
    BigInt result = {{0}, 0, 0};
    int carry = 0, i;

    for (i = 0; i < a.size || i < b.size || carry; i++)
    {
        int digitA = (i < a.size) ? a.digits[i] : 0;
        int digitB = (i < b.size) ? b.digits[i] : 0;
        int sum = digitA + digitB + carry;
        result.digits[result.size++] = sum % 10;
        carry = sum / 10;
    }

    return result;
}

BigInt subtractBigInt(BigInt a, BigInt b)
{
    BigInt result = {{0}, 0, 0};
    int borrow = 0, i;

    for (i = 0; i < a.size || i < b.size; i++)
    {
        int digitA = (i < a.size) ? a.digits[i] : 0;
        int digitB = (i < b.size) ? b.digits[i] : 0;
        int sub = digitA - digitB - borrow;

        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result.digits[result.size++] = sub;
    }

    while (result.size > 1 && result.digits[result.size - 1] == 0)
    {
        result.size--;
    }

    return result;
}

BigInt multiplyBigInt(BigInt a, BigInt b)
{
    BigInt result = {{0}, 0, 0};

    for (int i = 0; i < b.size; i++)
    {
        BigInt temp = {{0}, 0, 0};
        int carry = 0;

        for (int j = 0; j < a.size || carry; j++)
        {
            int prod = b.digits[i] * ((j < a.size) ? a.digits[j] : 0) + carry;
            temp.digits[temp.size++] = prod % 10;
            carry = prod / 10;
        }

        for (int k = 0; k < i; k++)
        {
            temp.digits[temp.size++] = 0;
        }

        result = addBigInt(result, temp);
    }

    return trimLeadingZeros(result);
}

BigInt divideBigInt(BigInt a, BigInt b)
{
    BigInt result = {{0}, 0, 0};
    BigInt remainder = {{0}, 0, 0};

    if (compareBigInt(b, (BigInt){{0}, 1, 0}) == 0)
    {
        printf("Error: Division by zero.\n");
        return result;
    }

    for (int i = a.size - 1; i >= 0; i--)
    {
        for (int j = remainder.size; j > 0; j--)
        {
            remainder.digits[j] = remainder.digits[j - 1];
        }
        remainder.digits[0] = a.digits[i];
        remainder.size++;

        while (remainder.size > 1 && remainder.digits[remainder.size - 1] == 0)
        {
            remainder.size--;
        }
        int count = 0;
        while (compareBigInt(remainder, b) >= 0)
        {
            remainder = subtractBigInt(remainder, b);
            count++;
        }

        result.digits[result.size++] = count;
    }

    while (result.size > 1 && result.digits[result.size - 1] == 0)
    {
        result.size--;
    }

    for (int i = 0; i < result.size / 2; i++)
    {
        char temp = result.digits[i];
        result.digits[i] = result.digits[result.size - i - 1];
        result.digits[result.size - i - 1] = temp;
    }

    return trimLeadingZeros(result);
}

BigInt modBigInt(BigInt a, BigInt b)
{
    BigInt quotient = divideBigInt(a, b);
    BigInt remainder = subtractBigInt(a, multiplyBigInt(quotient, b));
    return remainder;
}

BigInt negateBigInt(BigInt a)
{
    a.is_negative = !a.is_negative;
    return a;
}

BigInt absBigInt(BigInt a)
{
    a.is_negative = 0;
    return a;
}

BigInt powerBigInt(BigInt base, unsigned int exponent)
{
    BigInt result = fromInt(1);

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = multiplyBigInt(result, base);
        }
        base = multiplyBigInt(base, base);
        exponent /= 2;
    }

    return result;
}

int compareBigInt(BigInt a, BigInt b)
{
    if (a.size != b.size)
    {
        return a.size > b.size ? 1 : -1;
    }

    for (int i = a.size - 1; i >= 0; i--)
    {
        if (a.digits[i] != b.digits[i])
        {
            return a.digits[i] > b.digits[i] ? 1 : -1;
        }
    }

    return 0;
}

int equalsBigInt(BigInt a, BigInt b)
{
    return compareBigInt(a, b) == 0;
}

int notEqualsBigInt(BigInt a, BigInt b)
{
    return !equalsBigInt(a, b);
}

int lessThanBigInt(BigInt a, BigInt b)
{
    return compareBigInt(a, b) < 0;
}

int greaterThanBigInt(BigInt a, BigInt b)
{
    return compareBigInt(a, b) > 0;
}

int lessOrEqualsBigInt(BigInt a, BigInt b)
{
    return compareBigInt(a, b) <= 0;
}

int greaterOrEqualsBigInt(BigInt a, BigInt b)
{
    return compareBigInt(a, b) >= 0;
}

BigInt sqrtBigInt(BigInt a)
{
    BigInt left = fromInt(0);
    BigInt right = a;
    BigInt mid, square;

    while (compareBigInt(left, right) <= 0)
    {
        mid = divideBigInt(addBigInt(left, right), fromInt(2));
        square = multiplyBigInt(mid, mid);

        if (compareBigInt(square, a) == 0)
        {
            return mid;
        }
        else if (compareBigInt(square, a) < 0)
        {
            left = addBigInt(mid, fromInt(1));
        }
        else
        {
            right = subtractBigInt(mid, fromInt(1));
        }
    }

    return right;
}

BigInt cbrtBigInt(BigInt a)
{
    BigInt left = fromInt(0);
    BigInt right = a;
    BigInt mid, cube;

    while (compareBigInt(left, right) <= 0)
    {
        mid = divideBigInt(addBigInt(left, right), fromInt(2));
        cube = multiplyBigInt(multiplyBigInt(mid, mid), mid);

        if (compareBigInt(cube, a) == 0)
        {
            return mid;
        }
        else if (compareBigInt(cube, a) < 0)
        {
            left = addBigInt(mid, fromInt(1));
        }
        else
        {
            right = subtractBigInt(mid, fromInt(1));
        }
    }

    return trimLeadingZeros(right);
}
