#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template<typename Iterator> class reverse_iterator
	{
		public:
			typedef Iterator iterType;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer 			pointer;
			typedef typename iterator_traits<Iterator>::reference 			reference;
			typedef typename iterator_traits<Iterator>::iterator_category 	iterator_category;

			reverse_iterator() : ptr(NULL) {};
			explicit reverse_iterator(iterType ptr) : ptr(ptr) {};
			template<typename It> reverse_iterator(reverse_iterator<It> const &reverse_itr) : ptr(reverse_itr.ptr) {}

			reverse_iterator& operator=(const reverse_iterator<Iterator> &reverse_itr)
			{
				if(this != &reverse_itr)
				{
					this->ptr = reverse_itr.ptr;
				}
				return ( *this );
			}

			reference operator*() const
			{
				iterType itr = ptr;
				return ( *--itr );
			}

			reference operator[](difference_type p) const
			{
				return *(*this + p);
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			reverse_iterator& operator++()
			{
				--ptr;
				return ( *this );
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator itr(*this);
				--ptr;
				return itr;
			}

			reverse_iterator operator+(difference_type p) const
			{
				return reverse_iterator(ptr - p);
			}

			reverse_iterator& operator+=(difference_type p)
			{
				ptr -= p;
				return ( *this );
			}

			reverse_iterator& operator--()
			{
				++ptr;
				return ( *this );
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator itr( *this );
				++ptr;
				return itr;
			}

			reverse_iterator operator-(difference_type p) const
			{
				return reverse_iterator(ptr + p);
			}

			reverse_iterator& operator-=(difference_type p)
			{
				ptr += p;
				return ( *this );
			}

			template <typename Itr1, typename Itr2> friend bool operator!=(const reverse_iterator<Itr1>& lftSd, const reverse_iterator<Itr2>& rghtSd)
			{
				return !(lftSd.ptr == rghtSd.ptr);
			}

			template <typename Itr1, typename Itr2> friend bool operator==(const reverse_iterator<Itr1>& lftSd, const reverse_iterator<Itr2>& rghtSd)
			{
				return ( lftSd.ptr == rghtSd.ptr );
			}

			template <typename Itr1, typename Itr2> friend bool operator<(const reverse_iterator<Itr1>& lftSd, const reverse_iterator<Itr2>& rghtSd)
			{
				return ( lftSd.ptr > rghtSd.ptr );
			}

			template <typename Itr1, typename Itr2> friend bool operator<=(const reverse_iterator<Itr1>& lftSd, const reverse_iterator<Itr2>& rghtSd)
			{
				return ( lftSd.ptr >= rghtSd.ptr);
			}

			template <typename Itr1, typename Itr2> friend bool operator>(const reverse_iterator<Itr1>& lftSd, const reverse_iterator<Itr2>& rghtSd)
			{
				return ( lftSd.ptr < rghtSd.ptr);
			}

			template <typename Itr1, typename Itr2> friend bool operator>=(const reverse_iterator<Itr1>& lftSd, const reverse_iterator<Itr2>& rghtSd)
			{
				return ( lftSd.ptr <= rghtSd.ptr );
			}

	private:
		iterType ptr;
	};
};

#endif