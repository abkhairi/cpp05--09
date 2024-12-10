/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:13:11 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 16:13:12 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

int main()
{
	Data ptr;

	ptr.a = 42;
	ptr.b = 13.37;
	ptr.str = "login";
	uintptr_t var = Serializer::serialize(&ptr);
	Data *data = Serializer::deserialize(var);
	std::cout << data->a << "\n";
	std::cout << data->b << "\n";
	std::cout << data->str << "\n";
}

// int main()
// {
//     Data *ptr = new Data;
//     ptr->a = 13;
//     ptr->b = 42.17f;
//     ptr->str = "abkhairi";

//     // std::cout << "ptr = " << ptr << std::endl;
//     uintptr_t c = Serializer::serialize(ptr); // convert addres the struct en number decimal
//     // int *ptr_a = reinterpret_cast<int* >(c);
//     // float *ptr_b = reinterpret_cast<float*>(reinterpret_cast<char *>(c) + sizeof(int)); // indiquer the complier incremnt by 1 the addres 
//     // std::cout << " valeur a = " << *ptr_a << "\n valeur b = " << (*ptr_b)<< std::endl;

//     Data *ptr2 = Serializer::deserialize(c);
//     std::cout << "ptr  = " << ptr2->a <<std::endl;
//     std::cout << "ptr  = " << ptr2->b <<std::endl;
//     std::cout << "ptr  = " << ptr2->str <<std::endl;

//     delete ptr;
// }