unsigned int count_total_mice_amount(Cat* cats, unsigned int n)
{
    unsigned int amount = 0;
    for (int i = 0; i < n; i++){
        amount = amount + cats[i].mice_caught;
    }
    return amount;
}
