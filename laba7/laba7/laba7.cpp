#include <iostream>
#include <string>
#include <cmath>

int n, m;
const float eps = 1e-6;

using namespace std;

class Matrix {
public:
    float** data;
    int m, n, r;
    int* L;

    Matrix(float** A,int m, int n): data(A), m(m), n(n) {
        L = new int[n];
        for (int i = 0; i < n; i++) {
            L[i] = i;
        }
        r = min(m, n);
    }

    ~Matrix() {
        delete[] L;
    }

    int to_triange_view_column() {
        for (int i = 0; i < r; i++) {
            int v = i;
            int u = i;

            for (int k = i; k < m; k++) {
                for (int l = i; l < n; l++) {
                    if (abs(data[k][l]) > abs(data[v][u])) {
                        v = k;
                        u = l;
                    }
                }
            }

            //ведущий элемент слишком мал -> система вырождена ;(
            if (abs(data[v][u]) < eps) {
                r = i;
                break;
            }

            // типо перестановка строк
            if (v != i) {
                swap(data[i], data[v]);
            }

            // а тут в общем перестановка столбцов
            if (u != i) {
                for (int k = 0; k < m; k++) {
                    swap(data[k][i], data[k][u]);
                }
                swap(L[i], L[u]); // крч запоминаем где какие переменные
            }

            // Нормализация i-й строки
            float c = data[i][i];
            for (int j = i; j <= n; j++) {
                data[i][j] /= c;
            }

            // Вычитание уравнений из нижележащих строк
            for (int k = 0; k < m; k++) {
                if (k != i) {
                    float factor = data[k][i];
                    for (int j = i; j <= n; j++) {
                        data[k][j] -= factor * data[i][j];
                    }
                }
            }
        }

        // Проверяем совместность системы
        for (int i = r; i < m; i++) {
            if (abs(data[i][n]) > eps) {
                return 1; // Опа, система несовместна
            }
        }
        return 0;
    }

    float* general_solution() {
        if (to_triange_view_column()) {
            return NULL; // Система несовместна
        }
       
        float* X = new float[n]();

        //свободные переменные
        if (r < n) {
            for (int i = r; i < n; i++) {
                X[L[i]] = 2.0f; // Свободные переменные
                printf("x%d are free\n", L[i]+1);
            }
        }

        //считываем базисные через свободные
        for (int i = r - 1; i >= 0; i--) {
            X[L[i]] = data[i][n]; //используем свободные члены
            for (int j = i + 1; j < n; j++) {
                X[L[i]] -= data[i][j] * X[L[j]];
            }
        }

        return X;
    }

    float* only_decision_or_null() {
        if (to_triange_view_column()) {
            return NULL; // Не совместна или вырождена
        }

        if (r != n) {
            return NULL; // Нет единственного решения
        }

        float* X = new float[n];
        for (int i = 0; i < n; i++) {
            X[L[i]] = data[i][n]; // L[i] — исходный индекс переменной
        }

        // Обратная подстановка (если матрица не диагональна)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                X[L[i]] -= data[i][j] * X[L[j]];
            }
        }

        return X;
    }
};


int main()
{

    float** D; 
    scanf_s("%d %d", &m, &n); 
    D = new float* [m];

    for (int i = 0; i < m; i++) {
        D[i] = new float[n + 1]; 
        for (int j = 0; j <= n; j++) {
            scanf_s("%f", &D[i][j]);
        }
    }

    Matrix matrix(D, m, n); 
    float* X = matrix.general_solution();

    if (X == NULL) {
        printf("INCONSISTENT SYSTEMS");
    }
    else {
        printf("\n");
        for (int i = 0; i < n; i++) {
            printf("x%d %8.3f\n", i + 1, X[i]);
        }
    }

    for (int i = 0; i < m; i++) delete[] D[i];
    delete[] D;
    if (X != NULL) delete[] X; 
}
    