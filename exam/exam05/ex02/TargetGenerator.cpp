#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator &t) { *this = t; }
TargetGenerator &TargetGenerator::operator = (const TargetGenerator &t)
{
	if (this != &t)
	{
		for (std::vector<std::pair<std::string, ATarget *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
			delete it->second;
		this->arr = t.arr;
	}
	return (*this);
}
TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator()
{
	for (std::vector<std::pair<std::string, ATarget *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
		delete it->second;
}
void TargetGenerator::learnTargetType(ATarget *a)
{
	if (a)
		this->arr.push_back(std::make_pair(a->getType(), a->clone()));
}
void TargetGenerator::forgetTargetType(std::string const &str)
{
	for (std::vector<std::pair<std::string, ATarget *> >::iterator it = this->arr.begin(); it != this->arr.end();)
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
ATarget* TargetGenerator::createTarget(std::string const &str)
{
	for (std::vector<std::pair<std::string, ATarget *> >::iterator it = this->arr.begin(); it != this->arr.end(); it++)
		if (!it->first.compare(str))
			return (it->second);
	return (NULL);
}
std::vector<std::pair<std::string, ATarget *> >::iterator	TargetGenerator::begin() { return (this->arr.begin()); }
std::vector<std::pair<std::string, ATarget *> >::iterator	TargetGenerator::end() { return (this->arr.end()); }
