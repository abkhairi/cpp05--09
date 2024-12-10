/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:08:57 by abkhairi          #+#    #+#             */
/*   Updated: 2024/11/05 20:05:51 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av) 
{
    try
    {
        if (ac != 2)
            throw "Error: could not open file.";
        BitcoinExchange ob_btc;
        ob_btc.stock_and_pars(av[1]);
    }
    catch (const char* e)
    {
        std::cerr << e << std::endl;
    }
    return 0;
}