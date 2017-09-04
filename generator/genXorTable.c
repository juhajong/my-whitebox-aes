char xorHiTable[0x100] = { 0 };
char xorLoTable[0x100] = { 0 };

void genXorTables(void)
{
    // end of mixColumns
    char index = 0;
    for (char hi=0; hi<0x10; hi++)
    {
        for (char lo=0; lo<0x10; lo++)
        {
            index = (hi << 4) + lo;

            xorLoTable[index] = hi ^ lo;
            xorHiTable[index] = (hi ^ lo) << 4;
        }
    }
}
