/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:06:32 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/28 14:09:35 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

int main()
{
    try
    {
        Array<int> objInt(5);
        for (int i = 0; i < 5; i++)
        {
            objInt[i] = int(i);
            std::cout << "obj[" << i << "] = " << objInt[i] << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        Array<std::string> objInt(5);
        for (int i = 0; i < 5; i++)
        {
            objInt[i] = "abkhairi";
            std::cout << "obj[" << i << "] = " << objInt[i] << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

	return 0;
}


















// #define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << "1 \n";
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << "2 \n";
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }