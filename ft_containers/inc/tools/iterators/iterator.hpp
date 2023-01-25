#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include <stddef.h>
#include <iostream>

namespace ft
{
	template<typename Iter>	struct iterator_traits
	{
	public:
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template<typename T> struct iterator_traits<T*>
	{
	public:
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template<typename T> struct iterator_traits<const T*>
	{
	public:
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct bidirectional_iterator_tag : public std::forward_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
}

#endif