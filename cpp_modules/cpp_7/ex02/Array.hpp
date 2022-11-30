#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::string;
using std::endl;
using std::exception;

template< typename T > class Array
{
public:
	Array()
	{
		arr = new T[1];
		arr[0] = NULL;
		len = 0;
	};
	Array( unsigned int n )
	{
		arr = new T[n];
		len = n;
	};
	Array( const Array &cpy )
	{
		*this = cpy;
	}

	struct OutoftoRange : public exception
	{
		const char * what() const throw()
		{
			return "Out of to range!";
		}
	};

	Array& operator = ( const Array &obj )
	{
		if( this == &obj )
			return *this;
		len = obj.len;
		arr = new T[len];
		for ( unsigned int j = 0; j < len ; ++j )
			arr[j] = obj.arr[j];
		return *this;
	}

	T& operator [] ( unsigned int a )
	{
		if( a >= len )
			throw OutoftoRange();
		else
			return arr[a];
	}

	unsigned int size( void )
	{
		return len;
	}

	~Array()
	{
		delete[] arr;
	};
private:
	T* arr;
	unsigned int len;

};

#endif