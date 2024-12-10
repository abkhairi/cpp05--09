/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:29:49 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/19 15:29:50 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T , Container>
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack &ob)
        {
            *this = ob;
        }
        MutantStack& operator=(const MutantStack &ob)
        {
            if(this != &ob)
                return (this->c = ob.c);
            return (*this);
        }
        ~MutantStack(){};
    
    typedef typename Container::iterator iterator; //typedef = create a new alias iterator for the type container::iterator
    typedef typename Container::iterator const_it; //typename = pour identify Container::iterator est un type depande d un parametre de template

    iterator  begin(void)
    {
        return (this->c.begin());
    }
    iterator  end(void)
    {
        return (this->c.end());
    }
    const_it    begin(void) const
    {
        return (this->c.begin());
    }
    const_it    end(void) const
    {
        return (this->c.end());
    }
};

#endif