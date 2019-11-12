#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    int level = 0, where_is_black = -1, counter = 0;
    for (char &symbol: input) {
        switch (symbol) {
            case '(':
                level++;
                break;
            case 'b':
                if (where_is_black == -1)
                    where_is_black = level;
                break;
            case ',':
                continue;
            case 'g':
                continue;
            case 'w':
                if ((where_is_black < level) && (where_is_black != -1))
                    counter++;
                break;
            case ')':
                if (level == where_is_black)
                    where_is_black = -1;
                level--;
                break;
        }
    }
    std::cout << counter << std::endl;
    return 0;
}