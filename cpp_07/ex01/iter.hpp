/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:12:48 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/27 21:13:28 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T *addr, int len, F func)
{
    for (int i = 0; len > i; i++)
        func(addr[i]);
}

void print(char x)
{
	std::cout << x;
}

template <typename T>
void print_type(T t)
{
	std::cout << t << '.';
}


#endif