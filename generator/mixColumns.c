const char mcMatrix[4][4] = 
{
    { 2, 3, 1, 1 },
    { 1, 2, 3, 1 },
    { 1, 1, 2, 3 },
    { 3, 1, 1, 2 }
};

char gfMultiply(const char src, const char value)
{
    char result = 0;

    if (value == 1)
    {
        result = src;
    }
    else if (value == 2)
    {
        result = src << 1;
        if (src & 0x80)
        {
            result ^= 0x1b;
        }
    }
    else if (value == 3)
    {
        result = (src << 1);
        if (src & 0x80)
        {
            result ^= 0x1b;
        }
        result ^= src;
    }

    return result;
}

char matrixMultiply(const char state[0x10], const int col, const int row)
{
    char result = 0;

    for (int i=0; i<4; i++)
    {
        result ^= gfMultiply(state[4*row + i], mcMatrix[col][i]);
    }

    return result;
}

void mixColumns(char state[0x10])
{
    char result[0x10] = {0};

    for ( int row=0; row<4; row++ )
    {
        for ( int col=0; col<4; col++ )
        {
            result[4*row + col] = matrixMultiply(state, col, row);
        }
    }
    for ( int i=0; i<0x10; i++ )
    {
        state[i] = result[i];
    }

    return;
}
