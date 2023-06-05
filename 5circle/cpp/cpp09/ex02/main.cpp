#include "PmergeMe.hpp"

bool	isValidSequence(char *num)
{
	int	i = 0;
	int	n = 0;
	if (num[i] == '-')
		return (false);
	else if (num[i] == '+')
		i++;
	while (num[i])
	{
		if (!('0' <= num[i] && num[i] <= '9') || n < 0)
			return (false);
		n *= 10;
		n += num[i++] - '0';
	}
	if (n < 0)
		return (false);
	return (true);
}

int	main(int ac, char *av[])
{
	PmergeMe	data;
	std::clock_t start;
	std::clock_t end;
	double		ret, retret, ret1, ret1ret1;
	int			result = 0;
	int			v;

	try
	{
		if (ac == 1)
			throw PmergeMe::isntValidSequence();
		else
		{
			for (int i = 1; av[i]; i++)
				if (!isValidSequence(av[i]))
					throw PmergeMe::isntValidSequence();
			std::cout << "Before: ";
			start = std::clock();
			for (int i = 1; av[i]; i++)
			{
				v = std::atoi(av[i]);
				data.lstPush(v);
			}
			end = std::clock();
			retret = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
			start = std::clock();
			for (int i = 1; av[i]; i++)
			{
				v = std::atoi(av[i]);
				data.deqPush(v);
			}
			end = std::clock();
			ret1ret1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
			for (int i = 1; av[i]; i++)
				std::cout << " " << av[i];
			std::cout << std::endl;
			start = std::clock();
			data.lstSort(0, ac - 1);
			end = std::clock();
			ret = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
			start = std::clock();
			data.deqSort(0, ac - 1);
			end = std::clock();
			ret1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
			data.print();
			std::cout << "Time to process a range of " << std::setw(3) << ac - 1 << " elements with std::[list] : " << ret << " us, " << retret << " us" << std::endl;
			std::cout << "Time to process a range of " << std::setw(3) << ac - 1 << " elements with std::[deque] : " << ret1 << " us, " << ret1ret1 << " us" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		result = 1;
	}
	return (result);
}
