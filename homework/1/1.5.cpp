#include <iostream>
#include <vector>
#include <cmath>

int min_coins_func(std::vector<int> coins, int V) {
	int sum, j, k, min_coins = 2 * coins.size() + 1;
	uint64_t index = pow(3, coins.size());
	for (uint64_t i = 1; i <= index; i++) {			
		uint64_t copy_i = i;
		sum = 0;
		k = 0;
		j = 0;
		while (copy_i) {
			sum += (copy_i % 3) * coins[j];
			k += copy_i % 3;
			copy_i /= 3;
			j++;
		}		
			if ((sum == V) && (k < min_coins))	
				min_coins = k;
	}
	return min_coins;
}


int main() {
	int V, N, input, min_coins;
	uint64_t sum = 0;
	std::vector<int> coins;
	std::cin >> V >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> input;
		coins.push_back(input);
		sum += 2 * coins.back();
	}
	
	if (sum < V) {
		std::cout << "Impossible" << '\n';
	}
	else {
		min_coins = min_coins_func(coins, V);
		if (min_coins != (2 * N + 1))
			std::cout << min_coins << '\n';
		else
			std::cout << "Change" << '\n';
	}
	return 0;
}