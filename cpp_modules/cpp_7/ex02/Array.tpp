#include "Array.hpp"

template<typename T> Array<T>::Array()
{
	arr = new T[1];
	arr[0] = NULL;
	len = 0;
};

template<typename T> Array<T>::Array( unsigned int n )
{
	arr = new T[n];
	len = n;
};

template<typename T> Array<T>::Array( const Array<T> &cpy )
{
	*this = cpy;
};

template<typename T> Array<T>::~Array()
{
	delete[] arr;
}

template<typename T> Array<T>& Array<T>::operator = ( const Array<T> &obj )
{
	if( this == &obj )
		return *this;
	else
	{
		int i = -1;
		len = obj.len;
		arr = new T[len];
		while ( ++i < len)
			arr[i] = obj[i];
		return *this;
	}
	return NULL;
}

template<typename T> T& Array<T>::operator [] ( int a )
{
	if( a < 0 || a > len )
		throw OutoftoRange();
	else
		return arr[a];
}

template<typename T> unsigned int Array<T>::size( void )
{
	return len;
}

template <typename T> const char * Array<T>::OutoftoRange::what() const throw()
{
	return "Out of to range!";
}