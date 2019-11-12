#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int N, status = 0, max_status = 0, time_in_sec;
    std::string input;
    std::vector< std::pair<int, int> > time;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        time_in_sec = std::stoi(input.substr(0,2)) * 3600 + std::stoi(input.substr(3,2)) * 60 + std::stoi(input.substr(6,2));
        time.push_back(std::pair<int, int>(time_in_sec, 0));
        std::cin >> input;
        time_in_sec = std::stoi(input.substr(0,2)) * 3600 + std::stoi(input.substr(3,2)) * 60 + std::stoi(input.substr(6,2));
        time.push_back(std::pair<int, int>(time_in_sec, 1));
    }
    std::sort(time.begin(), time.end());
    for (int i = 0; i < 2 * N - 1; i++) {
        if ((time[i].first == time[i + 1].first) && (time[i].second == 1) && (time[i + 1].second == 0))
            std::swap(time[i], time[i+1]);
    }
    for (int i = 0; i < 2 * N; i++) {
        if (time[i].second == 0)
            status++;
        else 
            status--;
        if (status > max_status)
            max_status = status;
    }
    std::cout << max_status << '\n';
    return 0;
}