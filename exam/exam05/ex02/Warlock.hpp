#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class ATarget;
class ASpell;
class SpellBook;

class Warlock
{
private:
	std::string	name;
	std::string	title;
	Warlock();
	Warlock(const Warlock &w);
	Warlock &operator = (const Warlock &w);
	SpellBook	book;
public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();
	const std::string	&getName() const;
	const std::string	&getTitle() const;
	void	setTitle(const std::string &title);
	void	introduce() const;
	void	learnSpell(ASpell *a);
	void	forgetSpell(const std::string &str);
	void	launchSpell(const std::string &str, ATarget &a);
};

#endif
