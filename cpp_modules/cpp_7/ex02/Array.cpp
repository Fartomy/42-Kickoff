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

template<typename T> Array<T> &Array<T>::operator = ( const Array<T> &obj )
{
	if(  )
}

template<typename T> unsigned int Array<T>::size( void )
{
	return len;
}