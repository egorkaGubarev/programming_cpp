int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new)
{
    int* p_new = NULL;
    if (n_new != 0){
        p_new = new int[n_new];
    }
    if (source != NULL){
        size_t amount = std::min(n_old, n_new);
        for (int i = 0; i < amount; i++){
            p_new[i] = source[i];
        }
        delete[] source;
    }
    return p_new;
}
