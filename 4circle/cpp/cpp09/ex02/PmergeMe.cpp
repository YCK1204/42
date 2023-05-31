#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &p)
{
	*this = p;
}

PmergeMe::PmergeMe(std::list<int> a1, std::deque<int> a2)
{
	for (std::list<int>::const_iterator iter = a1.begin(); iter != a1.end(); iter++)
		this->lst.push_back(*iter);
	for (std::deque<int>::const_iterator iter = a2.begin(); iter != a2.end(); iter++)
		this->deq.push_back(*iter);
}

PmergeMe &PmergeMe::operator = (const PmergeMe &p)
{
	if (this != &p)
	{
		this->lst.clear();
		this->deq.clear();
		for (std::list<int>::const_iterator iter = p.lst.begin(); iter != p.lst.end(); iter++)
			this->lst.push_back(*iter);
		for (std::deque<int>::const_iterator iter = p.deq.begin(); iter != p.deq.end(); iter++)
			this->deq.push_back(*iter);	
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::lstMergeSort(int start, int middle, int end)
{
	int	tmp[end];
	int	i = start, j = middle + 1, k = start;
	int	v1, v2;
	std::list<int>::iterator	it;

	while (i <= middle && j <= end)
	{
		v1 = getValue(i);
		v2 = getValue(j);
		if (v1 <= v2)
		{
			tmp[k++] = v1;
			i++;
		}
		else
		{
			tmp[k++] = v2;
			j++;
		}
	}
	if (i > middle)
		while (j <= end)
			tmp[k++] = getValue(j++);
	else
		while (i <= middle)
			tmp[k++] = getValue(i++);
	for (int t = start; t <= end; t++)
	{
		it = this->lst.begin();
		std::advance(it, t);
		*it = tmp[t];
	}
}

void	PmergeMe::deqMergeSort(int start, int middle, int end)
{
	int	tmp[end];
	int	i = start, j = middle + 1, k = start;

	while (i <= middle && j <= end)
	{
		if (this->deq[i] <= this->deq[j])
			tmp[k++] = this->deq[i++];
		else
			tmp[k++] = this->deq[j++];
	}
	if (i > middle)
		while (j <= end)
			tmp[k++] = this->deq[j++];
	else
		while (i <= middle)
			tmp[k++] = this->deq[i++];
	for (int t = start; t <= end; t++)
		this->deq[t] = tmp[t];
}

void	PmergeMe::lstInsertSort()
{
	std::size_t	size = this->lst.size();
	std::list<int>::iterator	v1, v2;

	for (std::size_t i = 1; i < size; i++)
	{
		for (std::size_t j = i; j > 0; j--)
		{
			v1 = this->lst.begin();
			v2 = this->lst.begin();
			std::advance(v1, j);
			std::advance(v2, j - 1);
			if (*v1 < *v2)
			{
				int	tmp = *v1;
				*v1 = *v2;
				*v2 = tmp;
			}
			else
				break ;
		}
	}
}

void	PmergeMe::deqInsertSort()
{
	std::size_t	size = this->deq.size();

	for (std::size_t i = 1; i < size; i++)
	{
		for (std::size_t j = i; j > 0; j--)
		{
			if (this->deq[j] < this->deq[j - 1])
			{
				int	tmp = this->deq[j];
				this->deq[j] = this->deq[i];
				this->deq[i] = tmp;
			}
			else
				break ;
		}
	}
}

void	PmergeMe::lstSort(int start, int end)
{
	int	middle = (start + end) / 2;

	if (this->lst.size() <= 10)
	{
		lstInsertSort();
		return ;
	}
	else if (start < end)
	{
		lstSort(start, middle);
		lstSort(middle + 1, end);
		lstMergeSort(start, middle, end);
	}
}

void	PmergeMe::deqSort(int start, int end)
{
	int	middle = (start + end) / 2;

	if (this->deq.size() <= 10)
	{
		deqInsertSort();
		return ;
	}
	else if (start < end)
	{
		lstSort(start, middle);
		lstSort(middle + 1, end);
		lstMergeSort(start, middle, end);
	}
}

void	PmergeMe::lstPush(int v)
{
	this->lst.push_back(v);	
}

void	PmergeMe::deqPush(int v)
{
	this->deq.push_back(v);
}

int	PmergeMe::getValue(int idx) const
{
	std::list<int>::const_iterator it = this->lst.begin();
	std::advance(it, idx);
	return (*it);
}

void	PmergeMe::print()
{
	std::cout << "After: ";
	for (std::list<int>::iterator it = this->lst.begin(); it != this->lst.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

const char	*PmergeMe::isntValidSequence::what() const throw()
{
	return ("Error");
}
