#include <iostream>

void matrix_mult(uint64_t* mat_1, uint64_t* mat_2, int m) {
    
    uint64_t a11, a12, a22, a21;

    a11 = mat_1[0] * mat_2[0] + mat_1[1] * mat_2[2];
    a12 = mat_1[0] * mat_2[1] + mat_1[1] * mat_2[3];
    a21 = mat_1[2] * mat_2[0] + mat_1[3] * mat_2[2];
    a22 = mat_1[2] * mat_2[1] + mat_1[3] * mat_2[3];
    mat_1[0] = a11 % m;
    mat_1[1] = a12 % m;
    mat_1[2] = a21 % m;
    mat_1[3] = a22 % m;
}

int fib(uint64_t n, int m) {
   
    uint64_t mat_1[] = { 1, 1, 1, 0 };
    uint64_t mat_2[] = { 1, 0, 0, 1 };
    int i = sizeof(int) * 8 - 1;
   
    while ((n >> i) == 0) 
        i--;
    while (i > 0) {
        if (((n >> i) & 1) == 1) {
            matrix_mult(mat_2, mat_1, m);
            matrix_mult(mat_2, mat_2, m);
        }
        else
            matrix_mult(mat_2, mat_2, m);
        i -= 1;
    }
    if (n % 2 == 1)
        matrix_mult(mat_2, mat_1, m);
    if (mat_2[1] < 0) 
        mat_2[1] += m;
    return mat_2[1];
    }


int main() {
    uint64_t n;
    int m;

    std::cin >> n >> m;
    std::cout << fib(n, m) << '\n';

    return 0;
}