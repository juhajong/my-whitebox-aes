#include <stdio.h>
#include "transform.h"

void printBlock(char block[4][4])
{
    for (int i=0; i<4; i++)
    {
        printf("\t");
        for (int j=0; j<4; j++)
        {
            printf("%02x ", block[i][j] & 0xff);
        }
        printf("\n");
    }
    return;
}


int main(int argc, char *argv[])
{
    char plainText[0x10] = { 0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 };
    char cipherKey[0x10] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

    char state[4][4] = {0};
    char roundKey[11][4][4] = {0};

    // Initialize state and round key
    for ( int i=0; i<4; i++)
    {
        for ( int j=0; j<4; j++)
        {
            state[i][j]       = plainText[i + (4 * j)];
            roundKey[0][i][j] = cipherKey[i + (4 * j)];
        }
    }
    printf("plain text:\n");
    printBlock(state);
    printf("cipher key:\n");
    printBlock(roundKey[0]);

    // generate all round key
    keySchedule(roundKey);

    // encrypt
    addRoundKey(state, roundKey[0]);
    for ( int i=0; i<9; i++ )
    {
        subBytes(state);
        shiftRows(state);
        mixColumns(state);
        addRoundKey(state, roundKey[i+1]);
    }
    subBytes(state);
    shiftRows(state);
    addRoundKey(state, roundKey[10]);

 
    printf("cipher text:\n");
    printBlock(state);

    return 0;
}
