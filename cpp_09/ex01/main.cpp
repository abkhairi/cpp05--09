/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:04:02 by abkhairi          #+#    #+#             */
/*   Updated: 2024/11/05 20:16:17 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Process Each Token:

If the token is a number: Push it onto the stack.
If the token is an operator (e.g., +, -, *, /):
    Pop the top two numbers from the stack.
    Apply the operator to these numbers.
    Push the result back onto the stack.
*/

#include "RPN.hpp"


int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            throw ("Error");
            return 1;
        }
        std::string str = av[1];
        if (str.empty())
        {
            throw ("Error");
            return 1;
        }
        RPN ob_rpn;
        ob_rpn.execute(str); 
    }
    catch(const char* e)
    {
        std::cerr<<e<<"\n";
    }
    return 0;
}