#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include <iterator>
template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &m)
{
	std::stack<T>::c = m.c;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack &m)
{
	if (this->begin() != m.begin())
		std::stack<T>::c = m.c;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend() const
{
	return (std::stack<T>::begin());
}

#endif
