void keySchedule(char roundKey[11][0x10])
{
    const char rcon[4][10] = {
        { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 },
        { 0 },
        { 0 },
        { 0 }};

    for ( int i=1; i<11; i++ )
    {
        // RotWord
        roundKey[i][0] = roundKey[i-1][12 + 1];
        roundKey[i][1] = roundKey[i-1][12 + 2];
        roundKey[i][2] = roundKey[i-1][12 + 3];
        roundKey[i][3] = roundKey[i-1][12 + 0];

        for ( int j=0; j<4; j++)
        {
            // SubBytes
            roundKey[i][j] = sbox[roundKey[i][j] & 0xff];

            // Add rcon
            roundKey[i][j] ^= roundKey[i-1][j] ^ rcon[j][i-1];
        }

        // Complete remain words
        for ( int k=1; k<4; k++ )
        {
            for ( int l=0; l<4; l++)
            {
                roundKey[i][l + 4*k] = roundKey[i-1][l + 4*k] ^ roundKey[i][l + 4*(k-1)];
            }
        }
    }

    return;
}
