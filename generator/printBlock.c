void printBlock(char block[0x10])
{
    for (int i=0; i<4; i++)
    {
        printf("\t");
        for (int j=0; j<4; j++)
        {
            printf("%02x ", block[i+ j*4] & 0xff);
        }
        printf("\n");
    }
    return;
}
