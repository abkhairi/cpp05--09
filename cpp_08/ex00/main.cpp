/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:09:34 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/14 13:39:58 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vec;
        int i; 
        
        i = 13;
        vec.push_back(5);
        vec.push_back(4);
        vec.push_back(9);
        vec.push_back(13);
        std::cout << easyfind(vec, i);
    }
    catch(const char* e)
    {
        std::cerr << "exception : " << e << '\n';
    }
    return 0;
}