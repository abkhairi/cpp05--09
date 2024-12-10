/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:04:07 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/27 20:14:38 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream> 
#include <cctype>
#include <cstdlib> // For atoi
#include <string>

class RPN {
    private:
        std::stack<int> my_stack;
    public:
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        ~RPN();
        void execute(std::string str);
};

#endif