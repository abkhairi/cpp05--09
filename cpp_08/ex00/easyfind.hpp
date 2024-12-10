/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:14:20 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/14 13:19:48 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
int easyfind(T vec, int i)
{
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), i);
    if (it == vec.end())
        throw "not found ";
    return (*it);
}

#endif