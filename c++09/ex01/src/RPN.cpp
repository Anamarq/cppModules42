/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const std::string& exp) : expression(exp) {}
RPN::RPN(const RPN& other) : expression(other.expression) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this == &other)
        return *this;
    expression = other.expression;
    return *this;
}

int operate(char op, int num1, int num2) {
    //hacer la operacion correspondiente segun el signo
    switch (op){
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0)
            return num1 / num2;
        else
        {
            std::cerr << "Error: Division by zero" << std::endl;
            exit(EXIT_FAILURE);
        }
    default:
        std::cerr << "Error: Invalid operator" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int RPN::evaluateRPN()
{
    std::stack<int> st;
    std::stringstream ss(expression);
    std::string token;

    //mientras que haya algo en el stream ...
    while (ss >> token)
    {
        //si hay un signo
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            //debe haber 2 operandos en el stack en ese momento, sino es inválida la expresion
            if (st.size() < 2)
            {
                std::cerr << "Error: Invalid expression" << std::endl;
                exit(EXIT_FAILURE);
            }
            // coger el primer y segundo valor, operar con ellos y poner el resultado en el stack
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int result = operate(token[0], num1, num2);
            st.push(result);
        }
        else
        {
            //Si no es un signo, debe ser un número. Se pone en el stack para luego operar
            int num;
            std::stringstream intStream(token);
            intStream >> num;
            try {
                if (!intStream)
                    throw std::invalid_argument("invalid value, must be numbers and is " + token);
            }
            catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
            st.push(num);
        }
    }
    //El stack debe tener un resultado final, sino es que la expresion esta mal
    if (st.size() != 1)
    {
        std::cerr << "Error: Invalid expression" << std::endl;
        exit(EXIT_FAILURE);
    }

    return st.top();
}
