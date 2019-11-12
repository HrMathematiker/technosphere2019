#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string input;
    std::vector<std::string> stack;
    std::string temp;
    std::cin >> input;
    int level = 0;
    for (char &symbol: input) {
        switch (symbol) {
            case '(':
                stack.push_back(temp);
                level++;
                break;
            case ')':
                level--;
                break;
            case 'R':
                std::reverse(stack.back().begin(), stack.back().end());
                break;
            case ',':
                if (level > 0) {
                    stack[level - 1] += stack[level];
                    stack.pop_back();
                }
                break;
            default:
                stack.back() += symbol;
                break;
        }
        if ((level == 0) && (symbol == ')')) {
            stack[0] += stack[1];
            stack.pop_back();
        }
    }
    std::cout << stack.front() << std::endl;
    return 0;
}