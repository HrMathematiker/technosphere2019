#include <stdio.h>
#include <iostream>

int main() {
    char current_c, previous_c;
    int mode = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0; //mode 0 - not a comment, mode 1 - (*  *), mode 2 - { }, mode 3 - //, mode 4 - ' '
    bool previous_changed = true; 
    
    previous_c = '\0';

    while (scanf("%c", &current_c) == 1) {
        if ((previous_c == '(') && (current_c == '*') && (mode == 0)) {
            mode = 1; 
            previous_changed = true;
        }
        if ((previous_c == '*') && (current_c == ')') && (mode == 1) && (previous_changed == true)) {
            mode = 0;
            count_1++;
            previous_changed = false;
        }
        if ((current_c == '{') && (mode == 0)) {
            mode = 2; 
        }
        if ((current_c == '}') && (mode == 2)) {
            mode = 0;
            count_2++;  
        }
        if ((previous_c == '/') && (current_c == '/') && (mode == 0)) {
            mode = 3; 
        }
        if (current_c == '\'') {
            switch (mode) {
                case 0:
                    mode = 4;
                    count_4++;
                    break;
                case 4:
                    mode = 0; 
                    break;
            }
        }
        if (current_c == '\n') {
            if (mode == 4) {
                mode = 0;
            }
            if (mode == 3) {
                mode = 0;
                count_3++;
            }
        }
        previous_c = current_c; 
        
    }
    std::cout << count_1 << ' ' << count_2 << ' ' << count_3 << ' ' << count_4;
    return 0;
}