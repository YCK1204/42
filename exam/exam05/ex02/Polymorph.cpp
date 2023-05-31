#include "Polymorph.hpp"

Polymorph::Polymorph()
{
	setName("Polymorph");
	setEffects("turned into a critter");
}
Polymorph::~Polymorph() {}
ASpell	*Polymorph::clone() const { return (new Polymorph(*this)); }
