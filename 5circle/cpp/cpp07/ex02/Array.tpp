#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() 
{
	this->len = 0;
	this->arr = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::Array(const Array &a)
{
	this->arr = NULL;
	*this = a;
}

template <typename T>
Array<T> &Array<T>::operator = (const Array &a)
{
	if (this != &a)
	{
		this->len = a.len;
		if (this->arr)
			delete [] this->arr;
		this->arr = new T[this->len];
		for (std::size_t i = 0; i < this->len; i++)
			this->arr[i] = a.arr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->arr)
		delete [] this->arr;
}

template <typename T>
const char *Array<T>::outOfRangeException::what() const throw()
{
	return ("Error : out of range");
}

template <typename T>
T &Array<T>::operator[] (int idx)
{
	if (idx < 0 || static_cast<unsigned int>(idx) >= this->len)
		throw outOfRangeException();
	return (this->arr[idx]);
}

template <typename T>
std::size_t	Array<T>::size() const
{
	return (this->len);
}

#endif
