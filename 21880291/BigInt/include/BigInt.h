#ifndef BIGINT_H
#define BIGINT_H
#define MAX_DIGITS 100

typedef struct {
	char
digits[MAX_DIGITS];
	int size;
	int is_negative; 
} BigInt;

BigInt initBigInt(const char *str, int base);
void toString(BigInt num, char *str, int base);

BigInt fromInt(int value);
int toInt(BigInt num);
void printBigInt(BigInt num, int base);

BigInt addBigInt(BigInt a, BigInt b);
BigInt subtractBigInt(BigInt a, BigInt b);
BigInt multiplyBigInt(BigInt a, BigInt b);
BigInt divideBigInt(BigInt a, BigInt b);
BigInt modBigInt(BigInt a, BigInt b);
BigInt negateBigInt(BigInt a);
BigInt absBigInt(BigInt a);
BigInt powerBigInt(BigInt base, unsigned int exponent);

int compareBigInt(BigInt a, BigInt b);
int equalsBigInt(BigInt a, BigInt b);
int notEqualsBigInt(BigInt a, BigInt b);
int lessThanBigInt(BigInt a, BigInt b);
int greaterThanBigInt(BigInt a, BigInt b);
int lessOrEqualsBigInt(BigInt a, BigInt b);
int greaterOrEqualsBigInt(BigInt a, BigInt b);

BigInt sqrtBigInt(BigInt a);
BigInt cbrtBigInt(BigInt a);
#endif

