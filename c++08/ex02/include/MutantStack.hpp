
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <stack>
# include <iostream>

template< typename T, class Container = std::deque< T > >
class MutantStack : public std::stack<T, Container> {
public:
    typedef typename Container::iterator iterator;

    MutantStack(void) {};
    ~MutantStack(void) {};
    iterator begin();
    iterator end();
};


#include "MutantStack.tpp"
#endif