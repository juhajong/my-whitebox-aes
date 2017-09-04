void addRoundKey(char state[0x10], const char roundKey[0x10])
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            state[4*i + j] ^= roundKey[4*i + j];
        }
    }
}
