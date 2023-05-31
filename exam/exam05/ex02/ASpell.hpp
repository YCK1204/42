#ifndef ASPELL_HPP
# define ASPELL_HPP

#include "ATarget.hpp"
#include <iostream>
#include <string>

class ATarget;

class ASpell
{
private:
	std::string name;
	std::string effects;
public:
	ASpell();
	ASpell(const std::string &name, const std::string &effects);
	ASpell(const ASpell &a);
	ASpell &operator = (const ASpell &a);
	virtual ~ASpell();
	const std::string	&getName() const;
	const std::string	&getEffects() const;
	void	setName(const std::string &name);
	void	setEffects(const std::string &effects);
	virtual ASpell	*clone() const = 0;
	void	launch(const ATarget &a) const;
};

#endif
