/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:07:16 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/28 14:07:18 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

template<class T>
class Array
{
    private:
        T *a;
        unsigned int len;
    public:
        Array() : a(NULL), len(0){}
        Array(unsigned int n) : len(n)
        {
            try
            {
                a = new T[n];
                for (unsigned int i = 0; i < n ; i++)
                {
                    a[i] = T();
                }       
            }
            catch(const std::exception &e)
            {
                std::cerr << e.what() <<std::endl;
                exit(1);
            }
        }
        Array(const Array &ob) : a(NULL)
        {
            *this = ob;
        }
        Array& operator=(const Array &ob)// operator overloading
        {
            if (this == &ob)
                return (*this);
            if(this->a)
            {
                delete [] this->a;
                this->a = NULL;
            }
            a = new T[ob.len];
            this->len = ob.len;
            return (*this);
        }
        T& operator [](const unsigned int index) const // operator overloading
        {
            if (index > len)
            {
                throw std::out_of_range("index out of range");
            }
            return (a[index]);
        }
        unsigned int size()const{
            return len;
        }
        ~Array(){
            delete[] a;
        }
};


#endif