#include "TypeCast.hpp"

static bool is_double_handler( char *ch )
{
	int dot_cnt = 0;
	int i = 0;
	long double ldb;
	string st = ch;

	ldb = (long double)stold( st, 0);
	if( ldb > DBL_MAX || ldb < DBL_MIN )
		return true;
	while( ch[i] )
	{
		if( ch[i] == '.' )
			dot_cnt++;
		i++;
	}
	if( dot_cnt > 1 )
		return true;
	i = -1;
	while ( ch[++i] )
	{
		if( ( ch[i] == '.' && ch[i + 1] == '.' ) || ( ch[i] == '.' && ch[i + 1] == '.' ) )
			return true;
	}
	return false;
}

static bool is_float_handler( char *ch )
{
	int dot_cnt = 0;
	int f_cnt = 0;
	int i = 0;
	double db;
	string st = ch;

	db = (double) stod( st, 0);
	if( db > FLT_MAX || db < FLT_MIN )
		return true;
	while( ch[i] )
	{
		if( ch[i] == '.' )
			dot_cnt++;
		else if( ch[i] == 'f' )
			f_cnt++;
		i++;
	}
	if( dot_cnt > 1 )
		return true;
	else if( f_cnt > 1 )
		return true;
	i = -1;
	while ( ch[++i] )
	{
		if( ( ch[i] == '.' && ch[i + 1] == 'f' ) || ( ch[i] == 'f' && ch[i + 1] == '.' ) )
			return true;
	}
	return false;
}

bool is_float( char *ch )
{
	int i = 0;

	if( ch[0] == '.' || ch[0] == 'f' )
		return false;
	else if( is_float_handler( ch ) )
		return false;
	while( ch[i] )
	{
		if ( isdigit(ch[i]) || ( ch[i] == '.' || ch[i] == 'f' ) )
			i++;
		else
			return false;
	}
	return true;
}

bool is_int( char *ch )
{
	int i = 0;
	while( ch[i] )
	{
		if( isdigit( ch[i] ) )
			i++;
		else
			return false;
	}
	return true;
}

bool is_double( char *ch )
{
	int i = 0;

	if( ch[0] == '.' )
		return false;
	else if( is_double_handler( ch ) )
		return false;
	while( ch[i] )
	{
		if ( isdigit(ch[i]) ||  ch[i] == '.' )
			i++;
		else
			return false;
	}
	return true;
}

int which_type( char *ch )
{
	string str = ch;

	if ( str.length() == 1 && !isdigit(str[0]) )
		return 1;
	else if( is_int( ch ) )
		return 2;
	else if( is_float( ch ) )
		return 3;
	else if( is_double( ch ) )
		return 4;
	else if( str == "nan" )
		return 5;
	else
		return 0;
}

/*#include <iostream>

using namespace std;

int main()
{
	string s = "123.0f";

	float xd = stof(s, 0);

	cout << xd << endl;
	return 0;
}*/
