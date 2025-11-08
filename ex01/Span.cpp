/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:41:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/11/08 09:24:45 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// * ──────────────────────────────────────────────────────────────
// ?    ⚙️ C++ STANDARD TEMPLATE LIBRARY (STL) — COMPLETE GUIDE
// * ──────────────────────────────────────────────────────────────
//
// 🧠 INTRODUCTION
// ────────────────────────────────────────────
// The STL (Standard Template Library) is a powerful set of C++ template classes
// that provides ready-to-use and efficient tools to manage and manipulate data.
//
// It includes:
//  1️⃣ Containers  → Data structures that store data
//  2️⃣ Iterators   → Objects that point to container elements
//  3️⃣ Algorithms  → Functions that perform operations on containers
//  4️⃣ Function Objects (Functors) → Objects used like functions
//  5️⃣ Allocators  → Handle memory management for containers
//
// STL is built using templates, meaning it works with any data type (int, string, custom class, etc.)
//
// * ──────────────────────────────────────────────
//
// 🔹 1️⃣ CONTAINERS — “Where Data Lives”
// ────────────────────────────────────────────
// A container is a class template that stores a collection of elements (objects or data).
// Each container type has a different internal memory structure and access strategy.
//
// Containers are divided into 4 main categories:
//
//   ▪ Sequence Containers
//   ▪ Associative Containers
//   ▪ Unordered Associative Containers
//   ▪ Container Adapters
//
// ────────────────────────────────────────────
//
// ▓ SEQUENCE CONTAINERS (Linear Storage)
// --------------------------------------
// Elements are stored in a specific linear sequence (order of insertion matters).
//
// * std::array<T, N>        → Fixed-size array (stack memory)
// * std::vector<T>          → Dynamic array (contiguous, grows automatically)
// * std::deque<T>           → Double-ended queue (fast at both ends)
// * std::list<T>            → Doubly linked list
// * std::forward_list<T>    → Singly linked list (less memory, forward-only)
//
// 🧩 Use when: element order matters or frequent insertion/removal occurs.
//
// ────────────────────────────────────────────
//
// ▓ ASSOCIATIVE CONTAINERS (Ordered Key-Based Storage)
// ----------------------------------------------------
// Store elements sorted by key using balanced binary trees (Red-Black Tree).
//
// * std::set<T>             → Unique, sorted values
// * std::multiset<T>        → Sorted values, allows duplicates
// * std::map<Key, T>        → Key-value pairs with unique keys
// * std::multimap<Key, T>   → Key-value pairs allowing duplicate keys
//
// 🧩 Use when: you need automatic sorting and no duplicate keys (or controlled duplicates).
//
// ────────────────────────────────────────────
//
// ▓ UNORDERED ASSOCIATIVE CONTAINERS (Hash Table Based)
// -----------------------------------------------------
// Store elements as key-value pairs but **not sorted**. Instead, they use hash functions.
//
// * std::unordered_set<T>         → Unique elements, hashed
// * std::unordered_multiset<T>    → Hashed elements, allows duplicates
// * std::unordered_map<Key, T>    → Key-value pairs, unique keys
// * std::unordered_multimap<Key, T> → Key-value pairs, duplicate keys
//
// 🧩 Use when: you need **fast lookups (O(1) average)** and don’t care about order.
//
// ────────────────────────────────────────────
//
// ▓ CONTAINER ADAPTERS (Restricted Interfaces)
// --------------------------------------------
// These are wrappers that provide a simplified interface on top of existing containers.
//
// * std::stack<T>                 → LIFO (Last In, First Out) [based on deque by default]
// * std::queue<T>                 → FIFO (First In, First Out) [based on deque by default]
// * std::priority_queue<T>        → Elements ordered by priority (max-heap by default)
//
// 🧩 Use when: you need specific behaviors (stack, queue, or heap) without worrying about internals.
//
// * ──────────────────────────────────────────────
//
// 🔹 2️⃣ ITERATORS — “The Connectors”
// ────────────────────────────────────────────
// Iterators act like **pointers** that can traverse elements of a container.
// They generalize access to container elements, allowing algorithms to work with any container type.
//
// Types of iterators:
//   ▪ Input Iterator        → Read data only once
//   ▪ Output Iterator       → Write data only once
//   ▪ Forward Iterator      → Traverse forward (like in forward_list)
//   ▪ Bidirectional Iterator→ Move forward/backward (like in list, set, map)
//   ▪ Random Access Iterator→ Jump to any element (like in vector, deque, array)
//
// Example:
// ```cpp
// std::vector<int> v = {10, 20, 30};
// std::vector<int>::iterator it = v.begin();
// while (it != v.end()) {
//     std::cout << *it << " "; // Access element
//     ++it; // Move to next
// }
// ```
//
// 🧩 Iterators make STL algorithms work with any container.
//
// * ──────────────────────────────────────────────
//
// 🔹 3️⃣ ALGORITHMS — “The Workers”
// ────────────────────────────────────────────
// STL algorithms are a set of functions that perform operations on containers via iterators.
// Defined in <algorithm> and <numeric>.
//
// Examples:
//  ▪ sort(begin, end)             → Sorts elements in ascending order
//  ▪ reverse(begin, end)          → Reverses order
//  ▪ find(begin, end, value)      → Finds first occurrence
//  ▪ count(begin, end, value)     → Counts occurrences
//  ▪ accumulate(begin, end, 0)    → Sums up all elements
//  ▪ unique(begin, end)           → Removes consecutive duplicates
//  ▪ lower_bound(begin, end, val) → First element ≥ val (sorted containers)
//
// 🧩 Algorithms use iterators, not container-specific functions —
//     that’s why they can work with any container type.
//
// * ──────────────────────────────────────────────
//
// 🔹 4️⃣ FUNCTION OBJECTS (FUNCTORS)
// ────────────────────────────────────────────
// A **functor** is a class that acts like a function by overloading operator().
// They are often used in algorithms to define custom behavior.
//
// Example:
// ```cpp
// struct Compare {
//     bool operator()(int a, int b) const { return a > b; }
// };
// std::sort(v.begin(), v.end(), Compare()); // Sort descending
// ```
//
// 🧩 STL provides predefined functors like std::less, std::greater, etc.
//
// * ──────────────────────────────────────────────
//
// 🔹 5️⃣ ALLOCATORS
// ────────────────────────────────────────────
// Allocators handle memory allocation for containers (default is std::allocator).
// They abstract low-level memory management to make containers more flexible and efficient.
//
// You rarely need to modify them manually.
//
// * ──────────────────────────────────────────────
//
// ⚙️ PERFORMANCE & MEMORY SUMMARY
// ────────────────────────────────────────────
// Container         | Memory Layout          | Random Access | Insert/Erase (ends) | Insert/Erase (middle)
// ────────────────────────────────────────────
// array             | contiguous (stack)     | O(1)          | N/A                 | N/A
// vector            | contiguous (heap)      | O(1)          | O(1)/O(n)           | O(n)
// deque             | segmented (heap)       | O(1)          | O(1)/O(1)           | O(n)
// list              | scattered (heap)       | O(n)          | O(1)/O(1)           | O(1)*
// forward_list      | scattered (heap)       | O(n)          | O(1) front only     | O(1)*
// set/map           | tree (balanced BST)    | O(log n)      | O(log n)            | O(log n)
// unordered_set/map | hash table (buckets)   | O(1)* avg     | O(1)* avg           | O(1)* avg
// (* requires iterator)
//
// * ──────────────────────────────────────────────
//
// ✅ QUICK REFERENCE — CHOOSE THE RIGHT CONTAINER
// ────────────────────────────────────────────
// Goal                                  → Best Container
// ────────────────────────────────────────────
// Fast random access                    → vector / array
// Insert/remove both ends               → deque
// Frequent middle insertions/removals   → list
// Unique sorted elements                → set
// Key-value with order                  → map
// Fast lookup (unordered)               → unordered_map
// LIFO stack behavior                   → stack
// FIFO queue behavior                   → queue
// Priority ordering                     → priority_queue
//
// * ──────────────────────────────────────────────
//
// 🔸 Summary:
// STL = Containers + Iterators + Algorithms + Functors + Allocators
// They work together as a generic, reusable framework that gives
// both **performance** and **flexibility** in modern C++.
//
// * ──────────────────────────────────────────────────────────────



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
