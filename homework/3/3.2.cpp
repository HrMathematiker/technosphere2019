#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static vector<int> permutation;

bool comparer(vector<string> str_1, vector<string> str_2) {   
    for (int i = 0; i < permutation.size(); i++) {
        if (stoi(str_1[permutation[i]]) > stoi(str_2[permutation[i]])) 
            return true;
        if (stoi(str_1[permutation[i]]) < stoi(str_2[permutation[i]]))
            return false;
        }
    return false;
}


int main() {
    vector<vector<string>> data;
    string input_str;
    int N, K, input;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> input;
        permutation.push_back(input);
    }
    for (int i = 0; i < N; i++) {
        cin >> input_str;
        data.push_back(vector<string>());
        data[i].push_back(input_str);
        for (int j = 0; j < K; j++) {
            cin >> input_str;
            data[i].push_back(input_str);
        }
    }
    sort(data.begin(), data.end(), comparer);
    for (int i = 0; i < N; i++) {
        cout << data[i][0] << '\n';
    }
    return 0;
}