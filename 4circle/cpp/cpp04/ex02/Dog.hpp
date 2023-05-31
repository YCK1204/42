/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:51:30 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 15:17:32 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*b;
public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &d);
	Dog &operator = (const Dog &d);
	~Dog();
	void	makeSound() const;
	Brain	*getBrain() const;
	std::string	getBrain(int idx) const;
};

#endif
