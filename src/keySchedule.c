void keySchedule(char roundKey[11][4][4])
{
    char rcon[4][10] = {
        { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 },
        { 0 },
        { 0 },
        { 0 }};

    for ( int i=1; i<11; i++ )
    {
        // RotWord
        roundKey[i][0][0] = roundKey[i-1][1][3];
        roundKey[i][1][0] = roundKey[i-1][2][3];
        roundKey[i][2][0] = roundKey[i-1][3][3];
        roundKey[i][3][0] = roundKey[i-1][0][3];

        for ( int j=0; j<4; j++)
        {
            // SubBytes
            roundKey[i][j][0] = substitute(roundKey[i][j][0]);

            // Add rcon
            roundKey[i][j][0] ^= roundKey[i-1][j][0] ^ rcon[j][i-1];
        }

        // Complete remain words
        for ( int k=1; k<4; k++ )
        {
            for ( int l=0; l<4; l++)
            {
                roundKey[i][l][k] = roundKey[i-1][l][k] ^ roundKey[i][l][k-1];
            }
        }
    }

    return;
}
