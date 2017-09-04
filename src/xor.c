void xor(char src1[4], char src2[4], char dest[4])
{
    char hiNiddle = 0;
    char loNiddle = 0;

    char hiResult = 0;
    char loResult = 0;
    /*
    printf("\nsrc1: ");
    for (int i=0; i<4; i++)
    {
        printf("0x%02x, ", src1[i] & 0xff);
    }

    printf("\nsrc2: ");
    for (int i=0; i<4; i++)
    {
        printf("0x%02x, ", src2[i] & 0xff);
    }
    */
    for (int i=0; i<4; i++)
    {
        // hi
        hiNiddle = src1[i] & 0xf0;
        loNiddle = (src2[i] & 0xf0) >> 4;
        hiResult = xorHiTable[(hiNiddle + loNiddle) & 0xff];

        // lo
        hiNiddle = (src1[i] & 0x0f) << 4;
        loNiddle = (src2[i] & 0x0f);
        loResult = xorLoTable[(hiNiddle + loNiddle) & 0xff];

        // fi
        dest[i] = (hiResult + loResult) & 0xff;
    }
}
