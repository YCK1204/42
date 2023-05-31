#include "Warlock.hpp"

Warlock::Warlock() {}
Warlock::Warlock(const Warlock &w) { *this = w; }
Warlock &Warlock::operator = (const Warlock &w)
{
	if (this != &w)
	{
		this->name = w.name;
		this->title = w.title;
		for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
			delete it->second;
		this->arr = w.arr;
	}
	return (*this);
}
Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name + ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << this->name + ": My job here is done!" << std::endl;
	for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
		delete it->second;
}
const std::string	&Warlock::getName() const { return (this->name); }
const std::string	&Warlock::getTitle() const { return (this->title); }
void	Warlock::setTitle(const std::string &title) { this->title = title; }
void	Warlock::introduce() const { std::cout << this->name + ": I am " + this->name + ", " + this->title + "!" << std::endl; }
void	Warlock::learnSpell(ASpell *a)
{
	if (a)
		this->arr.push_back(std::make_pair(a->getName(), a));
}
void	Warlock::forgetSpell(const std::string &str)
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
void	Warlock::launchSpell(const std::string &str, ATarget &a)
{
	for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
		if (!it->first.compare(str))
			it->second->launch(a);
}
