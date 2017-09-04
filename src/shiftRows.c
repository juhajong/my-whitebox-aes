void shiftRows(char state[0x10])
{
    char tmp = 0;

    // second row
    tmp        = state[0x1];
    state[0x1] = state[0x5];
    state[0x5] = state[0x9];
    state[0x9] = state[0xd];
    state[0xd] = tmp;

    // third row
    tmp        = state[0x2];
    state[0x2] = state[0xa];
    state[0xa] = tmp;
    tmp        = state[0x6];
    state[0x6] = state[0xe];
    state[0xe] = tmp;
    
    // fourth row
    tmp = state[0xf];
    state[0xf] = state[0xb];
    state[0xb] = state[0x7];
    state[0x7] = state[0x3];
    state[0x3] = tmp;

    return;
}
