/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:00:47 by mdahani           #+#    #+#             */
/*   Updated: 2025/11/07 18:46:46 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// * Includes
#include <iostream>
#include <algorithm>

// * Functions
template<typename T>
typename T::const_iterator easyfind(const T &container, const int num){
    // * we use const_iterator because we get const container and we don't need to edit the iterator just read it
    typename T::const_iterator it;
    
    it = std::find(container.begin(), container.end(), num);
    if (it == container.end()){
        throw std::runtime_error("Value not found");
    }

    return it;
}

#endif