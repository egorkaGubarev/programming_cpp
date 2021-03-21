#include <iostream>

struct string {
    char* str;
    size_t size;
    size_t capacity;

    string()
    {
        str = new char[1];
        str[0] = '\0';
        size = 0;
        capacity = 0;
    }

    string(size_t cnt, char c)
    {
        capacity = get_degree(cnt);
        size_t full_size = capacity + 1;
        str = new char[full_size];
        for (int i = 0; i < cnt; i++){
            str[i] = c;
        }
        str[cnt] = '\0';
        size = cnt;
    }

    string(const string& s)
    {
        size = s.size;
        capacity = s.capacity;
        size_t full_size = capacity + 1;
        str = new char[full_size];
        for (int i = 0; i <= size; i ++){
            str[i] = s[i];
        }
    }

    string(char c)
    {
        size = 1;
        capacity = 1;
        size_t full_size = capacity + 1;
        str = new char[full_size];
        str[0] = c;
        str[1] = '\0';
    }

    string(const char* c_str)
    {
        size = 0;
        while (c_str[size] != '\0'){
            size ++;
        }
        capacity = get_degree(size);
        size_t full_size = capacity + 1;
        str = new char[full_size];
        for (int i = 0; i <= size; i++){
            str[i] = c_str[i];
        }
    }

    ~string()
    {
        delete[] str;
        str = NULL;
        size = 0;
        capacity = 0;
    }

    string& operator= (const string& new_str)
    {
        size = new_str.size;
        if (capacity < new_str.capacity){
            capacity = new_str.capacity;
            size_t full_size = capacity + 1;
            char* new_str = new char[full_size];
            delete[] str;
            str = new_str;
        }
        for (int i = 0; i <= size; i ++){
            str[i] = new_str[i];
        }
        return *this;
    }

    bool operator== (const string& other)
    {
        if (size != other.size){
            return false;
        }
        else{
            int i = 0;
            while (str[i] == other[i] && str[i] != '\0'){
                i ++;
            }
            if (i == size){
                return true;
            }
            else{
                return false;
            }
        }
    }

    bool operator!= (const string& other)
    {
        if (*this == other){
            return false;
        }
        else{
            return true;
        }
    }

    bool operator> (const string& other)
    {
        int i = 0;
        size_t size_min = std::min(size, other.size);
        while (str[i] == other[i] && i < size_min){
            i ++;
        }
        if (i == size_min){
            if (size > other.size){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if (str[i] > other[i]){
                return true;
            }
            else{
                return false;
            }
        }
    }

    bool operator< (const string& other)
    {
        if (*this != other && !(*this > other)){
            return true;
        }
        else{
            return false;
        }
    }

    string& operator+= (const string& other)
    {
        size_t new_size = size + other.size;
        size_t new_capacity = get_degree(new_size);
        reserve(new_capacity);
        for (int i = size; i <= size + other.size; i++){
            str[i] = other[i - size];
        }
        size = new_size;
        return (*this);
    }

    char operator[] (unsigned int pos) const
    {
        char symbol = str[pos];
        return symbol;
    }

    void append(const string other)
    {
        *this += other;
    }

    void resize(unsigned int new_capacity)
    {
        if (size >= new_capacity){
            capacity = new_capacity;
            size = capacity;
            str[size] = '\0';
        }
        else{
            reserve(new_capacity);
        }
    }

    void reserve(unsigned int new_capacity)
    {
        if (capacity < new_capacity){
            capacity = new_capacity;
            size_t full_size = capacity + 1;
            char* new_str = new char[full_size];
            for (int i = 0; i <= size; i ++){
                new_str[i] = str[i];
            }
            delete[] str;
            str = new_str;
        }
    }

    void insert(unsigned int pos, string other)
    {
        size_t new_size = size + other.size;
        capacity = get_degree(new_size);
        size_t full_size = capacity + 1;
        char* new_str = new char[full_size];
        for (int i = 0; i < pos; i ++){
            new_str[i] = str[i];
        }
        for (int i = pos; i < pos + other.size; i++){
            new_str[i] = other[i - pos];
        }
        for (int i = pos + other.size; i <= new_size; i++){
            new_str[i] = str[i - other.size];
        }
        delete[] str;
        str = new_str;
        size = new_size;
    }

    void shrink_to_fit()
    {
        (*this).resize(size);
    }

    void clear()
    {
        for (int i = 1; i <= size; i++){
            str[i] = '0';
        }
        str[0] = '\0';
        size = 0;
    }

    friend std::ostream& operator<< (std::ostream& ostr, const string& str)
    {
        for (int i = 0; i < str.size; i ++){
            ostr << str[i];
        }
        return ostr;
    }

    /* friend std::istream& operator>> (std::istream& istr, string& str)
    {
        int i = 0;
        do{
            istr >> str[i];
            i ++;
        } while (istr.peek() != '\n');
    } */

    int get_degree (int argument, int base=2)
    {
        int value = 1;
        while (argument > value){
            value = value * base;
        }
        return value;
    }

};


string operator + (string & str1, const string & str2)
{
    string my_string(str1);
    my_string += str2;
    return my_string;
}


int stoi(const string str, size_t* pos = NULL, int base = 10)
{
    *pos = 0;
    bool negative = false;
    if (str[*pos] == '-'){
        negative = true;
        (*pos) ++;
    }
    int code_max = 0;
    if (base >= 1 && base <= 10){
        code_max = '0' + base - 1;
    }
    else{
        if (base >= 11 && base <= 36){
            code_max = 'A' + base - 11;
        }
        else{
            if (base >= 37 && base <= 62){
                code_max = 'a' + base - 37;
            }
        }
    }
    int value = 0;
    int number;
    while (str[*pos] <= code_max && !(str[*pos] >= 58 && str[*pos] <= 64) && !(str[*pos] >= 91 && str[*pos] <= 96) && str[*pos] != '\0'){
        if (str[*pos] < 58){
            number = (int)str[*pos] - 48;
        }
        else{
            if (str[*pos] < 91){
                number = (int)str[*pos] - 48 - 7;
            }
            else{
                number = (int)str[*pos] - 48 - 7 - 6;
            }
        }
        value = value * base + number;
        (*pos) ++;
    }
    if (negative){
        value = -value;
    }
    if (*pos == str.size){
        return value;
    }
    else{
        std::cout << "Invalid argument" << '\n';
        return -2147483648;
    }
}

void print_string_info(string my_string)
{
    std::cout << "str: " << my_string << "; size: " << my_string.size << "; capacity: " << my_string.capacity << '\n';
}

int main()
{
    return 0;
}
