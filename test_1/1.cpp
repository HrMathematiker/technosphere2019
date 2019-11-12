#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int kolvo(std::vector<int> v, int l)
{
    int k = v.size();
    int n = v.size();
    int i = 0;
    while (i < n - 1) { 
        if(abs(v[i+1] - v[i]) <= l) { 
            k--; 
            i+=2;
        }
    }

    return k;
}

int main() {
    int l, n, k, input;
    std::vector<int> v;
    std::cin >> l >> n;

    for(int i = 0; i < n; i++) {
        std::cin >> input;
        v.push_back(input);
    }
    std::sort(v.begin(), v.end());
    k = kolvo(v, l);
    std::cout << k << '\n';
    return 0;
}