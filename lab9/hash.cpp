#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

struct Node
{
    int value;
    int key;
    bool is_filled = false;
    bool was_used = false;
};

struct HashMap
{
    Node* array;
    size_t size;
    size_t filled_amount;
    double filled_ratio = 0;
};

bool is_prime(int n1, int n2)
{
    int min = std::min(n1, n2);
    int max_divider = std::sqrt(min);
    int divider = 2;
    while ((n1 % divider) * (n2 % divider) != 0 && divider <= max_divider){
        divider ++;
    }
    if (divider > max_divider){
        return true;
    }
    else{
        return false;
    }
}

int get_base(size_t size)
{
    int base = size - 2;
    while (!is_prime(base, size) && base > 0){
        base --;
    }
    if (base == 0){
        base = size - 1;
    }
    return base;
}

int do_hash(int key, int base, size_t size)
{
    int index = (key * base) % size;
    return index;
}

HashMap* create_hash()
{
    HashMap* hash = new HashMap;
    (*hash).array = new Node[1];
    (*hash).size = 1;
    (*hash).filled_amount = 0;
    return hash;
}

HashMap* reallocate(HashMap* hash)
{
    size_t new_size = (*hash).size * 2;
    Node* new_array = new Node[new_size];
    for (int index = 0; index < (*hash).size; index ++){
        if ((*hash).array[index].is_filled){
            int new_index = do_hash((*hash).array[index].key, new_size - 1, new_size);
            if (new_array[new_index].is_filled){
                int new_base = get_base(new_size);
                int key = (*hash).array[index].key;
                int index_delta = do_hash(key, new_base, new_size);
                while (new_array[new_index].is_filled){
                    new_index = new_index + index_delta;
                }
            }
            new_array[new_index].value = (*hash).array[index].value;
            new_array[new_index].key = (*hash).array[index].key;
            new_array[new_index].is_filled = true;
            new_array[new_index].was_used = true;
        }
    }
    delete[] (*hash).array;
    (*hash).array = new_array;
    (*hash).size = new_size;
    (*hash).filled_ratio = (*hash).filled_amount / (*hash).size;
    return hash;
}

HashMap* add(HashMap* hash, int value, int key)
{
    int base = (*hash).size - 1;
    int index = do_hash(key, base, (*hash).size);
    if ((*hash).array[index].is_filled){
        int new_base = get_base((*hash).size);
        int index_delta = do_hash(key, new_base, (*hash).size);
        while ((*hash).array[index].is_filled){
            index = (index + index_delta) % (*hash).size;
        }
    }
    (*hash).array[index].value = value;
    (*hash).array[index].key = key;
    (*hash).array[index].is_filled = true;
    (*hash).array[index].was_used = true;
    (*hash).filled_amount ++;
    (*hash).filled_ratio = (double)(*hash).filled_amount / (double)(*hash).size;
    if ((*hash).filled_ratio > 0.5){
        hash = reallocate(hash);
    }
    return hash;
}

HashMap* create_hash(size_t size)
{
    HashMap* hash = create_hash();
    int value;
    for (int key = 0; key < size; key ++){
        value = key;
        hash = add(hash, value, key);
    }
    return hash;
}

int find_value_by_key(HashMap* hash, int key)
{
    int base = (*hash).size - 1;
    int index = do_hash(key, base, (*hash).size);
    if ((*hash).array[index].was_used){
        if ((*hash).array[index].key != key){
            int new_base = get_base((*hash).size);
            int index_delta = do_hash(key, new_base, (*hash).size);
            while ((*hash).array[index].key != key && (*hash).array[index].was_used){
                index = (index + index_delta) % (*hash).size;
            }
        }
        if ((*hash).array[index].was_used){
            if ((*hash).array[index].is_filled){
                return (*hash).array[index].value;
            }
            else{
                std::cout << "Invalid argument" << '\n';
                return INT_MIN;
            }
        }
        else{
            std::cout << "Invalid argument" << '\n';
            return INT_MIN;
        }
    }
    else{
        std::cout << "Invalid argument" << '\n';
        return INT_MIN;
    }
}

int pop(HashMap* hash, int key)
{
    int base = (*hash).size - 1;
    int index = do_hash(key, base, (*hash).size);
    if ((*hash).array[index].was_used){
        if ((*hash).array[index].key != key){
            int new_base = get_base((*hash).size);
            int index_delta = do_hash(key, new_base, (*hash).size);
            while ((*hash).array[index].key != key && (*hash).array[index].was_used){
                index = (index + index_delta) % (*hash).size;
            }
        }
        if ((*hash).array[index].was_used){
            if ((*hash).array[index].is_filled){
                (*hash).array[index].is_filled = false;
                (*hash).filled_amount --;
                (*hash).filled_ratio = (double)(*hash).filled_amount / (double)(*hash).size;
                return (*hash).array[index].value;
            }
            else{
                std::cout << "Invalid argument" << '\n';
                return INT_MIN;
            }
        }
        else{
            std::cout << "Invalid argument" << '\n';
            return INT_MIN;
        }
    }
    else{
        std::cout << "Invalid argument" << '\n';
        return INT_MIN;
    }
}

void print_hash(HashMap* hash)
{
    std::cout << "--- Hash.array ---" << '\n';
    for (int index = 0; index < (*hash).size; index ++){
        if ((*hash).array[index].is_filled){
            std::cout << "Key: " << (*hash).array[index].key << "; value: " << (*hash).array[index].value << '\n';
        }
    }
    std::cout << "---" << '\n';
}

void print_hash_info(HashMap* hash)
{
    std::cout << "Size: " << (*hash).size << '\n';
    std::cout << "Filled_amount: " << (*hash).filled_amount << '\n';
    std::cout << "Filled_ratio: " << (*hash).filled_ratio << '\n';
}

void delete_hash(HashMap* hash)
{
    delete[] (*hash).array;
    delete[] hash;
}

int get_time(int find(HashMap*, int), HashMap* hash, int key, const int repeat_amount)
{
    const auto start = std::chrono::high_resolution_clock::now();
    for (int repeat = 0; repeat < repeat_amount; repeat ++){
        int value = find(hash, key);
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto system_time = end - start;
    const int time  = system_time.count();
    const int single_call_time = time / repeat_amount;
    return single_call_time;
}

void write_file(const size_t size, const int time, const std::string path)
{
    std::ofstream output;
    output.open(path, std::ios::app);
    if (output.is_open()){
        output << size << "; " << time << ';' << '\n';
        output.close();
    }
}

void make_test(const size_t size_start, const size_t size_finish, const double size_multiplier_step, const std::string path)
{
    const int checks_amount = 10;
    const int find_amount = 10000000;
    for (size_t size = size_start; size <= size_finish; size = size * size_multiplier_step){
        int time_min = -1;
        for (int i = 0; i < checks_amount; i ++){
            HashMap* hash = create_hash(size);
            int key = size / 2;
            const int time = get_time(find_value_by_key, hash, key, find_amount);
            delete_hash(hash);
            if (time > 0){
                if (time < time_min || time_min == -1){
                    time_min = time;
                }
            }
        }
        write_file(size, time_min, path);
        std::cout << "Size " << size << " tested" << '\n';
    }
}

void clear_file(const std::string path)
{
    std::ofstream output;
    output.open(path);
    if (output.is_open()){
        output.close();
    }
}

int main()
{
    const size_t size_start = 1, size_finish = 20000;
    const double size_multiplier_step = 2;
    const std::string path = "hash_result.txt";
    clear_file(path);
    make_test(size_start, size_finish, size_multiplier_step, path);
    return 0;
}
