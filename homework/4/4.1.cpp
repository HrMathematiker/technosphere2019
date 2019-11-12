#include <iostream>
#include <vector>
#include <numeric>

bool check(int mid, std::vector<int> array, int K) { 
    int count = 0; 
    int sum = 0; 
    for (int i = 0; i < array.size(); i++) { 
        if (array[i] > mid) 
            return false;
        sum += array[i];  
        if (sum > mid) { 
            count++; 
            sum = array[i]; 
        } 
    } 
    count++;  
    if (count <= K) 
        return true; 
    return false; 
} 
  

int solve(std::vector<int> array, int K) 
{ 
    int start = 1; 
    int end = std::accumulate(array.begin(), array.end(), 0);
    int answer = 0; 
    while (start <= end) { 
        int mid = (start + end) / 2; 
        if (check(mid, array, K)) { 
            answer = mid; 
            end = mid - 1; 
        } 
        else 
            start = mid + 1;  
    } 
    return answer; 
} 


int main() {
    int N, K, input, temp, res; //K - max num of volumes, N - num chapters
    std::vector<int> pages_in_chapter;
    std::cin >> K >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        pages_in_chapter.push_back(input);
    }
    std::cout << solve(pages_in_chapter, K) << std::endl;
    return 0;
}