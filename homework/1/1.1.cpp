#include <iostream>
#include <string>
#include <cmath>

char letter(int64_t n, int64_t k) { //возвращает k-ый символ n-той строки 
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    if (k == 1) {
        return alphabet.substr(n - 1, 1)[0];
    }
    else {
        if (k <= pow(2, n - 1))
            return letter (n - 1, k - 1);
        else
            return letter (n - 1, k - pow(2, n - 1));
    }
}

int main() {
    int64_t n, k, l;
    std::cin >> n >> k >> l;
    std::string substr;
    for (int64_t i = k; i <= l; i++) {
        substr.push_back(letter(n, i));
    }
    std::cout << substr;
    return 0;
}