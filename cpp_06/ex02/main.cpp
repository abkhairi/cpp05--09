/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:12:11 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 18:03:48 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *basePtr = generate();
    std::cout << "basePtr = " << basePtr << std::endl;
    identify(basePtr);
    identify(*basePtr);
    
    delete basePtr;
    return 0;
}
























// int main() {
//     Base* basePtr = new Derived1;  // Pointeur de type Base pointant vers un objet de type Derived1
//     // Utilisation de dynamic_cast pour vérifier si basePtr peut être casté en Derived1*
//     Derived1* d1 = dynamic_cast<Derived1*>(basePtr);
//     if (d1 != nullptr) 
//     {
//         std::cout << "basePtr est un objet de type Derived1" << std::endl;
//         std::cout << "valeur de d1 = " << d1 << std::endl;
//     } 
//     else if (d1 == nullptr)
//     {
//         std::cout << "basePtr n'est pas un objet de type Derived1" << std::endl;
//         std::cout << "valeur de d1 = " << d1 << std::endl;
//     }
//     // Essai de cast vers Derived2*, ce qui devrait échouer
//     Derived2* d2 = dynamic_cast<Derived2*>(basePtr);
//     if (d2 != nullptr) 
//         std::cout << "basePtr est un objet de type Derived2" << std::endl;
//     else 
//         std::cout << "basePtr n'est pas un objet de type Derived2" << std::endl;

//     delete basePtr;
//     return 0;
// }
