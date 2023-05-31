/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:45:22 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 15:17:21 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*b;
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &c);
	Cat &operator = (const Cat &c);
	~Cat();
	void	makeSound() const;
	Brain	*getBrain() const;
	std::string	getBrain(int idx) const;
};

#endif
