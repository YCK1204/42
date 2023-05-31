#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <sstream>

class	RPN : public std::stack<double>
{
public:
	RPN();
	RPN(const RPN &r);
	RPN &operator = (const RPN &r);
	~RPN();
	std::size_t	getSize() const;
	double	pop();
	void	push(double v);
};

#endif
