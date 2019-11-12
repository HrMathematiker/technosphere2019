#include <iostream>
#include <vector>

static int upper_bound = 20000000;

std::vector<bool> sieve_of_Eratosthenes() { //возвращает массив простых чисел (true = простое)
    std::vector<bool> prime(upper_bound, true); 
    for (int p = 2; p * p <= upper_bound; p++) { 
        if (prime[p] == true) { 
            for (int i = p * p; i <= upper_bound; i += p) 
                prime[i] = false; 
        } 
    }
    return prime;
} 

int m_primes (int M, int N) {
    int sum, counter = 0;
    std::vector<bool> prime = sieve_of_Eratosthenes();
    for (int i = 2; i < 2 + N; i++) {
        if (prime[i])
            counter++;
    }
    if (counter == M) {
        return 2;
    }
    for (int i = 3; i <= upper_bound; i++) {
        if (prime[i - 1])
                counter--;
        if (prime[i + N - 1])
                counter++;
        if (counter == M) 
            return i;
    }
    return -1;
}


int main() {
    int N, M;
    std::cin >> M >> N;
    std::cout << m_primes(M, N) << '\n';
    return 0;
}