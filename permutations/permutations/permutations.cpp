
#include <iostream>

int P[3];
bool R[3]; 
int n;

void per(int k) {
    for (int i = 0; i < n; i++) {
        if (R[i] == 0) {
            P[k] = i + 1;
            R[i] = 1;
            if (k == n - 1) {
                for (int s = 0; s < n; s++) std::cout << P[s] << " ";
                std::cout << "\n";
            }
            else {
                per(k + 1);
            }
            R[i] = 0;
        }
    }
}


int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++) R[i] = 0;
    per(0);
}

