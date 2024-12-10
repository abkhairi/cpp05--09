/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:49:26 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/15 13:21:27 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span{
    private :
        unsigned int N;
        std::vector<int> vec;
    public :
        Span();
        Span(unsigned int N);
        Span(const Span &oldobj);
        Span& operator=(const Span &oldobj);
        ~Span();
        
        void    addNumber(int nbr);
        int     shortestSpan();
        int     longestSpan();
        void    display();
};


#endif