#include <stdio.h>
#include "shiftRows.c"
#include "tables.c"
#include "xor.c"
#include "printBlock.c"

int main(int argc, char *argv[])
{
    static char plainText[0x10] = { 0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 };

    char state[0x10] = { 0 };
    char mixed[0x10] = { 0 };
    char tmp[2][4]   = { 0 };

    // Initialize state
    for (int i=0; i<0x10; i++)
    {
        state[i] = plainText[i];
    }

    printf("plain text:\n");
    printBlock(state);

    // encrypt
    for (int r=1; r<=9; r++ )
    {
        shiftRows(state);
        // T box
        for (int i=0; i<0x10; i++)
        {
            state[i] = tbox[r-1][i][state[i] & 0xff];
        }
        for (int col=0; col<4; col++)
        {
            // Ty table
            for (int i=0; i<4; i++)
            {
                for (int j=0; j<4; j++)
                {
                    mixed[i*4+j] = tyTable[i][state[(col*4+i) & 0xff] & 0xff][j];
                }
            }
            // Xor table
            xor(&mixed[0x0], &mixed[0x4], tmp[0]);
            xor(&mixed[0x8], &mixed[0xc], tmp[1]);
            xor(tmp[0], tmp[1], &state[col * 4]);
        }
    }
    shiftRows(state);
    for (int i=0; i<0x10; i++)
    {
        state[i] = tbox[9][i][state[i] & 0xff];
    }

    printf("\ncipher text:\n");
    printBlock(state);


    for (int i=0; i<0x10; i++)
    {
        printf("0x%02x, ", state[i] & 0xff);
    }
    return 0;
}
