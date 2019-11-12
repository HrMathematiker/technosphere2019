#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


int main () {
    int N1, N2, temp; 
    std::cin >> N1;
    std::cin >> N2;
    std::vector<int> arr1(N1);
    std::vector<int> arr2(N2);
    for (int i = 0; i < N1; i++){
        
    }   
    for (int i = 0; i < N2; i++){
        std::cin >> arr2[i];
    }
    std::vector<int> cv;
    std::set_difference(std::begin(arr1), std::end(arr1), 
                        std::begin(arr2), std::end(arr2), 
                        std::back_inserter(cv));
    return cv.size();
 }