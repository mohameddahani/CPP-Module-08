/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:34:27 by mdahani           #+#    #+#             */
/*   Updated: 2025/11/08 09:58:18 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::cout << "==========================" << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // 17
    // 1
    // 5
    // 3
    // 5
    // 737
    // 0

    std::cout << "==========================" << std::endl;

    std::stack<int> s(mstack);

    while (!s.empty()){
        std::cout << s.top() << std::endl;
        s.pop();
    }

    // 0
    // 737
    // 5
    // 3
    // 5

    std::cout << "==========================" << std::endl;

    // ! Check for constant container
    const MutantStack<int> mstack_const(mstack);
    MutantStack<int>::const_iterator it2 = mstack_const.begin();
    MutantStack<int>::const_iterator ite2 = mstack_const.end();
    for (size_t i = 0; (it2 != ite2) && i < 4; i++){
        std::cout << mstack_const.top() << std::endl;
    }

    return 0;
}