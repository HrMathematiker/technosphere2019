#include <iostream> 
#include <vector>
#include <algorithm>

int main() {
    int64_t N, M;
    std::vector<uint64_t> factorials;
    std::cin >> N >> M;
    M -= 1;
    std::vector<int> result(N);
    int temp = 0;
    factorials.push_back(1);
    while (++temp <= N)
        factorials.push_back(factorials.back() * temp);
    M = (M >= factorials.back()) ? (factorials.back() - 1) : M;
    for (int i = 0; i < N; ++i) {
        result[i] = M / factorials[N - 1 - i];
        M %= factorials[N - 1 - i];
    }

    for (int i = N - 1; i > 0; --i) {
        for (int j = i - 1; j >= 0; --j)
            if (result[j] <= result[i])
                result[i]++;
    }
    for (int i = 0; i < N; i++)
        std::cout << result[i] + 1 << ' ';
    return 0;
}