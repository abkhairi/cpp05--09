/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:51:06 by abkhairi          #+#    #+#             */
/*   Updated: 2024/11/05 20:17:22 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    try
    {
        if (ac < 2 || av[1][0] == '\0')
            throw ("Error");

        PmergeMe ob_merge;
        std::vector<int> vec;
        std::deque<int> dequ;

        for (int i = 1; ac > i; i++)
        {
            if (av[i][0] == '\0')
            {
                throw ("Error");
            }
            if (ft_number(av[i]) == false)
            {
                throw ("Error");
            }
            long nbr = std::strtol(av[i], NULL, 10);
            if (nbr > 2147483647)
            {
                std::cerr<<"Error"<<std::endl;
                exit (1);
            }
            vec.push_back(nbr);
            dequ.push_back(nbr);
        }
        if (vec.size() <= 1)
        {
            throw ("are you wanted to sorted one number ?!");
        }
        // Before 
        std::cout << "Before : "; 
        std::vector<int>::iterator it = vec.begin();
        for (; it != vec.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        double time_v = ob_merge.sorted_vector(vec); // sorted vector
        double time_d = ob_merge.sorted_deque(dequ); // sorted deque

        std::cout << "After  : "; 
        std::vector<int>::iterator ite = vec.begin();
        for (; ite != vec.end(); ite++)
            std::cout << *ite << " ";
        std::cout << std::endl;
        //After
        std::cout << "Time to process a range of " <<vec.size() <<" elements with std::vector : "<<time_v << " us"<<std::endl;
        std::cout << "Time to process a range of " <<dequ.size() <<" elements with std::deque : "<<time_d << " us"<<std::endl;
    }
    catch(const char *e)
    {
        std::cerr << e << std::endl;
    }
    return 0;
}