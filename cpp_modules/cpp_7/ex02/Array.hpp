#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::string;
using std::endl;

template< typename T > class Array
{
public:
	Array();
	Array( unsigned int n );
	Array( const Array<T> &cpy );

	Array& operator = ( const Array<T> &obj );
	T& operator [] ( int a );

	unsigned int size( void );

	~Array();
private:
	T* arr;
	size_t len;

};

#endif