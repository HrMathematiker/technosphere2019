#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>

int main () {
	int64_t N, input, temp_1, temp_2;
	std::cin >> N;
	std::priority_queue<int64_t> capitals;
	for(int64_t i = 0; i < N; i++) {
		std::cin >> input;
		capitals.push(-input);
	}
	int64_t sum = 0;
	for(int64_t i = 0; i < N - 1; i++) {
		temp_1 = capitals.top();
		capitals.pop();
		temp_2 = capitals.top();
		capitals.pop();
		sum -= temp_1 + temp_2;
		temp_1 += temp_2;
		capitals.push(temp_1);
	}
	std::cout << std::fixed << std::setprecision(2) << double(sum) / 100 << std::endl;
    return 0;
}
