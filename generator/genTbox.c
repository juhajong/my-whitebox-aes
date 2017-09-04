char tbox[10][0x10][0x100] = { 0 };

void genTboxes(char roundKey[11][0x10])
{
    // 0 ~ 8
    for (int r=0; r<9; r++)
    {
        // shiftRows
        shiftRows(roundKey[r]);
        // subBytes
        for (int i=0; i<0x10; i++)
        {
            for (int x=0; x<0x100; x++)
            {
                tbox[r][i][x] = sbox[(x ^ roundKey[r][i]) & 0xff] & 0xff;
            }
        }
    }
    // 9
    // shiftRows
    shiftRows(roundKey[9]);
    // subBytes
    for (int i=0; i<0x10; i++) {
        for (int x=0; x<0x100; x++)
        {
            tbox[9][i][x] = (sbox[(x ^ roundKey[9][i]) & 0xff] ^ roundKey[10][i]) & 0xff;
        }
    }

    // restore roundKeys
    for (int r=0; r<10; r++)
    {
        for (int i=0; i<3; i++)
        {
            shiftRows(roundKey[r]);
        }
    }
}
