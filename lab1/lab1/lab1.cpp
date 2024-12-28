#include <iostream>

void Fibonachi(long max, int &n, int&s) {
    int first = 1; 
    int second = 1; 
    int temp;
    s = 0;
    n = 0;

    while (s + first <= max) {
        s += first;
        n++; 
        temp = first + second;
        first = second;
        second = temp;
    } 
}

float f(float x) {
    return sin(x) / x;   
}

void values_function_print(int func) {
    float x_values[10];
    float delta = 4 / 9;

    while 
}

int main()
{
    setlocale(LC_ALL, "ru");
    int s, n, max;
    std::cout << "введите max\n";
    std::cin >> max;
    Fibonachi(max, n, s);
    std::cout << "n:" << n << " s:" << s;
}



