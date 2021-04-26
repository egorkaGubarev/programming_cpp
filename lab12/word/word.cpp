#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool is_prefix(std::string word_small, std::string word_big)
{
    bool is_right = false;
    int k = word_small.length();
    int l = word_big.length();
    if (k < l){
        is_right = true;
        for (size_t letter_number = 0; letter_number < k; letter_number ++){
            if (word_small[letter_number] != word_big[letter_number]){
                is_right = false;
            }
        }
    }
    return is_right;
}

int main()
{
    size_t m;
    std::ifstream test;
    test.open("test_case500.txt");
    test >> m;
    std::vector<std::string> words(m + 1);
    for (size_t word_number = 1; word_number <= m; word_number ++){
        test >> words[word_number];
    }
    test.close();
    std::vector<int> length(m + 1);
    length[1] = 1;
    int max_global = 0;
    for (size_t word_number = 2; word_number <= m; word_number ++){
        int max = 0;
        for (size_t smaller_number = 1; smaller_number < word_number; smaller_number ++){
            if (is_prefix(words[smaller_number], words[word_number])){
                if (length[smaller_number] > max){
                    max = length[smaller_number];
                }
            }
        }
        int new_length = max + 1;
        length[word_number] = new_length;
        if (new_length > max_global){
            max_global = new_length;
        }
    }
    std::cout << max_global << '\n';
    /* std::string word1;
    std::cin >> word1;
    std::string word2;
    std::cin >> word2;
    if (is_prefix(word1, word2)){
        std::cout << "---is prefix---" << '\n';
    }
    std::cout << word1.length() << '\n';
    std::cout << word2.length() << '\n'; */
    return 0;
}
