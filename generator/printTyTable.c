void printTyTables(void)
{
    printf("static char tyTable[4][0x100][4] = \n");
    printf("{\n");
    for (int i=0; i<4; i++)
    {
        printf("    {");
        for (int x=0; x<0x100; x++)
        {
            if (x % 4 == 0)
            {
              printf("\n        ");
            }
            printf("{");
            for (int j=0; j<4; j++)
            {
                printf("0x%02x", tyTable[i][x][j] & 0xff);
                if (j != 3)
                {
                    printf(", ");
                }
                else
                {
                    printf("}");
                }
            }
            if (x != 0xff)
            {
                printf(", ");
            }
            else
            {
                printf("\n");
            }
        }
        printf("    }");
        if (i != 3)
        {
            printf(",");
        }
        printf("\n");
    }
    printf("};\n");
}
