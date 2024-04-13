#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Estructura para representar un par (�ndice, n�mero)
struct IndexNumberPair {
    int index;
    int number;

    IndexNumberPair(int i, int n) : index(i), number(n) {}
};

// Clase functor para comparar pares (�ndice, n�mero)
class CompareIndexNumberPairs {
public:
    bool operator()(const IndexNumberPair& a, const IndexNumberPair& b) const {
        return a.number < b.number;
    }
};

// Algoritmo de Ford-Johnson para ordenar n�meros positivos
void fordJohnson(std::vector<int>& numbers) {
    std::vector<IndexNumberPair> pairs;

    // Paso 1: Crear pares (�ndice, n�mero) y separarlos en listas L y S
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] <= 0) continue;
        pairs.push_back(IndexNumberPair(i, numbers[i]));
    }

    // Paso 2: Ordenar los pares seg�n el n�mero
    std::sort(pairs.begin(), pairs.end(), CompareIndexNumberPairs());

    // Paso 3: Reconstruir la secuencia ordenada
    for (size_t i = 0; i < pairs.size(); ++i) {
        numbers[i] = pairs[i].number;
    }
}

// Funci�n para imprimir el contenido de un contenedor
void printContainer(const std::vector<int>& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <num1> <num2> ..." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        numbers.push_back(std::atoi(argv[i]));
    }

    std::cout << "Secuencia original: ";
    printContainer(numbers);

    std::clock_t start = std::clock();

    // Ordenar utilizando Ford-Johnson
    fordJohnson(numbers);

    std::clock_t end = std::clock();
    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Secuencia ordenada: ";
    printContainer(numbers);
    std::cout << "Tiempo de ejecuci�n: " << elapsed_time << " segundos" << std::endl;

    return 0;
}
