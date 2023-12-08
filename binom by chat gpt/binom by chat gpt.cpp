#include <iostream>

// Функция для вычисления биномиального коэффициента C(n, k)
unsigned long long binomialCoefficient(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    unsigned long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }

    return result;
}

int main() {
    int a, b, n;

    // Ввод значений a, b и n через пробел
    std::cout << "Enter values for a, b, and n (separated by space): ";
    std::cin >> a >> b >> n;

    // Вывод разложения бинома Ньютона
    std::cout << "Expansion of (" << a << "x + " << b << "y)^" << n << ": ";

    for (int k = 0; k <= n; ++k) {
        unsigned long long coefficient = binomialCoefficient(n, k);
        if (coefficient != 1) {
            std::cout << coefficient;
        }

        if (k > 0) {
            if (a != 0) {
                std::cout << "x";
                if (k > 1) {
                    std::cout << "^" << k;
                }
            }
            if (b != 0) {
                if (a != 0) {
                    std::cout << " + ";
                }
                std::cout << coefficient;
                if (k > 0) {
                    std::cout << "y";
                    if (n - k > 1) {
                        std::cout << "^" << (n - k);
                    }
                }
            }
        }
        else {
            std::cout << "1";
        }

        if (k < n) {
            if (a != 0 || b != 0) {
                std::cout << " + ";
            }
        }
    }

    std::cout << std::endl;

    return 0;
}
