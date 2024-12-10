// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:26:25 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/21 12:25:45 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	sum_of_size;
	char	*p;

	if (s == NULL)
		return (0);
	j = 0;
	sum_of_size = strlen(s) + start;
	if (strlen(s) < start)
	{
		p = new char;
		*p = '\0';
		return (p);
	}
	if (sum_of_size < len)
		len = sum_of_size;
	p = new char[len + 1];
	if (!p)
		return (0);
	while (s[start] && j < len)
		p[j++] = s[start++];
	p[j] = '\0';
	return (p);
}

static size_t	ft_nbrword(const char *str, char c)
{
	size_t	i;
	size_t	counteur;
	size_t	len;

	len = strlen(str);
	counteur = 0;
	i = 0;
	while (i < len)
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			counteur++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (counteur);
}

static char	**free_all(char **s, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i && s[j] != NULL)
	{
		delete [] s[j];
		s[j] = NULL;
		j++;
	}
	delete [] s;
	s = NULL;
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **spliter, size_t wc)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	while (i < wc)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		spliter[i] = ft_substr(s, start, end - start);
		if (!spliter[i])
			return (free_all(spliter, i));
		start = end;
		i++;
	}
	*(spliter + i) = NULL;
	return (spliter);
}

char	**ft_split(char const *s, char c)
{
	char	**spliter;
	size_t	wc = 0;

	if (!s)
		return (0);
	wc = ft_nbrword(s, c); 
	spliter =  new (std::nothrow) char*[wc + 1];
	if (!spliter)
		return (0);
	return (ft_fill(s, c, spliter, wc));
}
//-------------------------------- fin split() ----------------------------------------

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ob)
{
	*this = ob;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ob)
{
	if(this != &ob)
	{
		this->ob_map = ob.ob_map;
	}
	return(*this);
}



int ft_stringToInt(std::string str)
{
    return (std::atoi(str.c_str()));
}

int is_digit(char ch)
{
    return ch >= '0' && ch <= '9'; // Check if the character is between '0' and '9'
}

int check_is_leap(int year, int month, int day)
{
    (void )day;
    (void )month;
    if ((year % 4 ==0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

std::string ft_trim(std::string& str) {
    // Find the first position that is not a whitespace
    size_t first = str.find_first_not_of(" \t\n\r\f\v");

    // If the string is empty or contains only whitespace
    if (first == std::string::npos)
        return "";
    
    // Find the last position that is not a whitespace
    size_t last = str.find_last_not_of(" \t\n\r\f\v");

    // Return the substring that contains no leading or trailing whitespace
    return str.substr(first, (last - first + 1));
}

int BitcoinExchange::stock_and_pars(std::string str) 
{
    std::ifstream obj_data("data.csv");
    std::string line_data;
    if (!obj_data.is_open())
    {
        std::cerr << "Error: could not open the file!\n";
        return 1;
    }
    int e = 0;
    if (e == 0)
    {
        std::getline(obj_data, line_data);
        if (line_data != "date,exchange_rate")
        {   
            std::cout << "Error: file data\n";
            return 1; 
        }
        e = 1;
    }
    char **tab;
    while (std::getline(obj_data, line_data))
    {
        tab = ft_split(line_data.c_str(), ',');
        std::string key(tab[0]);
        std::string value_t_db(tab[1]);
        size_t k = 0;
        while (tab[k])
            k++;
        free_all(tab, k);
        double value;
        key = ft_trim(key);
        value_t_db = ft_trim(value_t_db);
        value = std::strtod(value_t_db.c_str(), NULL);
        ob_map[key] = value;
    }
    std::ifstream obj_file(str); // Ouverture du fichier
    if (!obj_file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1; // Code d'erreur
    }
    int flag = 0;
    std::string line;
    if (flag == 0 )
    {
        std::getline(obj_file, line);
        if (std::strcmp(line.c_str(),"date | value") != 0)
        {
            std::cerr << "error\n";
            return 1;   
        }
        flag = 1;
    }
    while (std::getline(obj_file, line))
    {
        try // here
        {
            std::string first_str = line.substr(0, 10);
            std::string second_str = line.substr(10, 3);
            std::string final_str = line.substr(13);
            double number = strtod(final_str.c_str(), NULL);
            int count_point = 0;
            int j = 0;
            
            int year = ft_stringToInt(line.substr(0, 4));
            int month = ft_stringToInt(line.substr(5, 2));
            int day = ft_stringToInt(line.substr(8, 2));

            // if (year <= 2009 && day <= 1)
            //     throw "Error:";
            if (first_str[4] != '-' || first_str[7] != '-')
                throw "Error:";
            for (size_t i = 0; i <= 3; i++)
            {
                if (is_digit(first_str[i]) == 0 || year < 2009 || year >= 2025 || day > 31 || day <= 0)
                    throw "Error:";
            }
            for (size_t i = 5; i <= 6; i++)
            {
                if (is_digit(first_str[i]) == 0 || month >= 13 || month <= 0)
                    throw "Error:";
            }
            if (check_is_leap(year, month, day) == 0)
            {
                if (month == 02 && (day <= 0 || day >= 29))
                    throw("Error :no leap moi2");   
                else if ((month != 2) && (month <= 7) && (month % 2 == 0) && (day <= 0 || day > 30))
                    throw "Error: mont deyal 04 06 ..";
                else if ((month != 2) && (month <= 7) && (month % 2 != 0) && (day <= 0 || day > 31))
                    throw "Error: mont deyal 04 06 ..";
                else if ((month != 2) && (month >= 8) && (month % 2 == 0) && (day <= 0 || day > 31))
                    throw "Error: mont deyal 04 06 ..";
                else if ((month != 2) && (month >= 8) && (month % 2 != 0) && (day <= 0 || day > 30))
                    throw "Error: mont deyal 04 06 ..";
            }
            else if(check_is_leap(year, month, day) == 1)
            {
                if (month == 02 && (day <= 0 || day >= 30))
                    throw("Error :no leap moi2"); 
                else if (month != 2 && month <= 7 && (month % 2 == 0) && (day <= 0 || day > 30))
                    throw "Error: mont deyal 04 06 ..";
                else if (month != 2 && month <= 7 && (month % 2 != 0) && (day <= 0 || day > 31))
                    throw "Error: mont deyal 04 06 ..";
                else if (month != 2 && month >= 8 && (month % 2 == 0) && (day <= 0 || day > 31))
                    throw "Error: mont deyal 04 06 ..";
                else if (month != 2 && month >= 8 && (month % 2 != 0) && (day <= 0 || day > 30))
                    throw "Error: mont deyal 04 06 ..";
            }
            if (second_str[0] != ' ' || second_str[1] != '|' || second_str[2] != ' ')
                throw "Error:";
            while (final_str[j])
            {
                if (final_str[j] == '.')
                    count_point++;
                j++;
            }
            if (count_point > 1 || final_str[0] == '.')
                throw "Error:";
            size_t i = 0;
            if (final_str.empty())
                throw "Error:";
            if ((final_str[0] == '-' || final_str[0] == '+') && final_str[1])
                i++;
            if (i == 1)
            {
                for (i = 1; final_str.length() > i; i++)
                {
                    if (final_str[i] == '.')
                        i++;
                    if (is_digit(final_str[i]) == 0)
                        throw "Error:";
                }
            }
            else if  (i == 0)
            {
                for (i = 0; final_str.length() > i; i++)
                {
                    if (final_str[i] == '.')
                        i++;
                    if (is_digit(final_str[i]) == 0)
                        throw "Error:";
                }
            }
            if (number < 0)
                throw std::invalid_argument("Error: not a positive number.");
            if (!(number <= 1000))
                throw std::invalid_argument("Error: too large a number.");
            std::map<std::string, double>::iterator it = ob_map.lower_bound(first_str);
            if (it != ob_map.end() && it->first == first_str)
                std::cout<<first_str<<" => "<<final_str<<" = " << (it->second * number)<< std::endl;
            else
            {
                if (it == ob_map.begin())
                    throw "Error";
                else
                {
                    --it;
                    std::cout<<first_str<<" => "<<final_str<<" = " << (it->second * number)<< std::endl;
                }
            }
        }
        catch(const std::invalid_argument &msj)
        {
            std::cerr << msj.what()<< std::endl;
        }
        catch(const char* e)
        {
            std::cerr<<e<<" bad input => "<<line<<std::endl;
        }
        catch(...)
        {
            std::cerr<<"Error: bad input => "<<line<<std::endl;
        }
    }
    obj_data.close();
    obj_file.close();
    return 0;
}


BitcoinExchange::~BitcoinExchange()
{
}