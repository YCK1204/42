#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook &s) { *this = s; }
SpellBook &SpellBook::operator = (const SpellBook &s)
{
	if (this != &s)
	{
		for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
			delete it->second;
		this->arr = s.arr;
	}
	return (*this);
}
SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
	for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
		delete it->second;
}
void	SpellBook::learnSpell(ASpell *a) { this->arr.push_back(std::make_pair(a->getName(), a->clone()); }
void	SpellBook::forgetSpell(std::string const &str)
{
	for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->arr.begin(); it != this->arr.end();)
	{
		if (!it->first.compare(str))
		{
			delete it->second;
			it = this->arr.erase(it);
		}
		else
			it++;
	}
}

ASpell	*SpellBook::createSpell(std::string const &str)
{
	for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
		if (!it->first.compare(str))
			return (it->second);
	return (NULL);
}

std::vector<std::pair<std::string, ASpell *> >::iterator	SpellBook::begin() { return (this->arr.begin()); }
std::vector<std::pair<std::string, ASpell *> >::iterator	SpellBook::end() { return (this->arr.end()); }
