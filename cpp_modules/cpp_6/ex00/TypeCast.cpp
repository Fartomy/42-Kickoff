#include "TypeCast.hpp"

TypeCast::TypeCast() : type("who"){};

TypeCast::~TypeCast(){};

TypeCast::TypeCast( const TypeCast &cpy )
{
	cout << "Copy constructor called" << endl;
	*this = cpy;
}

TypeCast& TypeCast::operator = ( const TypeCast &obj )
{
	cout << "Assigment operator overload called" << endl;
	this->type = obj.type;
	return ( *this );
}

const char * TypeCast::ErrorHandle::what() const throw()
{
	return "False Argument!";
}

void TypeCast::display( int a, char *ch )
{
	string str = ch;
	char b;

	switch ( a )
	{
		case 1 :
			cout << "char: " << "'" << str << "'" << endl;
			cout << "int: " << (int)str[0] << endl;
			cout << "float: " << (float)str[0] << ".0f" << endl;
			cout << "double: " << (double)str[0] << ".0" << endl;
			break;
		case 2 :
			b = ( char )stoi( str, 0 ,10 );
			if( isprint( b ) )
				cout << "char: " << "'" << b << "'" << endl;
			else
				cout << "char: Non displayable" << endl;
			cout << "int: " << stoi( str, 0, 10 ) << endl;
			cout << "float: " << stof( str, 0 ) << ".0f" << endl;
			cout << "double: " << stod( str, 0 ) << ".0" << endl;
			break;
		case 3 :
			b = ( char )stoi( str, 0 );
			cout << "char: " << "'" << b << "'" << endl;
			cout << "int: " << stoi( str, 0, 10 ) << endl;
			cout << "float: " << stof( str, 0 ) << "f" << endl;
			cout << "double: " << stod( str, 0 ) << endl;
		case 4 :
			b = ( char )stoi( str, 0 );
			cout << "char: " << "'" << b << "'" << endl;
			cout << "int: " << stoi( str, 0, 10 ) << endl;
			cout << "float: " << stof( str, 0 ) << "f" << endl;
			cout << "double: " << stod( str, 0 ) << endl;
		case 5 :
			cout << "char: impossible" << endl;
			cout << "int: impossible" << endl;
			cout << "float: nanf" << endl;
			cout << "double: nan" << endl;
		case 0:
			throw ErrorHandle();
			break;
	}
}