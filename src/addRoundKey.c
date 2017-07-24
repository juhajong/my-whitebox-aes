void addRoundKey(char state[4][4], char roundKey[4][4])
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            state[i][j] ^= roundKey[i][j];
        }
    }
}
