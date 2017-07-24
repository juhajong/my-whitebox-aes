char gfMultiply(char src, char value)
{
    char result = 0;

    switch(value)
    {
        case 1:
            result = src;
            break;

        case 2:
            result = src << 1;
            if ( src & 0x80 )
            {
                result ^= 0x1b;
            }
            break;

        case 3:
            result = (src << 1);
            if ( src & 0x80 )
            {
                result ^= 0x1b;
            }
            result ^= src;
            break;

        default:
            break;
    }

    return result;
}

char matrixMultiply(char state[4][4], int col, int row)
{
    char result = 0;
    char matrix[4][4] = {
        {2, 3, 1, 1},
        {1, 2, 3, 1},
        {1, 1, 2, 3},
        {3, 1, 1, 2} };

    for (int i=0; i<4; i++)
    {
        result ^= gfMultiply(state[i][row], matrix[col][i]);
    }

    return result;

}

void mixColumns(char state[4][4])
{
    char result[4][4] = {0};

    for ( int row=0; row<4; row++ )
    {
        for ( int col=0; col<4; col++ )
        {
            result[col][row] = matrixMultiply(state, col, row);
        }
    }

    for ( int i=0; i<4; i++ )
    {
        for ( int j=0; j<4; j++ )
        {
            state[i][j] = result[i][j];
        }
    }

    return;
}
