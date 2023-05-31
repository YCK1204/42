#include "Warlock.hpp"

Warlock::Warlock() {}
	
Warlock::Warlock(const Warlock &w) { *this = w; }
Warlock &Warlock::operator = (const Warlock &w)
{
	if (this != &w)
	{
		this->name = w.name;
		this->title = w.title;
		for (std::vector<std::pair<std::string, ASpell *> >::iterator it = this->book.begin(); it != this->book.end(); it++)
			this->book.learnSpell(it->second);
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
}
const std::string	&Warlock::getName() const { return (this->name); }
const std::string	&Warlock::getTitle() const { return (this->title); }
void	Warlock::setTitle(const std::string &title) { this->title = title; }
void	Warlock::introduce() const { std::cout << this->name + ": I am " + this->name + ", " + this->title + "!" << std::endl; }
void	Warlock::learnSpell(ASpell *a)
{
	if (a)
		this->book.learnSpell(a);
}
void	Warlock::forgetSpell(const std::string &str)
{
	this->book.forgetSpell(str);
}
void	Warlock::launchSpell(const std::string &str, ATarget &a)
{
	ASpell	*tmp = this->book.createSpell(str);

	if (tmp)
		tmp->launch(a);
}
