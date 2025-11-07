/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:41:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/11/07 18:46:18 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// * ──────────────────────────────────────────────────────────────
// ?   ⚙️ C++ STL — SHORT REFERENCE GUIDE
// * ──────────────────────────────────────────────────────────────
//
// 🔹 STL OVERVIEW
// ────────────────────────────────────────────
// STL (Standard Template Library) provides reusable, efficient tools
// to store, access, and manipulate data.
//
// Components:
//  1️⃣ Containers  → store data
//  2️⃣ Iterators   → traverse data
//  3️⃣ Algorithms  → manipulate data
//  4️⃣ Functors    → custom operations
//  5️⃣ Allocators  → memory management
//
// * ──────────────────────────────────────────────
//
// 🔹 CONTAINERS (DATA STRUCTURES)
// ────────────────────────────────────────────
//
// ▓ 1️⃣ Sequence Containers → store elements in linear order
// ------------------------------------------------------------
// array<T, N>       → fixed size, fast O(1) access
// vector<T>         → dynamic array, O(1) access, O(1) push_back
// deque<T>          → fast insert/remove at both ends
// list<T>           → doubly linked list (O(1) insert/remove)
// forward_list<T>   → singly linked list (O(1) insert/remove front)
//
// ▓ 2️⃣ Associative Containers → sorted key-based (Red-Black Tree)
// ------------------------------------------------------------
// set<T>            → unique sorted values
// multiset<T>       → sorted values, duplicates allowed
// map<K, V>         → key-value, unique keys
// multimap<K, V>    → key-value, duplicate keys
//
// ▓ 3️⃣ Unordered Associative Containers → hash table based
// ------------------------------------------------------------
// unordered_set<T>        → unique hashed values
// unordered_multiset<T>   → hashed values, duplicates allowed
// unordered_map<K, V>     → key-value, hashed, unique keys
// unordered_multimap<K, V>→ key-value, hashed, duplicate keys
//
// ▓ 4️⃣ Container Adapters → restricted interfaces
// ------------------------------------------------------------
// stack<T>          → LIFO (default: deque)
// queue<T>          → FIFO (default: deque)
// priority_queue<T> → max-heap (default: vector)
//
// * ──────────────────────────────────────────────
//
// 🔹 ITERATORS
// ────────────────────────────────────────────
// Objects similar to pointers used to traverse containers.
//
// Types:
//  - Input          (read-only, single-pass, e.g., istream_iterator)
//  - Output         (write-only, single-pass, e.g., ostream_iterator)
//  - Forward        (multi-pass, e.g., forward_list)
//  - Bidirectional  (e.g., list, set, map)
//  - Random Access  (e.g., vector, deque, array)
//
// Example:
// ```cpp
// for (auto it = v.begin(); it != v.end(); ++it)
//     std::cout << *it << " ";
// ```
//
// * ──────────────────────────────────────────────
//
// 🔹 ALGORITHMS
// ────────────────────────────────────────────
// Generic functions in <algorithm> working via iterators.
//
// Common examples:
//  - sort(), reverse(), find(), count(), accumulate(), unique()
//
// Example:
// ```cpp
// std::sort(v.begin(), v.end());
// std::reverse(v.begin(), v.end());
// ```
//
// * ──────────────────────────────────────────────
//
// 🔹 COMPLEXITY OVERVIEW
// ────────────────────────────────────────────
// Container        | Access | Insert End | Insert Mid | Ordered | Hash
// ────────────────────────────────────────────
// array            | O(1)   | N/A        | N/A        | No      | No
// vector           | O(1)   | O(1)*      | O(n)       | No      | No
// deque            | O(1)   | O(1)       | O(n)       | No      | No
// list             | O(n)   | O(1)       | O(1)*      | No      | No
// set/map          | O(log n)| O(log n)  | O(log n)   | Yes     | No
// unordered_map    | O(1)*  | O(1)*      | O(1)*      | No      | Yes
// (* = average)
//
// * ──────────────────────────────────────────────
//
// 🔹 QUICK RECOMMENDATION
// ────────────────────────────────────────────
// Goal                               → Container
// ────────────────────────────────────────────
// Fast random access                 → vector / array
// Insert/remove both ends            → deque
// Many middle insertions/removals    → list
// Unique sorted elements             → set
// Key-value sorted                   → map
// Fast key lookup (unordered)        → unordered_map
// Stack behavior                     → stack
// Queue behavior                     → queue
// Priority-based access              → priority_queue
//
// * ──────────────────────────────────────────────





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
