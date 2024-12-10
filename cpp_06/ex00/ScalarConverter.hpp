/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:13:41 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 18:15:40 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &ob);
        ScalarConverter &operator=(const ScalarConverter &ob);
        ~ScalarConverter();
    public :
        static void convert(std::string str);
};
