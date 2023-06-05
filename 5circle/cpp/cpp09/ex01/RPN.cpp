#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &r)
{
	*this = r;
}

RPN &RPN::operator = (const RPN &r)
{
	if (this != &r)
		std::stack<double>::operator=(r);
	return (*this);
}

RPN::~RPN() {}

std::size_t	RPN::getSize() const
{
	return (std::stack<double>::size());
}

double	RPN::pop()
{
	double	ret = std::stack<double>::top();
	std::stack<double>::pop();
	return (ret);
}

void	RPN::push(double v)
{
	std::stack<double>::push(v);
}
