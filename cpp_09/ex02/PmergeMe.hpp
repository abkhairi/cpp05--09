/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:51:11 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/28 14:52:37 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream> 

class PmergeMe{
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &ob);
        PmergeMe& operator=(const PmergeMe &ob);
        ~PmergeMe(); 

        double    sorted_vector(std::vector<int> &vec);
        double    sorted_deque(std::deque<int> &dequ);

};

void print_vec(std::vector<int> v);
bool ft_number(std::string s);
#endif