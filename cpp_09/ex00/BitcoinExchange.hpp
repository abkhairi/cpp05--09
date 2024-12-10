/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:09:24 by abkhairi          #+#    #+#             */
/*   Updated: 2024/11/04 12:36:50 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>  
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>



class BitcoinExchange{
    public :
        std::map<std::string , double> ob_map;
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& ob);
    BitcoinExchange& operator=(const BitcoinExchange &ob);
    ~BitcoinExchange();

    int stock_and_pars(std::string str);
};

#endif

