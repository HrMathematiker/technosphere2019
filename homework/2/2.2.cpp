#include <iostream>
#include <vector>

int main() {
    int input, counter = 0, max_num = 0, max = 0;
    std::vector <int> input_vector;
    while(true) {
        std::cin >> input;
        input_vector.push_back(input);
        if (input_vector.size() <= 8)
            continue;
        if (input > 0) {
            if (input_vector.front() > max_num)
                max_num = input_vector.front();
            input_vector.erase(input_vector.begin());
            if (max_num * input_vector.back() > max)
                max = max_num * input_vector.back();
        }
        else
            break;
    }
    std::cout << max << '\n';
    return 0;
}