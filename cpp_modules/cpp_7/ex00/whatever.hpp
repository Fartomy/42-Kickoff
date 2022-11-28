#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T> void swap( T& a, T& b );
template <typename T> T& min( T& a, T& b );
template<typename T> T& max( T& a, T& b );

#endif