/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:12:17 by abkhairi          #+#    #+#             */
/*   Updated: 2024/08/25 18:02:37 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

Base *generate(void) //qui crée aléatoirement une instance de l'une des classes A ou B ou C et la retourne sous forme de pointeur de type Base
{
    srand(time(0)); // func initialise le générateur de nombres aléatoires en C++. 
                    // time(0) : Cette fonction renvoie l'heure actuelle exprimée en secondes depuis le 1er janvier 1970
                    // Sans cette initialisation srand(), les nombres générés par rand() seraient les mêmes à chaque exécution du programme
    int random = rand() % 3; // random = 0 or 1 or 2

    if (random == 0)
        return (new A);
    else if (random == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p) //le type réel de l'objet pointé (c'est-à-dire "A", "B" ou "C").
{
    //convertir p en un pointeur de type A*. Si p pointe effectivement vers un objet de type A , cette conversion réussit et renvoie un pointeur valide de type A*. Si la conversion échoue, dynamic_cast renvoie un pointeur nul (nullptr).
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "type is : A\n";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "type is : B\n";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "type is : C\n";
    else
        std::cout << "bad_cast \n";
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "type is : A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "type is : B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "type is : C\n";
				
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << ": No one was the actual type of p(reference)"<< '\n';
			}
		}
	}
}


//Si dynamic_cast<A*>(p) renvoie un pointeur non nul, cela signifie que p pointe vers un objet de type A. La fonction imprime alors "A\n".