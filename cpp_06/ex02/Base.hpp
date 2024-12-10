/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:12:32 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 17:52:33 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base 
{
    public:
        virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif