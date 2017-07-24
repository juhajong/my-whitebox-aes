void shiftRows(char state[4][4])
{
    unsigned int row = 0;
    unsigned int hi  = 0;
    unsigned int lo  = 0;

    for (int i=1; i<4; i++)
    {
        row = ((unsigned int *)state)[i];

        hi = row >> (8 * i);
        lo = row << (8 * (4 - i));

        ((unsigned int *)state)[i] = hi + lo;
    }

}
