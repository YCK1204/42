#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "ASpell.hpp"

class ASpell;

class SpellBook
{
private:
	SpellBook(const SpellBook &s);
	SpellBook &operator = (const SpellBook &s);
	std::vector<std::pair<std::string, ASpell *> > arr;
public:
	SpellBook();
	~SpellBook();
	void	learnSpell(ASpell *a);
	void	forgetSpell(std::string const &str);
	ASpell	*createSpell(std::string const &str);
	std::vector<std::pair<std::string, ASpell *> >::iterator	begin();
	std::vector<std::pair<std::string, ASpell *> >::iterator	end();
};

#endif
