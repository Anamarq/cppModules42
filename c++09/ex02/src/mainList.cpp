#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>

// Estructura para representar un par (índice, número)
struct IndexNumberPair {
    int index;
    int number;

    IndexNumberPair(int i, int n) : index(i), number(n) {}
};

// Clase functor para comparar pares (índice, número)
class CompareIndexNumberPairs {
public:
    bool operator()(const IndexNumberPair& a, const IndexNumberPair& b) const {
        return a.number < b.number;
    }
};

// Algoritmo de Ford-Johnson para ordenar números positivos
void fordJohnson(std::list<int>& numbers) {
    std::list<IndexNumberPair> pairs;

    // Paso 1: Crear pares (índice, número) y separarlos en listas L y S
    int index = 0;
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it, ++index) {
        if (*it <= 0) continue;
        pairs.push_back(IndexNumberPair(index, *it));
    }

    // Paso 2: Ordenar los pares según el número
    pairs.sort(CompareIndexNumberPairs());

    // Paso 3: Reconstruir la secuencia ordenada
    std::list<int>::iterator it = numbers.begin();
    for (std::list<IndexNumberPair>::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it, ++it) {
        *it = pair_it->number;
    }
}

// Función para imprimir el contenido de un contenedor
void printContainer(const std::list<int>& container) {
    for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <num1> <num2> ..." << std::endl;
        return 1;
    }

    std::list<int> numbers;
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
    std::cout << "Tiempo de ejecución: " << elapsed_time << " segundos" << std::endl;

    return 0;
}
