/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:08:32 by abkhairi          #+#    #+#             */
/*   Updated: 2024/12/10 11:41:37 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw "error please check arguemnt!";
        else
        {
            std::string str = av[1];
            ScalarConverter::convert(str);    
        }
    }
    catch (const char *msj)
    {
        std::cerr <<" an "<< msj << std::endl ;
    }
    return (0);
}



// int main(int ac, char **av)
// {
//     if (ac != 2)
//     {
//         std::cout << "error please check arguemnt" << std::endl;
//         return 1;
//     }
//     std::string str = av[1];
//     ScalarConverter::convert(str);
//     return (0);
// }
