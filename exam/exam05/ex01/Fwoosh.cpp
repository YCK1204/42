#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	setName("Fwoosh");
	setEffects("fwooshed");
}
Fwoosh::~Fwoosh() {}
ASpell	*Fwoosh::clone() const { return (new Fwoosh(*this)); }
