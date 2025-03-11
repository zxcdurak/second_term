#include <iostream>

short n = 0;
long total_count = 0;
bool Columns[20] = {};
bool Ldiag[39] = {};
bool Rdiag[39] = {};
short Lines[20] = {};

void print_permutations(short* arr) {
    char temp[21];
    for (int i = 0; i < 20; ++i) {
        temp[i] = '#';
    }
    temp[n] = '\0';

    for (short s = 0; s < n; s++) {
        temp[arr[s]] = 'O';
        std::cout << temp << "\n";
        temp[arr[s]] = '#';
    }
    
}

void Queen(int j) {
    for (int i =0; i < n; i++) {
        if ((Columns[i] == 0) and (Rdiag[j - i + n - 1] == 0) and (Ldiag[j + i] == 0)) {
            Columns[i] = 1;
            Rdiag[j - i + n - 1] = 1;
            Ldiag[j + i] = 1;
            Lines[j] = i;

            if (j == n - 1) {
                total_count++;
               /* print_permutations(Lines);
                std::cout << "\n";*/
            }
            else {
                Queen(j + 1);
            }
            Columns[i] = 0;
            Rdiag[j - i + n - 1] = 0;
            Ldiag[i + j] = 0;
        }
    }
}

int main()
{
    std::cin >> n;
    Queen(0);
    std::cout << "\n" << "total_Count: " << total_count << "\n";
}
