#include <iostream>
#include <vector>

// Функция для вывода матрицы
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для нахождения определителя матрицы
double determinant(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size(); // Размер матрицы
    double det = 1.0; // Изначально определитель равен 1

    // Создаем копию матрицы, чтобы не изменять оригинал
    std::vector<std::vector<double>> triangularMatrix(matrix);

    for (int i = 0; i < n; ++i) {
        // Если элемент на главной диагонали равен нулю, меняем строки
        if (triangularMatrix[i][i] == 0) {
            int swapRow = -1;
            for (int j = i + 1; j < n; ++j) {
                if (triangularMatrix[j][i] != 0) {
                    swapRow = j;
                    break;
                }
            }
            if (swapRow == -1)
                return 0; // Определитель равен нулю, если нет ненулевых элементов на главной диагонали
            std::swap(triangularMatrix[i], triangularMatrix[swapRow]);
            det *= -1; // Меняем знак определителя при перестановке строк
        }

        // Приводим матрицу к верхнетреугольному виду
        for (int j = i + 1; j < n; ++j) {
            double factor = triangularMatrix[j][i] / triangularMatrix[i][i];
            for (int k = i; k < n; ++k) {
                triangularMatrix[j][k] -= factor * triangularMatrix[i][k];
            }
        }
    }

    // Умножаем элементы главной диагонали
    for (int i = 0; i < n; ++i) {
        det *= triangularMatrix[i][i];
    }

    return det;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Пример использования
    std::vector<std::vector<double>> matrix = {{1, 4, 0, 1},
                                               {1, 4, 3, 0},
                                               {0, 2, 0, 9},
                                               {1, 0, 1, 2}};

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix);

    double det = determinant(matrix);

    std::cout << "Определитель матрицы: " << det << std::endl;

    return 0;
}
