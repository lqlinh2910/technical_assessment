/*
* File: BinaryGap.c
* Author: LUU QUANG LINH
* Date: 18/06/2023
* Description: This is file for a technical assessment
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
* Function: decimalToBinary
* Description: This function use for convert Decimal number to binary number and print it.
* Input:
*   num - input number
* Output:
*   return: none
*/
void decimalToBinary(int num);

/*
* Function: solution
* Description: This function use for printf the length of longest binary gap of the binary number.
* Input:
*   num - positive integer N
* Output:
*   return: the length of its longest binary gap.
*/
int solution(int n);

int main()
{
    int decimalNumber;
    do {
        printf("Nhap so thap phan: ");
        scanf("%d", &decimalNumber);
    } while (decimalNumber < 1);

    decimalToBinary(decimalNumber);

    // Initially check that number must not
    // be 0 and power of 2
    printf("\nmax= %d", solution(decimalNumber));

    return 0;
}

void decimalToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int binaryNum[32];
    int i = 0;

    while (num > 0) {
        binaryNum[i++] = num % 2;
        num /= 2;
    }
    printf("So nhi phan la:");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

int solution(int n)
{
    // loop to find position of 1
    // sizeof int = 4 so total 32 bits
    int setBit = 1, prev = 0, i;
    for (i = 1; i <= sizeof(int) * 8; i++) {
        prev++;

        // we have found right most 1
        if ((n & setBit) == setBit) {
            setBit = setBit << 1;
            break;
        }

        // left shift setBit by 1 to check next bit
        setBit = setBit << 1;
    }

    // now loop through for remaining bits and find
    // position of immediate 1 after prev
    int max = 0, cur = prev;
    for (int j = i + 1; j <= sizeof(int) * 8; j++) {
        cur++;

        // if current bit is set, then compare
        // difference of cur - prev -1 with
        // previous maximum number of zeros
        if ((n & setBit) == setBit) {
            if (max < (cur - prev - 1))
                max = cur - prev - 1;

            // update prev
            prev = cur;
        }
        setBit = setBit << 1;
    }

    return max;
}


