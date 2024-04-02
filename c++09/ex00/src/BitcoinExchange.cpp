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
        std::cout << "date: " << date << " value: " << value << std::endl;
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

void BitcoinExchange::execute(const std::string& filen)
{
    std::ifstream inputfile(filen.c_str());
    std::string line;

    if (!inputfile.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    // leer primera linea para verificar que el formato sea correcto
    std::getline(inputfile, line); // skip first line

    if (line != "date | value")
    {
        std::cout << "Error: file must start with date | value" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (std::getline(inputfile, line))
    {
        //Separar 
        int separator = line.find('|');
        if (separator == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, separator);
        std::string value = line.substr(separator + 1);
    }

}