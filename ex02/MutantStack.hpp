/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:34:43 by mdahani           #+#    #+#             */
/*   Updated: 2025/11/08 10:06:07 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

// * Includes
#include <iostream>
#include <stack>
#include <deque>

// * Class With Orthodox Canonical Form
// * Tempate Class
template<typename T>
class MutantStack: public std::stack<T> {
    // ! public
    public:
        // * Default constructor
        MutantStack(){
            std::cout << "Default constructor of MutantStack is called" << std::endl;
        };

        // * Copy constructor
        MutantStack(const MutantStack &other){
            *this = other;

            std::cout << "Copy constructor of MutantStack is called" << std::endl;
        };

        // * Copy assignment operator
        MutantStack &operator=(const MutantStack &other){
            std::stack<T>::operator=(other);

            std::cout << "Copy assignment operator of MutantStack is called" << std::endl;

            return *this;
        };

        // * Destructor
        ~MutantStack(){
            std::cout << "MutantStack is destroyed" << std::endl;
        };
        
        // * Methods
        // ? Define a iterator of deque
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;


        // * For non-constant object
        // ? this->c.begin(): this will return a iterator of first element on deque and last in stack
        iterator begin(){
            return this->c.begin();
        }
        
        // ? this->c.end(): this will return a iterator of last element on deque and first in stack
        iterator end(){
            return this->c.end();
        }

        // * For constant object
        // ? this->c.begin(): this will return a iterator of first element on deque and last in stack
        const_iterator begin() const {
            return this->c.begin();
        }
        
        // ? this->c.end(): this will return a iterator of last element on deque and first in stack
        const_iterator end() const {
            return this->c.end();
        }
};
#endif
