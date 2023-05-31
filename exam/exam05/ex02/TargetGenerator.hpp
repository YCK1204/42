#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <vector>
#include <iterator>

class ATarget;

class TargetGenerator
{
private:
	TargetGenerator(const TargetGenerator &t);
	TargetGenerator &operator = (const TargetGenerator &t);
	std::vector<std::pair<std::string, ATarget *> > arr;
public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *a);
	void forgetTargetType(std::string const &str);
	ATarget* createTarget(std::string const &str);
	std::vector<std::pair<std::string, ATarget *> >::iterator	begin();
	std::vector<std::pair<std::string, ATarget *> >::iterator	end();
};

#endif
