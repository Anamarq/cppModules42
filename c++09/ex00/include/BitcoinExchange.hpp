/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string> // Asegúrate de incluir esta cabecera
#include <cstdlib> // Para incluir EXIT_FAILURE y EXIT_SUCCESS

class BitcoinExchange
{
private:
    std::map<std::string, std::string> data;

    void readData(const std::string& namedata);
    float getBitcoinChange(std::string date);

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& namedata);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void execute(const std::string& file);
};

#endif