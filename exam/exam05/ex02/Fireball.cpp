#include "Fireball.hpp"

Fireball::Fireball()
{
	setName("Fireball");
	setEffects("burnt to a crisp");
}
Fireball::~Fireball() {}
ASpell	*Fireball::clone() const { return (new Fireball(*this)); }
