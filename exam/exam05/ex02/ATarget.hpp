#ifndef ATARGET_HPP
# define ATARGET_HPP

#include "ASpell.hpp"
#include <iostream>
#include <string>

class ASpell;

class ATarget
{
private:
	std::string type;
public:
	ATarget();
	ATarget(const ATarget &a);
	ATarget &operator = (const ATarget &a);
	ATarget(const std::string &type);
	virtual ~ATarget();
	const std::string	&getType() const;
	void	setType(const std::string &type);
	virtual ATarget	*clone() const = 0;
	void	getHitBySpell(const ASpell &a) const;
};

#endif
