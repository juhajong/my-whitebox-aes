char tyTable[4][0x100][4]  = { 0 };

void genTyTables(void)
{
    // start of mixColumns
    for (int i=0; i<4; i++)
    {
        for (int x=0; x<0x100; x++)
        {
            for ( int j=0; j<4; j++)
            {
                tyTable[i][x][j] = gfMultiply(x, mcMatrix[j][i]);
            }
        }
    }
}
