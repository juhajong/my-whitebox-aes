void printTboxes(void)
{
    printf("static char tbox[10][0x10][0x100] = \n");
    printf("{\n");
    for (int r=0; r<10; r++)
    {
        printf("    {\n");
        for (int i=0; i<0x10; i++)
        {
            printf("        {");
            for (int x=0; x<0x100; x++)
            {
                if (x % 0x10 == 0)
                {
                    printf("\n            ");
                }
                printf("0x%02x", tbox[r][i][x] & 0xff);
                if (x != 0xff)
                {
                    printf(", ");
                }
                else
                {
                    printf("\n");
                }
            }
            printf("        }");
            if (i != 0xf)
            {
                printf(",");
            }
            printf("\n");
        }
        printf("    }");
        if (r != 9)
        {
            printf(",");
        }
        printf("\n");
    }
    printf("};\n");
}
