#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

std::mt19937 create_random_engine()
{
    std::mt19937 engine(0);
    return engine;
}

std::uniform_int_distribution<int> create_random_distribution()
{
    std::uniform_int_distribution<int> int_dist(0, 10000);
    return int_dist;
}

int* create_sorted_array(const size_t size)
{
    int* array = new int[size];
    for (int i = 0; i < size; i ++){
        array[i] = i;
    }
    return array;
}

int* create_random_array(const size_t size)
{
    std::mt19937 engine = create_random_engine();
    std::uniform_int_distribution<int> int_dist = create_random_distribution();
    int* array = new int[size];
    for (int i = 0; i < size; i ++){
        array[i] = int_dist(engine);
    }
    return array;
}

int get_time(int* sort(int*, const size_t), int* array, const int repeat_amount,  const size_t size)
{
    int* array_sorted = NULL;
    const auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < repeat_amount; i ++){
        array_sorted = sort(array, size);
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto system_time = end - start;
    const int time  = system_time.count();
    const int single_call_time = time / repeat_amount;
    return single_call_time;
}

int get_time(int* sort(int*, const int, const int), int* array, const int repeat_amount, const int left, const int right)
{
    int* array_sorted = NULL;
    const auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < repeat_amount; i ++){
        array_sorted = sort(array, left, right);
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto system_time = end - start;
    const int time  = system_time.count();
    const int single_call_time = time / repeat_amount;
    return single_call_time;
}

int* make_bubble_sort(int* array, const size_t size)
{
    for (int j = 0; j < size - 1; j ++){
        bool swap_done = false;
        for (int i = 0; i < size - 1 - j; i ++){
            if (array[i] > array[i + 1]){
                std::swap(array[i], array[i + 1]);
                swap_done = true;
            }
        }
        if (!swap_done){
            break;
        }
    }
    return array;
}

int* make_selection_sort(int* array, const size_t size)
{
    for (int i = 0; i < size - 1; i ++){
        int min_i = i;
        for (int j = i + 1; j < size; j ++){
            if (array[j] < array[min_i]){
                min_i = j;
            }
        }
        if (min_i != i){
            std::swap(array[i], array[min_i]);
        }
    }
    return array;
}

int* make_insertion_sort(int* array, const size_t size)
{
    for(int j = 1; j < size; j ++){
        const int key = array[j];
        int i = j - 1;
        while(i > -1 && array[i] > key){
            array[i + 1] = array[i];
            i --;
        }
        array[i + 1] = key;
    }
    return array;
}

int partition(int* array, const int left, const int right)
{
    const int reference = array[(left + right) / 2];
    int i = left;
    int j = right;
    while(i <= j){
        while (array[i] < reference){
            i ++;
        }
        while (array[j] > reference){
            j --;
        }
        if (i >= j){
            break;
        }
        std::swap(array[i ++], array[j --]);
    }
    return j;
}

int* make_quicksort(int* array, const int left, const int right)
{
    if(left < right){
        int q = partition(array, left, right);
        array = make_quicksort(array, left, q);
        array = make_quicksort(array, q + 1, right);
    }
    return array;
}

void clear_file(const std::string path)
{
    std::ofstream output;
    output.open(path);
    if (output.is_open()){
        output.close();
    }
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

int make_samll_size_test(int* generate_array(const size_t), int* sort(int*, const size_t), const size_t size)
{
    return 0;
}

void make_test(int* generate_array(const size_t), int* sort(int*, const size_t), const size_t size_start, const size_t size_finish, const double size_multiplier_step,
               const std::string path)
{
    const int sort_amount = 1;
    const int checks_amount = 10;
    const int short_array_sort_max_amount = 1000000;
    for (size_t size = size_start; size <= size_finish; size = size * size_multiplier_step){
        int time_min = -1;
        for (int i = 0; i < checks_amount; i ++){
            int* array = generate_array(size);
            const int time = get_time(sort, array, sort_amount, size);
            delete[] array;
            if (time > 0){
                if (time < time_min || time_min == -1){
                    time_min = time;
                }
            }
        }
        if (time_min == -1){
            for (int i = 0; i < checks_amount; i ++){
                int* array = generate_array(size);
                int short_array_sort_amount = short_array_sort_max_amount / size;
                const int time = get_time(sort, array, short_array_sort_amount, size);
                delete[] array;
                if (time > 0){
                    if (time < time_min || time_min == -1){
                        time_min = time;
                    }
                }
            }
        }
        write_file(size, time_min, path);
        std::cout << "Size " << size << " tested" << '\n';
    }
}

void make_test(int* generate_array(const size_t), int* sort(int*, const int, const int), const size_t size_start, const size_t size_finish, const double size_multiplier_step,
               const std::string path)
{
    const int sort_amount = 1;
    const int checks_amount = 10;
    const int short_array_sort_max_amount = 1000000;
    for (size_t size = size_start; size <= size_finish; size = size * size_multiplier_step){
        int time_min = -1;
        for (int i = 0; i < checks_amount; i ++){
            int* array = generate_array(size);
            const int time = get_time(sort, array, sort_amount, 0, size - 1);
            delete[] array;
            if (time > 0){
                if (time < time_min || time_min == -1){
                    time_min = time;
                }
            }
        }
        if (time_min == -1){
            for (int i = 0; i < checks_amount; i ++){
                int* array = generate_array(size);
                int short_array_sort_amount = short_array_sort_max_amount / size;
                const int time = get_time(sort, array, short_array_sort_amount, 0, size - 1);
                delete[] array;
                if (time > 0){
                    if (time < time_min || time_min == -1){
                        time_min = time;
                    }
                }
            }
        }
        write_file(size, time_min, path);
        std::cout << "Size " << size << " tested" << '\n';
    }
}

void print_array(const int* array, const size_t size)
{
    for (int i = 0; i < size; i ++){
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    /*const size_t size_min = 1, size_max = 20000;
    const double size_multiplier_step = 2;*/
    const size_t size = 1000;
    const int repeat = 10000;
    int* array = create_random_array(size);
    const int time = get_time(make_bubble_sort, array, repeat, size);
    std::cout << "Time: " << time << '\n';
    delete[] array;
    /*clear_file("result_bubble.txt");
    std::cout << "---Bubble sort start---" << '\n';
    make_test(create_sorted_array, make_bubble_sort, size_min, size_max, size_multiplier_step, "result_bubble.txt");
    std::cout << "---Bubble sort finish---" << '\n';
    clear_file("result_selection.txt");
    std::cout << "---Selection sort start---" << '\n';
    make_test(create_sorted_array, make_selection_sort, size_min, size_max, size_multiplier_step, "result_selection.txt");
    std::cout << "---Selection sort finish---" << '\n';
    clear_file("result_insertion.txt");
    std::cout << "---Insertion sort start---" << '\n';
    make_test(create_sorted_array, make_insertion_sort, size_min, size_max, size_multiplier_step, "result_insertion.txt");
    std::cout << "---Insertion sort finish---" << '\n';
    clear_file("result_quicksort.txt");
    std::cout << "---Quick sort start---" << '\n';
    make_test(create_sorted_array, make_quicksort, size_min, size_max, size_multiplier_step, "result_quicksort.txt");
    std::cout << "---Quick sort finish---" << '\n';*/
    return 0;
}
