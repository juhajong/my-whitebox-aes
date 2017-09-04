#include <stdio.h>

#include "addRoundKey.c"
#include "subBytes.c"
#include "shiftRows.c"
#include "mixColumns.c"
#include "keySchedule.c"

#include "genTbox.c"
#include "genTyTable.c"
#include "genXorTable.c"

#include "printTbox.c"
#include "printTyTable.c"
#include "printXorTable.c"

int main(int argc, char *argv[])
{
    static char cipherKey[0x10] = { 0x79, 0x31, 0x53, 0x66, 0x52, 0x33, 0x76, 0x33, 0x72, 0x35, 0x49, 0x6e, 0x39, 0x6b, 0x65, 0x59 };

    char roundKey[11][0x10] = { 0 };

    // Initialize round key
    for (int i=0; i<0x10; i++)
    {
        roundKey[0][i] = cipherKey[i];
    }

    // generate all round keys
    keySchedule(roundKey);

    // generate all tables
    genTboxes(roundKey);
    printTboxes();

    genTyTables();
    printTyTables();  

    genXorTables();
    printXorTables();

    return 0;
}
