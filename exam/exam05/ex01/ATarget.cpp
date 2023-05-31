#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(const ATarget &a) { *this = a; }
ATarget &ATarget::operator = (const ATarget &a)
{
	if (this != &a)
		this->type = a.type;
	return (*this);
}
ATarget::ATarget(const std::string &type) { this->type = type; }
ATarget::~ATarget() {}
const std::string	&ATarget::getType() const { return (this->type); }
void	ATarget::setType(const std::string &type) { this->type = type; }
void	ATarget::getHitBySpell(const ASpell &a) const { std::cout << this->type + " has been " + a.getEffects() + "!" << std::endl; }
