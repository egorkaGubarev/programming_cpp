#include <iostream>
#include <vector>

std::vector<int> make_selection_sort(std::vector<int> array, const size_t size)
{
    for (int i = 1; i < size - 1; i ++){
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

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> coord(N + 1);
    for (int i = 1; i <= N; i ++){
        std::cin >> coord[i];
    }
    std::vector<int> length(N + 1);
    coord = make_selection_sort(coord, N + 1);
    length[2] = coord[2] - coord[1];
    length[3] = coord[3] - coord[1];
    for (int i = 4; i <= N; i ++){
        int latest_distance = coord[i] - coord[i - 1];
        length[i] = std::min(length[i - 2] + latest_distance, length[i - 1] + latest_distance);
    }
    std::cout << length[N];
    return 0;
}
