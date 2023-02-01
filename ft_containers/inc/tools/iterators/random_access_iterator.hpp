#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template<typename Iterator> class random_access_iterator
	{
		public:
			typedef Iterator iterType;
			typedef typename iterator_traits<iterType>::value_type			value_type;
			typedef typename iterator_traits<iterType>::pointer 			pointer;
			typedef typename iterator_traits<iterType>::reference 			reference;
			typedef typename iterator_traits<iterType>::difference_type		difference_type;
			typedef typename iterator_traits<iterType>::iterator_category 	iterator_category;

			random_access_iterator() : ptr(0) {};
			random_access_iterator(iterType ptr) : ptr(ptr) {};
            template<class Iter>
			random_access_iterator(const random_access_iterator<Iter>& c) : ptr(&(*c)) {};
			~random_access_iterator() {};

			random_access_iterator& operator=(const random_access_iterator& c)
			{
				if (this != &c)
				{
					this->ptr = c.ptr;
				}
				return (*this);
			}

			reference operator*() const { return ( *ptr ); }
			reference operator[](difference_type p) const { return ( ptr[p] ); }
			pointer operator->() const { return &( operator*() ); }

			random_access_iterator& operator++()
			{
				++ptr;
				return ( *this );
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator itr(*this);
				++(*this);
				return ( itr );
			}

			random_access_iterator operator+(const difference_type& p) const
			{
				random_access_iterator itr(*this);
				return ( itr.ptr + p );
			}

			random_access_iterator& operator+=(const difference_type& p)
			{
				ptr += p;
				return ( *this );
			}

			random_access_iterator& operator--()
			{
				--ptr;
				return ( *this );
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator itr(*this);
				--(*this);
				return itr;
			}

			random_access_iterator operator-(const difference_type& p) const { return ( *this + (-p) ); }

			random_access_iterator& operator-=(const difference_type& p)
			{
				ptr -= p;
				return ( *this );
			}

			template<typename Itr1, typename Itr2> friend bool operator!=(const random_access_iterator<Itr1>& lftSd, const random_access_iterator<Itr2>& rghtSd) { return !( lftSd.ptr == rghtSd.ptr ); }
			template<typename Itr1, typename Itr2> friend bool operator==(const random_access_iterator<Itr1>& lftSd, const random_access_iterator<Itr2>& rghtSd) { return ( lftSd.ptr == rghtSd.ptr ); }
			template<typename Itr1, typename Itr2> friend bool operator<(const random_access_iterator<Itr1>& lftSd, const random_access_iterator<Itr2>& rghtSd) { return ( lftSd.ptr < rghtSd.ptr ); }
			template<typename Itr1, typename Itr2> friend bool operator<=(const random_access_iterator<Itr1>& lftSd, const random_access_iterator<Itr2>& rghtSd) { return ( lftSd.ptr <= rghtSd.ptr ); }
			template<typename Itr1, typename Itr2> friend bool operator>(const random_access_iterator<Itr1>& lftSd, const random_access_iterator<Itr2>& rghtSd) { return ( lftSd.ptr > rghtSd.ptr ); }
			template<typename Itr1, typename Itr2> friend bool operator>=(const random_access_iterator<Itr1>& lftSd, const random_access_iterator<Itr2>& rghtSd) { return ( lftSd.ptr >= rghtSd.ptr ); }
			template<typename Itr1, typename Itr2> friend typename random_access_iterator<Itr1>::difference_type operator-(const random_access_iterator<Itr1>& lftSd, const random_access_iterator<Itr2>& rghtSd) { return lftSd.ptr - rghtSd.ptr; }
			template<typename Itr> friend random_access_iterator<Itr> operator+(typename random_access_iterator<Itr>::difference_type d, random_access_iterator<Itr>& c )
			{
				c += d;
				return ( c );
			}

		private:
			iterType ptr;
	};
}

#endif

