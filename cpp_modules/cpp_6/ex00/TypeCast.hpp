#ifndef TYPECAST_HPP
#define TYPECAST_HPP

#include <iostream>
#include <limits.h>
#include <float.h>

using std::cout;
using std::endl;
using std::string;
using std::stof;
using std::stod;
using std::stoi;
using std::stold;
using std::exception;
using std::cerr;

class TypeCast
{
public:
	TypeCast();
	TypeCast( const TypeCast &cpy );

	struct ErrorHandle : public exception
	{
		const char * what() const throw();
	};

	TypeCast& operator = ( const TypeCast &obj );
	~TypeCast();
	void display( int a, char *ch );

private:
	string type;
};

int which_type( char *ch );
bool is_double( char *ch );
bool is_float( char *ch );
bool is_int( char *ch );

#endif