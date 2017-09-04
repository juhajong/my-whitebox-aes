void printXorTables(void)
{
    char index = 0;

    printf("\nstatic char xorLoTable[0x100] = \n");
    printf("{");
    for (char hi=0; hi<0x10; hi++)
    {
        printf("\n    ");
        for (char lo=0; lo<0x10; lo++)
        {
            index = (hi << 4) + lo;
            printf("0x%02x, ", xorLoTable[index] & 0xff);
        }
    }
    printf("\n};\n");

    printf("\nstatic char xorHiTable[0x100] = \n");
    printf("{");
    for (char hi=0; hi<0x10; hi++)
    {
        printf("\n    ");
        for (char lo=0; lo<0x10; lo++)
        {
            index = (hi << 4) + lo;
            printf("0x%02x, ", xorHiTable[index] & 0xff);
        }
    }
    printf("\n};\n");
}

