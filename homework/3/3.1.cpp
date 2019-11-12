#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::map<char, int> letter_counter;
    std::vector<std::pair<int, char>> vector_letters;
    char input;
    while (scanf("%c", &input) == 1) {
        std::pair< std::map<char, int>::iterator, bool> ret;
        ret = letter_counter.insert(std::pair<char, int> (input, 1));
        if (!ret.second)
            ret.first -> second++;
    }
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        if (letter_counter[letter] != 0)
            vector_letters.push_back(std::make_pair(letter_counter[letter], letter));
    }
    std::sort(vector_letters.rbegin(), vector_letters.rend());
    for (int i = 0; i < vector_letters.size() - 1; i++) {
        for (int j = 0; j < vector_letters.size() - i - 1; j++) 
            if ((vector_letters[j].first == vector_letters[j+1].first) && (vector_letters[j].second > vector_letters[j+1].second))
                std::swap(vector_letters[j], vector_letters[j+1]);
    }
    for (int i = 0; i < vector_letters.size(); i++) {
        std::cout << vector_letters[i].second << ' ' << vector_letters[i].first << '\n';
    }
    return 0;
}