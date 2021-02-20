int* now_get_me_some_bytes(unsigned int n)
{
    int* p_array = new int[n];
    return p_array;
}


void now_free_some_bytes(int* p)
{
    delete[] p;
    p = NULL;
}
