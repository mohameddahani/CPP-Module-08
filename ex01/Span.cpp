/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:41:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/11/06 18:32:55 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// * ──────────────────────────────────────────────────────────────
         // ?   📘 C++ SEQUENCE CONTAINERS COMPARISON TABLE
// * ──────────────────────────────────────────────────────────────
// * 
// ! Container:        array
// * ────────────────────────────────────────────
// * Memory Structure:  Static contiguous block (fixed size)
// * Access Speed:      O(1) (very fast)
// * Add/Remove End:    Not possible (fixed size)
// * Add/Remove Begin:  Not possible
// * Add/Remove Middle: Not possible
// * Capacity:          Fixed at creation
// * Iterators:         Random access
// * Use Case:          When size is known and never changes
// * 
// * ────────────────────────────────────────────
// * 
// ! Container:        vector
// * ────────────────────────────────────────────
// * Memory Structure:  Dynamic contiguous array (heap)
// * Access Speed:      O(1)
// * Add/Remove End:    O(1) amortized (very fast)
// * Add/Remove Begin:  O(n)
// * Add/Remove Middle: O(n)
// * Capacity:          Dynamic (auto-expands, usually x2)
// * Iterators:         Random access
// * Use Case:          When fast random access and adding at end only
// * 
// * ────────────────────────────────────────────
// * 
// ! Container:        deque
// * ────────────────────────────────────────────
// * Memory Structure:  Multiple contiguous blocks (with pointer map)
// * Access Speed:      O(1) (slightly slower than vector)
// * Add/Remove End:    O(1)
// * Add/Remove Begin:  O(1)
// * Add/Remove Middle: O(n)
// * Capacity:          Dynamic
// * Iterators:         Random access
// * Use Case:          When you need fast insertion/removal at both ends
// * 
// * ────────────────────────────────────────────
// * 
// ! Container:        list
// * ────────────────────────────────────────────
// * Memory Structure:  Doubly linked list (each node has prev/next)
// * Access Speed:      O(n)
// * Add/Remove End:    O(1)
// * Add/Remove Begin:  O(1)
// * Add/Remove Middle: O(1) (via iterator)
// * Capacity:          No fixed capacity (nodes allocated dynamically)
// * Iterators:         Bidirectional
// * Use Case:          When you frequently insert/remove in the middle
// * 
// * ────────────────────────────────────────────
// * 
// ! Container:        forward_list
// * ────────────────────────────────────────────
// * Memory Structure:  Singly linked list (one pointer to next)
// * Access Speed:      O(n)
// * Add/Remove End:    Not possible directly
// * Add/Remove Begin:  O(1)
// * Add/Remove Middle: O(1) (after known element)
// * Capacity:          No fixed capacity (dynamic allocation)
// * Iterators:         Forward only
// * Use Case:          When memory efficiency matters and only forward traversal needed
// * 
// * ────────────────────────────────────────────
// * 
                 // ?    🧠 MEMORY LAYOUT SUMMARY
// * ────────────────────────────────────────────
// * array         → contiguous (stack)
// * vector        → contiguous (heap)
// * deque         → segmented blocks (non-contiguous)
// * list          → scattered nodes (heap, doubly linked)
// * forward_list  → scattered nodes (heap, singly linked)
// * 
// * ────────────────────────────────────────────
// * 
                 // ?    ⚙️ BIG O COMPLEXITY
// * ────────────────────────────────────────────
// * Operation          array   vector  deque   list   forward_list
// * ────────────────────────────────────────────
// * Access by index     O(1)    O(1)    O(1)   O(n)        O(n)
// * Insert at end        -      O(1)    O(1)   O(1)          -
// * Insert at front       -     O(n)    O(1)   O(1)        O(1)
// * Insert in middle      -     O(n)    O(n)   O(1)*       O(1)*
// * Delete at end         -     O(1)    O(1)   O(1)          -
// * Delete at front       -     O(n)    O(1)   O(1)        O(1)
// * Delete in middle      -     O(n)    O(n)   O(1)*       O(1)*
// * (* requires iterator)
// * 
// * ────────────────────────────────────────────
// * 
                 // ?    💡 QUICK GUIDE
// * ────────────────────────────────────────────
// * Goal                                   Best Container
// * ────────────────────────────────────────────
// * Fast random access                     vector or array
// * Insert/remove at both ends             deque
// * Insert/remove in the middle often      list
// * Low memory and simple forward traversal forward_list
// * Fixed size, compile-time known         array
// * ────────────────────────────────────────────


// * Default constructor
Span::Span(): sizeOfvector(0){
    std::cout << "Default constructor of Span is called" << std::endl;
}

// * Parametrised constructor
Span::Span(const unsigned int &size): sizeOfvector(size){
    
    std::cout << "Parametrised constructor of Span is called" << std::endl;
}

// * Copy constructor with initializer list
Span::Span(const Span &other){
    // ! call copy assignment operator
    *this = other;

    std::cout << "Copy constructor of Span is called" << std::endl;
}

// * Copy assignment operator
Span &Span::operator=(const Span &other){
    this->sizeOfvector = other.sizeOfvector;
    
    std::cout << "Copy assignment operator of Span is called" << std::endl;
    
    return *this;
}

// * Destructor
Span::~Span(){
    std::cout << "Span is destroyed" << std::endl;
}

// * Setters & Getters

// * Methods
void Span::addNumber(int number){
    if (this->sizeOfvector == this->vector.size()){
        throw std::runtime_error("The size is full");
    }

    this->vector.push_back(number);
}

int Span::shortestSpan(){
    if (this->vector.size() == 0 || this->vector.size() == 1){
        throw std::runtime_error("Add more numbers");
    }

    // * sort the vector
    std::sort(this->vector.begin(), this->vector.end());

    // * after sorting store the range between sorted number in another vector
    std::vector<int>rangeBetweenNumbers;
    for (size_t i = 0; i < this->vector.size(); i++){
        for (size_t j = i + 1; j < this->vector.size(); j++){
            rangeBetweenNumbers.push_back(abs(this->vector[i] - this->vector[j]));
        }
    }
    // * sort the ranges
    std::sort(rangeBetweenNumbers.begin(), rangeBetweenNumbers.end());
    
    return *rangeBetweenNumbers.begin();
}


int Span::longestSpan(){
    if (this->vector.size() == 0 || this->vector.size() == 1){
        throw std::runtime_error("Add more numbers");
    }

    // * sort the vector
    std::sort(this->vector.begin(), this->vector.end());

    // * after sorting store the range between sorted number in another vector
    std::vector<int>rangeBetweenNumbers;
    for (size_t i = 0; i < this->vector.size(); i++){
        for (size_t j = i + 1; j < this->vector.size(); j++){
            rangeBetweenNumbers.push_back(abs(this->vector[i] - this->vector[j]));
        }
    }
    // * sort the ranges
    std::sort(rangeBetweenNumbers.begin(), rangeBetweenNumbers.end());
    
    return rangeBetweenNumbers[rangeBetweenNumbers.size() - 1];
}
