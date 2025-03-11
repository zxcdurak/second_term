#include <iostream>

void Fibonachi(long max, int &n, int &s) {
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

void values_function_print(float start) {
    float delta = (4 - start) / 9;
    float x = start;
    while (x <= 4 + delta) {
        std::cout << "x:" << x << "    f(x):" << f(x) << "\n";
        x += delta;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    float start;
    std::cin >> start;
    values_function_print(start);
   /* int s, n, max;
    std::cout << "введите max\n";
    std::cin >> max;
    Fibonachi(max, n, s);
    std::cout << "n:" << n << " s:" << s;*/
    return 0;
}


