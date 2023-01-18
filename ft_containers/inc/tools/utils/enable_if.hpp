#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{
	template <bool Cond, class T = void> struct enable_if
	{};
	template<class T> struct enable_if<true, T>
	{
		typedef T type;
	};
};

// https://cplusplus.com/reference/type_traits/enable_if/

#endif