#include <iostream>

int main(){
    int N, coins, temp, req_coins; 
    coins = 0; 
    req_coins = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> temp;
        temp -= 5; 
        if (temp % 10 == 0){
            coins++;
        }
        else{
            if ((temp / 5) - coins < 0){
                coins -= temp / 5;
            }
            else{
                req_coins += (temp / 5) - coins;
                coins = 0;
            }
        }
    }
    std::cout << req_coins;
    return 0;
}