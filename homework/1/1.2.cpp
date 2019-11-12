#include <string>
#include <iostream>

int num_compare(std::string num_1, std::string num_2) {
    
    int size_1, size_2;
    
    size_1 = num_1.size();
    size_2 = num_2.size();

    if (size_1 > size_2) {
        return 1;
    }
    else if (size_1 < size_2) {
        return 2;
    }
    else {
        for (int i = 0; i < size_1; i++) {
            if (num_1[i] > num_2[i]) {
                return 1;
            }
            else if (num_1[i] < num_2[i]) {
                return 2;
            }
        }
    }
    return 0;
}

void num_sum(std::string& num_1, std::string& num_2, char sign_1) {
    
    int i, int_1, int_2, size_1, size_2, add = 0;
    
    size_1 = num_1.size();
    size_2 = num_2.size();
    i = 1;
    for (; i <= size_2; i++) {
        int_1 = num_1[size_1 - i] - '0';
        int_2 = num_2[size_2 - i] - '0';
        num_1[size_1 - i] = (int_1 + int_2 + add) % 10 + '0';
        add = (int_1 + int_2 + add) / 10;
    }
    for (; i <= size_1; i++) {
        int_1 = num_1[size_1 - i] - '0';
        num_1[size_1 - i] = (int_1 + add) % 10 + '0';
        add = (int_1 + add) / 10;
    }
    if (sign_1 == '-') {
        std::cout << sign_1;
    }
    if (add > 0) {
        std::cout << char(add + '0');
    }
    
    std::cout << num_1;
}

std::string num_diff(std::string& num_1, std::string& num_2) {
    
    int size_1, size_2, j = 1;
    
    size_1 = num_1.size();
    size_2 = num_2.size();
    
    for (int i = 1; i <= size_2; i++) {
        if (num_1[size_1 - i] >= num_2[size_2 - i]) {
            num_1[size_1 - i] -= num_2[size_2 - i] % 48;
        }
        else {
            while (num_1[size_1 - i - j] == 48) {
                num_1[size_1 - i - j] += 9;
                j++;
            }
            num_1[size_1 - i - j] -= 1;
            num_1[size_1 - i] += (10 - num_2[size_2 - i] % 48);
            j = 1;
        }
    }
    return num_1;
}

int main() {
    int size_1, size_2, comp, j = 0;
    char sign_1, sign_2, operation;
    std::string num_1, num_2, res, num_2_mod, num_1_mod;
    
    std::cin >> num_1;
    std::cin >> operation;
    std::cin >> num_2; 
    
    if(num_1[0] == '-') { sign_1 = '-'; num_1_mod = num_1.substr(1); } 
    if(num_1[0] != '-') { sign_1 = '+'; num_1_mod = num_1; }
    if(num_2[0] == '-') { sign_2 = '-'; num_2_mod = num_2.substr(1); } 
    if(num_2[0] != '-') { sign_2 = '+'; num_2_mod = num_2; }

    if(sign_1 == '-' && sign_2 == '+' && operation == '+') { operation = '-'; sign_2 = '-'; }
    if(sign_1 == '-' && sign_2 == '+' && operation == '-') { operation = '+'; sign_2 = '-'; }
    if(sign_1 == '+' && sign_2 == '-' && operation == '+') { operation = '-'; sign_2 = '+'; }
    if(sign_1 == '+' && sign_2 == '-' && operation == '-') { operation = '+'; sign_2 = '+'; }

    size_1 = num_1_mod.size();
    size_2 = num_2_mod.size();

    comp = num_compare(num_1_mod, num_2_mod);

    switch (comp) {
        case 0:
            if (operation == '+') {
                num_sum (num_1_mod, num_2_mod, sign_1);
            }
            else {
                std::cout << 0;
            }
            break;
        case 1:
            if(operation == '+') { 
                num_sum(num_1_mod, num_2_mod, sign_1); 
            }
            else {
            res = num_diff(num_1_mod, num_2_mod);
            for(int i = 0; i < sign_1; i++) { 
                if(res[i] != '0') 
                    break;
                j++; 
                }
            if (sign_1 == '-') 
                 std::cout << '-';
            for(int i = j; i < size_1; i++) 
                 std::cout << res[i];
            }
            break;
        case 2:
            if(operation == '+') { 
                num_sum(num_2_mod, num_1_mod, sign_1); 
            }
            else {
                res = num_diff(num_2_mod, num_1_mod);
                for(int i = 0; i < size_2; i++) { 
                    if(res[i] != '0') 
                        break; 
                    j++; 
                }
                if (sign_1 == '-') { 
                    for(int i = j; i < size_2; i++) 
                        std::cout << res[i];
                }
                else { 
                    std::cout << '-';
                    for(int i = j; i < size_2; i++) 
                        std::cout << res[i];
                }
            } 
            break; 
    }
    return 0;
}