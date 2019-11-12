#include <iostream>
#include <string>
#include <algorithm>

std::string my_next_permutation(std::string input) {
    if (input.length() <= 1)
        return input;
    int last_index = input.length() - 1;
    int index_1 = last_index, index_2;
    while (true) {
        index_2 = index_1;
        --index_1; 
        if (input[index_1] < input[index_2]) {
            int index_3 = last_index;
            while (!(input[index_1] < input[index_3]))
                index_3--;
            std::swap(input[index_1], input[index_3]);
            std::reverse(input.begin() + index_2, input.end());
            return input;
        }
        if (index_1 == 0) {
            std::reverse(input.begin(), input.end());
            return input;
        }
    }
}

int main() {
    std::string input_str;
    std::cin >> input_str;
    std::cout << my_next_permutation(input_str);
    return 0;
}