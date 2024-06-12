// Program Rekursif

#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1) {  // Basis kasus
        return 1;
    } else {
        return n * factorial(n - 1);  // Pemanggilan rekursif
    }
}

int main() {
    int number = 5;  // angka yang akan dicari faktorialnya
    std::cout << "Factorial of " << number << " is " << factorial(number) << std::endl;
    return 0;
}
