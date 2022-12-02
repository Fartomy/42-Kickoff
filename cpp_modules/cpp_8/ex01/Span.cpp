#include "Span.hpp"

Span::Span()
{
	len = 0;
};

Span::Span( unsigned int N )
{
	vc.reserve( N );
	len = N;
};

Span::Span( const Span &cpy )
{
	*this = cpy;
};

Span& Span::operator = ( const Span &obj )
{
	this->vc = obj.vc;
	this->len = obj.len;

	return *this;
}

Span::~Span(){};

const char * Span::StorageIsFull::what() const throw()
{
	return "Storage is Full!";
}

const char * Span::NotFoundOrHaveaOne::what() const throw()
{
	return "Not Found or Have a One Element!";
}

void Span::addNumber( int nb )
{
	if( vc.size() == len )
		throw StorageIsFull();
	vc.push_back( nb );
}

int Span::shortestSpan( void )
{
	if( vc.size() <= 1 )
		throw NotFoundOrHaveaOne();
	sort( vc.begin(), vc.end() );
	std::vector<int> ltl;
	std::vector<int>::iterator itr;
	std::vector<int>::iterator bftr;
	for ( unsigned long j = 1; j < vc.size(); ++j )
	{
		bftr = vc.end() - j;
		for ( itr = vc.begin(); itr < vc.end() - j; ++itr )
			ltl.push_back( *bftr - *itr );
	}
	sort( ltl.begin(), ltl.end() );
	itr = ltl.begin();

	return *itr;
}

int Span::longestSpan( void )
{
	if ( vc.size() <= 1 )
		throw NotFoundOrHaveaOne();
	sort( vc.begin(), vc.end() );
	std::vector<int>::iterator itr;
	std::vector<int>::iterator itr2;

	itr = vc.end() - 1;
	itr2 = vc.begin();
	return ( *itr - *itr2 );

}