/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:41:42 by mdahani           #+#    #+#             */
/*   Updated: 2025/11/06 12:09:29 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

// * Includes
#include <iostream>
#include <vector>
#include <algorithm>

// * Class With Orthodox Canonical Form
class Span {
    // ! private
    private:
        unsigned int sizeOfvector;
        std::vector<int>vector;
        std::vector<int>::iterator it;

    // ! public
    public:
        // * Default constructor
        Span();

        // * Parametrised constructor
        Span(const unsigned int &size);

        // * Copy constructor
        Span(const Span &other);

        // * Copy assignment operator
        Span &operator=(const Span &other);

        // * Destructor
        ~Span();
        
        // * Methods
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
};
#endif