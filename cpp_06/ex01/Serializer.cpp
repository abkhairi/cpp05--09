/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:13:19 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 16:13:20 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

Serializer::Serializer(){}


uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

Serializer &Serializer::operator=(const Serializer& ob)
{
    (void)ob;
    return (*this);
}

Serializer::Serializer(const Serializer& ob)
{
    *this = ob;
}

Serializer::~Serializer(){}
