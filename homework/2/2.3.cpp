#include <iostream>
#include <vector>
#include <algorithm>

int segments(std::vector<float> numbers) {
    int number_of_segments = 0, i = 0, counter;
    while (i < numbers.size()) {
        int j = i;
        counter = 0;
        while ((numbers[j] <= numbers[i] + 1) && (j < numbers.size())) {
            j++;
            counter++;
        }
        i += counter;
        number_of_segments++;
    }
    return number_of_segments;
} 

int main() {
    int N;
    float input;
    std::vector<float> numbers;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        numbers.push_back(input);
    }
    std::sort(numbers.begin(), numbers.end());
    std::cout << segments(numbers) << '\n';
    return 0;
}