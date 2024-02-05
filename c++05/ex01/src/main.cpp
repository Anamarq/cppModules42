/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
    try {
        // Crear un burócrata
        Bureaucrat bureaucrat("Anaxula", 20);
        std::cout << bureaucrat << std::endl;

        // Crear un formulario
        Form form("Application Form", false, 40, 30);
        std::cout << form << std::endl;

        // Intentar firmar el formulario con el burócrata
        bureaucrat.signForm(form);

        // Intentar crear un formulario con una calificación de firma inválida
        Form invalidForm("Invalid Form", false, 160, 30);

        // Intentar crear un burócrata con una calificación inválida
        Bureaucrat invalidBureaucrat("Invalid Bureaucrat", 200);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}