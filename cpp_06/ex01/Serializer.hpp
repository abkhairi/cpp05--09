/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:13:24 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 16:13:25 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
    public:
        int a;
        float b;
        std::string str;
};

class Serializer{
    // Constructeur privé pour empêcher l'initialisation
    private :
        Serializer();
        Serializer(const Serializer& ob);
        Serializer &operator=(const Serializer& ob);
        ~Serializer();
    public :
    // Méthode pour sérialiser un pointeur en uintptr_t
        static uintptr_t serialize(Data* ptr);
    // Méthode pour désérialiser un uintptr_t en pointeur
        static Data* deserialize(uintptr_t raw);
};


#endif
