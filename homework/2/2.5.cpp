#include <iostream>
#include <string>
#include <map>

std::string fraction_to_decimal(int N, int M) { 
    std::string result, period; 
    std::map <int, int> mp; 
    int remainder = N % M; 
    mp.clear(); 
    while ((remainder != 0) && (mp.find(remainder) == mp.end())) { 
        mp[remainder] = result.length(); 
        remainder *= 10; 
        int res_part = remainder / M; 
        result += std::to_string(res_part); 
        remainder %= M; 
    } 
    period = result.substr(mp[remainder]); 
    result.replace(result.find(period), period.length(), "(" + period + ")");
    return (remainder == 0)? "" : "0." + result; 
} 

int main() {
    double N, M;
    std::cin >> N >> M;
    std::string result = fraction_to_decimal((int) N, (int) M);
    if (result == "") 
        std::cout << N / M << '\n';
    else 
        std::cout << result << '\n';
    return 0;
}