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

int main()
{
    try
    {
        Bureaucrat bureaucrat1("John Doe", 100);
        std::cout << "Created bureaucrat: " << bureaucrat1 << std::endl;

        bureaucrat1.incrementGrade();
        std::cout << "Incremented grade: " << bureaucrat1 << std::endl;

        bureaucrat1.decrementGrade();
        std::cout << "Decremented grade: " << bureaucrat1 << std::endl;

        // Attempting to create a bureaucrat with an invalid grade (too low)
        Bureaucrat invalidBureaucrat("Invalid", 1);

        invalidBureaucrat.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
