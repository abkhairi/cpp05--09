/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:13:57 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/27 20:17:24 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename C>
C min(C a, C b) {
    return (a < b) ? a : b;
}

template<typename C>
C max(C a, C b) {
    return (a > b) ? a : b;
}


#endif