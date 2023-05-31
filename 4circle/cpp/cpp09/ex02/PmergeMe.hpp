#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <iomanip>
#include <list>
#include <deque>
#include <iterator>
#include <cstdlib>
#include <iterator>

class	PmergeMe
{
private:
	std::list<int>	lst;
	std::deque<int>	deq;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &p);
	PmergeMe(std::list<int> a1, std::deque<int> a2);
	PmergeMe &operator = (const PmergeMe &p);
	~PmergeMe();
	void	lstMergeSort(int start, int middle, int end);
	void	deqMergeSort(int start, int middle, int end);
	void	lstInsertSort();
	void	deqInsertSort();
	void	lstSort(int start, int end);
	void	deqSort(int start, int end);
	int		getValue(int idx) const;
	void	lstPush(int v);
	void	deqPush(int v);
	void	print();
	class	isntValidSequence : public std::exception
	{
		const char *what() const throw();
	};
};

#endif
