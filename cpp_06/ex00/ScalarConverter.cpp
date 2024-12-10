/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:04:54 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 18:43:27 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &ob){
    *this = ob;
}

int is_digit(char c, int &ptr)
{
    if (!(c >= '0' && c <= '9'))
        return(0);
    ptr = 2;
    return 1;
}

int check_char(char c, int len, int &ptr)
{
    if (len != 1)
        return 0;
    if (c >= 32 && c <= 126)
    {
        ptr = 1;
        return (1);
    }
    return 0;
}

int check_float(std::string str, int &ptr)
{
    int i = 0;
    int count_p = 0;
    size_t found;
    int j = 0;
    int k = 0;


    while (str[i])
    {
        if(str[i] == '.')
            count_p++;
        i++;
    }
    if (count_p != 1)
        return 0;
    found = str.find('.');
    if (found == 0)
        return 0;
    if (str[found + 1] == '\0')
        return 0;
    while(str[j])
        j++;
    std::string before_point = str.substr(0, found);
    std::string after_point = str.substr(found + 1, j - found);
    if (after_point[j - found - 2] != 'f')
        return 0;
    after_point = str.substr(found + 1, (j - found) - 2);
    while (after_point[k] != '\0')
    {
        if (!(after_point[k] >= '0' && after_point[k] <= '9'))
            return 0;
        k++;
    }
    k = 0;
    if (before_point[k] == '-' || before_point[k] == '+')
        k = 1;
    while (before_point[k])
    {
        if (!(before_point[k] >= '0' && before_point[k] <= '9'))
            return 0;
        k++;
    }
	ptr = 3;
    return 1;
}

int check_doubl(std::string str, int &ptr)
{
    int i = 0;
    int count_p = 0;
    size_t found;
    int j = 0;
    int k = 0;

    while (str[i])
    {
        if(str[i] == '.')
            count_p++;
        i++;
    }
    if (count_p != 1)
        return 0;
    found = str.find('.');// index de .
    if (found == 0)
        return 0;
    if (str[found + 1] == '\0')
        return 0;
    while(str[j])
        j++;
    std::string before_point = str.substr(0, found);
    std::string after_point = str.substr(found + 1, j - found);
    if (before_point[k] == '-' || before_point[k] == '+')
        k = 1;
    while (before_point[k])
    {
        if (!(before_point[k] >= '0' && before_point[k] <= '9'))
            return 0;
        k++;
    }
    k = 0;
    while (after_point[k])
    {
        if (!(after_point[k] >= '0' && after_point[k] <= '9'))
            return 0;
        k++;
    }
	ptr = 4;
    return 1;
}

int parsing(std::string str, int &ptr)
{
    int i   = 0;
    int len = 0;

    while (str[len])
        len++;
    if (len == 1 && (str[0] == '+' || str[0] == '-')) //./convert - or +; 
    {
        ptr = 1;
        return (1);
    }
    if (str[i] == '-' || str[i] == '+')
        i = 1;
    while (str[i])
    {
        if (!check_doubl(str, ptr) && !is_digit(str[i], ptr) && !check_float(str, ptr) && !check_char(str[i], len, ptr))
        {
            ptr = 1337;
            return (0);
        }
        i++;
    }
    return(1);
}

void ScalarConverter::convert(std::string str)
{
    int	ptr = 1337;
    int	j = 0;

    char	ch;
    float	floating;
    double	doubl;

    if (str[j] == '-')
        j++;
    while (str[j] && str[j] >= '0' && str[j] <= '9')
        j++;
    if (j > 308)
    {
        std::cout<<"char: Non displayable"<<std::endl;
        std::cout<<"int: out of range"<<std::endl;
        if (str[0] == '-')
        {
            std::cout<<"float: -inff"<<std::endl;
            std::cout<<"double: -inf"<<std::endl;
        }
        else
        {
            std::cout<<"float: inff"<<std::endl;
            std::cout<<"double: inf"<<std::endl;
        }
        return ;
    }
    size_t point_;
    size_t f = str.find('.');
    if (std::string::npos != f)
    {
        size_t len = 0;
        while(str[len])
            len++;
        point_ = len - f - 1;
    }
    else
        point_ = 0;
    // point_ = déterminer le nombre de chiffres après le point
    if (str.empty() || parsing(str, ptr) == 0)
    {
        std::cout << "char = Impossible"<< std::endl;
        std::cout << "int =  Impossible" << std::endl;
        std::cout << "float = nanf" <<std::endl;
        std::cout << "double = nan" <<std::endl;
        return ;
    }
    if (ptr == 1)
    {
        ch = str[0];
        std::cout << "char = " << ch << std::endl;
        std::cout << "int = " << static_cast<int>(ch) << std::endl;
        std::cout << "float = " << static_cast<float>(ch)<< ".0f" << std::endl;
        std::cout << "double = " << static_cast<double>(ch) <<".0"<< std::endl;
    }
    else if (ptr == 2)
    {
		const char* cstr2 = str.c_str();// convertit un objet de type std::string en une chaîne C-style
        double intger = strtod(cstr2, NULL);//convertit cette chaîne C-style en un nombre à virgule flottante (double)
        if (intger >= 32 && intger <= 126)
            std::cout << "char = " << static_cast<char>(intger) << std::endl;
        else
            std::cout << "char = Non displayable"<< std::endl;
        if (intger < -2147483648 || intger > 2147483647)
            std::cout << "int = out of range \n";
        else
            std::cout << "int = " << static_cast<int>(intger) << std::endl;
        std::cout << std::fixed;
        std::cout << "float = "  << std::setprecision(point_)<<static_cast<float>(intger) <<".0f" << std::endl;// setprecision(2) = Afficher 2 chiffres après la virgule 
        std::cout << "double = " << std::setprecision(point_)<<static_cast<double>(intger) <<".0" << std::endl;
    }
    else if (ptr == 3)
    {
		const char* cstr3 = str.c_str();
        floating = strtod(cstr3, NULL);
        if (floating >= 32 && floating <= 126)
        {
            std::cout << "char = " << static_cast<char>(floating) << std::endl;
        }
        else
            std::cout << "char = Non displayable"<< std::endl;
        if (floating < -2147483648 || floating > 2147483647)
        {
            std::cout << "int = out of range \n";
        }
        else
            std::cout << "int = " << static_cast<int>(floating) << std::endl;
         std::cout << std::fixed;
        std::cout << "float = " << std::setprecision(point_)<< floating <<"f" << std::endl;
        std::cout << "double = " <<std::setprecision(point_)<<  static_cast<double>(floating) << std::endl;
    }
    else if (ptr == 4)
    {
		const char* cstr4 = str.c_str();
        doubl = std::strtod(cstr4, NULL);
        if (doubl >= 32 && doubl <= 126)
            std::cout << "char = " << static_cast<char>(doubl) << std::endl;
        else
            std::cout << "char = Non displayable"<< std::endl;
        if (doubl < -2147483648 || doubl > 2147483647)
        {
            std::cout << "int = out of range \n";
        }
        else
            std::cout << "int = " << static_cast<int>(doubl) << std::endl;
        std::cout << std::fixed;
        std::cout << "float = " <<std::setprecision(point_)<< static_cast<float>(doubl)<< "f" << std::endl;
        std::cout << "double = " <<std::setprecision(point_)<< doubl << std::endl;
    }
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ob)
{
    (void)ob;
    return(*this);
}

ScalarConverter::~ScalarConverter() {

}