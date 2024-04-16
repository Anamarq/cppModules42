/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int strToInt(const std::string& str)
{
    std::stringstream intStream(str);
    int value;
    intStream >> value;
    try {
        if (!intStream)
            throw std::invalid_argument("invalid value in datavase date: " + str);
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return value;
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(char* numbers[], int argc)
{
    numElms = argc;
    for (int i = 1; i < argc; ++i)
    {
        numVec.push_back(strToInt(numbers[i]));
        numDeque.push_back(strToInt(numbers[i]));
    }
}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other) : numVec(other.numVec), numDeque(other.numDeque),
    timeVec(other.timeVec), timeDq(other.timeDq), numElms(other.numElms) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this == &other)
        return *this;
    numVec = other.numVec;
    numDeque = other.numDeque;
    timeVec = other.timeVec;
    timeDq = other.timeDq;
    numElms = other.numElms;
    return *this;
}

// Función recursiva para ordenar los elementos más grandes
void mergeSortVector(std::vector<int>& arr, int start, int end)
{
    //Si start es menor que end, significa que hay al menos dos elementos en el rango y es posible realizar la ordenación
    //sino termina
    if (start < end)
    {
        //Se llama recursivamente a la funcion mergeSort para ordenar cada mitad del rango por separado
        int mid = (start + end) / 2;
        mergeSortVector(arr, start, mid);
        mergeSortVector(arr, mid + 1, end);

        // Mezcla los dos subarreglos ordenados
        int i = start, j = mid + 1;
        std::vector<int> temp;
        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        //para los numeros que se queden sueltos
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= end)
        {
            temp.push_back(arr[j]);
            j++;
        }
        //se va copiando en el array, ordenado
        std::copy(temp.begin(), temp.end(), arr.begin() + start);
    }
}

// Función para realizar la ordenación merge-insertion
void fordJohnsonVector(std::vector<int>& arr)
{
    // Inicio del algoritmo
    int n = arr.size();
    if (n > 1)
    {
        // Realiza el ordenamiento inicial por pares
        //Comparar los elementos en posiciones pares con los elementos en posiciones impares
        //e intercambiarlos si es necesario para garantizar que cada par esté en orden ascendente.
        for (int i = 0; i < n - 1; i += 2)
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
        // Llama a la función mergeSort para ordenar los elementos más grandes
        mergeSortVector(arr, 0, n - 1);
    }
}

// Función recursiva para ordenar los elementos más grandes
void mergeSortDeque(std::deque<int>& arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSortDeque(arr, start, mid);
        mergeSortDeque(arr, mid + 1, end);

        std::deque<int> temp;
        int i = start, j = mid + 1;
        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= end)
        {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = 0; k < static_cast<int>(temp.size()); ++k)
        {
            arr[start + k] = temp[k];
        }
    }
}

// Función para realizar la ordenación merge-insertion
void fordJohnsonDeque(std::deque<int>& arr)
{
    int n = arr.size();
    if (n > 1)
    {
        for (int i = 0; i < n - 1; i += 2)
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
        mergeSortDeque(arr, 0, n - 1);
    }
}

//plantilla para iterar con cualquier contenedor
template<typename Container>
void printContainer(const Container& container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::execute()
{
    std::cout << "Before: ";
    printContainer(numDeque);

    std::clock_t start = std::clock();
    // Ordenar utilizando Ford-Johnson para el vector
    fordJohnsonVector(numVec);
    std::clock_t end = std::clock();
    timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // Ordenar utilizando Ford-Johnson para la deque
    start = std::clock();
    fordJohnsonDeque(numDeque);
    end = std::clock();
    timeDq = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    printContainer(numDeque);
    std::cout << "Time to process a range of " << numElms << " elements with std::vector : " << timeVec * 1000000 << " us" << std::endl;
    std::cout << "Time to process a range of " << numElms << " elements with std::deque : " << timeDq * 1000000 << " us" << std::endl;
}