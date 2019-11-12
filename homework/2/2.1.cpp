#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, r, len, min, sum = 0, input, help;
    std::cin >> n >> r;
    std::vector<int> points(n);
    std::vector<int> count(n);
    min = r * n;

    for(int i = 0; i < n; i++) { 
        std::cin >> input;
        points.push_back(input);
    }

    std::sort(points.begin(), points.end());
    count.push_back(1);
    help = points.front();
    for(int i = 1; i < n; i++) { 
        count.push_back(0);
        if(points[i] != help) { 
            sum += points[i]; 
            help = points[i]; 
            count[i] = 1; 
        }
        else 
            points[i] = 0;
    }
    for(int i = n - 1; i > 0; i--) {
        if(points[i] == 0) { 
            count[i-1] += count[i]; 
            count[i-1]++; 
            count[i] = 0; 
        }
    }
    help = points.front();
    for(int i = 0; i < n; i++) {
        if(i > 0 && points[i] == 0) 
            continue;
        len = n * points[i] - sum + r * (n - (i + 1)) - r * (count[i] - 1);
        if(len < min) {
            min = len;
            help = points[i];
        }
    }
    std::cout << help << '\n';
    return 0;
}