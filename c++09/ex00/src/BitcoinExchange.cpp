/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

//Lee datos del la database
void BitcoinExchange::readData(const std::string& namedata)
{
    std::ifstream datafile(namedata.c_str());
    if (!datafile.is_open()) {
        std::cerr << "Error: could not open file (data)." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    std::getline(datafile, line); //la primera linea no sirve
    while (std::getline(datafile, line))
    {
        //Buscar la fecha  el valor correspondiente, separados por ','
        int separator = line.find(',');
        std::string date = line.substr(0, separator);
        std::string value = line.substr(separator + 1, line.length());
        data[date] = value; //guardar en el map
       // std::cout << "date: " << date << " value: " << value << std::endl;
    }
    datafile.close();
}

//constructor por defecto
BitcoinExchange::BitcoinExchange() { readData("data.csv"); }
//constructor
BitcoinExchange::BitcoinExchange(const std::string& namedata) { readData(namedata); }
//constructor de copia
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}
//operador asignacion
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this == &other)
        return *this;
    data = other.data;
    return *this;
}
//destructor
BitcoinExchange::~BitcoinExchange() {}

// Función para eliminar caracteres no imprimibles de la cadena
void removeNonPrintableChars(std::string& str)
{
    std::string::iterator it = str.begin();
    while (it != str.end())
    {
        if (!isprint(*it))
            it = str.erase(it);
        else
            ++it;
    }
}

bool dateIsCorrect(const std::string& date)
{
    // Crear un objeto stringstream para facilitar el análisis de la cadena
    //inicializar stringstream con el date en el constructor
    std::stringstream ss(date);
    int anio, mes, dia;
    char dash1, dash2;

    // Intentar leer los componentes de la fecha desde la cadena
    if (!(ss >> anio >> dash1 >> mes >> dash2 >> dia) || dash1 != '-' || dash2 != '-') {
        // La lectura no fue exitosa o los separadores no son correctos
        return false;
    }
    // Verificar que los valores de año, mes y día estén dentro de los rangos válidos
    return (anio >= 0 && mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31);
}

void valueIsCorrect(const std::string& value)
{
    // Crear un stringstream para facilitar el análisis de la cadena
    std::stringstream ss(value);
    float floatValue;

    // Intentar convertir el valor a float
    ss >> floatValue;
    // Verificar si la conversión fue exitosa y si el valor es un número flotante positivo dentro del rango
    if (!ss)
        throw std::invalid_argument("invalid value: " + value);
    else if(ss && floatValue < 0)
        throw std::invalid_argument("not a positive number.");
    else if(ss && floatValue > 1000)
        throw std::invalid_argument("too large a number.");
}

float strToFloat(const std::string& str)
{
    std::stringstream floatStream(str);
    float value;
    floatStream >> value;
    try {
        if (!floatStream)
            throw std::invalid_argument("invalid value in datavase: " + str);
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return value;
}
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
std::string intToStr(int n)
{
    std::stringstream ss;
    ss << n;
    return ss.str();
}

std::string findPreviousDate(const std::string& date)
{
    // Obtener año, mes y día de la fecha proporcionada
    int year = strToInt(date.substr(0, 4).c_str());
    int month = strToInt(date.substr(5, 2).c_str());
    int day = strToInt(date.substr(8, 2).c_str());

    // Restar un día a la fecha
    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        // Obtener el número de días en el mes anterior
        int diasEnMesAnterior = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            diasEnMesAnterior = 30;
        }
        else if (month == 2) {
            // Verificar si el año es bisiesto
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                diasEnMesAnterior = 29; // Febrero en un año bisiesto
            }
            else {
                diasEnMesAnterior = 28; // Febrero en un año no bisiesto
            }
        }
        day = diasEnMesAnterior;
    }

    ////en cpp98 no hay to_string
    std::string yearStr = intToStr(year);
    std::string monthStr = intToStr(month);
    std::string dayStr = intToStr(day);
    if (month < 10)
        monthStr = "0" + monthStr;
    if (day < 10)
        dayStr = "0" + dayStr;
    return yearStr + "-" + monthStr + "-" + dayStr;
}

std::string cleanDate(const std::string& date)
{
    int year = strToInt(date.substr(0, 4).c_str());
    int month = strToInt(date.substr(5, 2).c_str());
    int day = strToInt(date.substr(8, 2).c_str());
    std::string yearStr = intToStr(year);
    std::string monthStr = intToStr(month);
    std::string dayStr = intToStr(day);
    if (month < 10)
        monthStr = "0" + monthStr;
    if (day < 10)
        dayStr = "0" + dayStr;
    return yearStr + "-" + monthStr + "-" + dayStr;
}

float BitcoinExchange::getBitcoinChange(std::string date)
{
    //Buscar el tipo de cambio de Bitcoin correspondiente a la fecha proporcionada 
        //en el archivo de datos. Si no se encuentra una coincidencia exacta, 
        //buscar la fecha más cercana anterior en el archivo de datos.
        //tipo de iterador para map en std c++98
    date = cleanDate(date);
    std::map<std::string, std::string>::iterator it = data.find(date);
    if (it != data.end())
        return strToFloat(it->second); // Se encontro una coincidencia exacta, devolver el valor correspondiente

    std::string prevDate;// = date;
     while (it == data.end()) {
         prevDate = findPreviousDate(date);
         it = data.find(prevDate);
         date = prevDate;
     }
     return strToFloat(it->second);
}

void BitcoinExchange::execute(const std::string& filen)
{
    std::ifstream inputfile(filen.c_str());
    std::string line;

    if (!inputfile.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Leer primera línea para verificar que el formato sea correcto
    std::getline(inputfile, line); // Saltar primera línea

    // Eliminar caracteres no imprimibles de la cadena
    removeNonPrintableChars(line);

    if (line != "date | value") {
        std::cerr << "Error: file must start with 'date | value'" << std::endl;
        std::cerr << "Found: " << line << std::endl;
        exit(EXIT_FAILURE);
    }
    while (std::getline(inputfile, line))
    {
        //Separar 
        size_t separator = line.find('|');
        if (separator == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, separator);
        removeNonPrintableChars(date);
        std::string value = line.substr(separator + 1);
        removeNonPrintableChars(value);
        //ver si son validos la fecha y el valor
        try {
            if (!dateIsCorrect(date))
                throw std::invalid_argument("invalid date: " + date);
            valueIsCorrect(value);
            //Se calcula el valor de Bitcoin multiplicando el tipo de cambio
            //por el valor proporcionado en la entrada y se imprime el resultado. luego se cierra el archivo
            std::cout << date << " => " << value << " = " << getBitcoinChange(date) * strToFloat(value) << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    inputfile.close();
}