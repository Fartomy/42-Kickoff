#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../tools/iterators/random_access_iterator.hpp"
#include "../tools/iterators/reverse_iterator.hpp"
#include "../tools/utils/enable_if.hpp"
#include "../tools/utils/is_integral.hpp"
#include "../tools/utils/equal.hpp"
#include "../tools/utils/lexicographical_compare.hpp"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <memory>

// https://cplusplus.com/reference/vector/vector/?kw=vector

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Member Types\-*-*-*-*-*-*-*-*-*-*-*-*-*-

			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef value_type& 												reference;
			typedef const value_type&											const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::random_access_iterator<pointer>							iterator;
			typedef ft::random_access_iterator<const_pointer>					const_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename allocator_type::size_type							size_type;

		private:
			allocator_type		alc;
			size_type			cpt;
			size_type			sz;
			value_type 			*ary;

		public:
			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Iterator Functions\-*-*-*-*-*-*-*-*-*-*-*-*-*-

			iterator begin()
			{
				return ( ary );
			}

			iterator end()
			{
				return ( ary + sz );
			}

			const_iterator cbegin() const
			{
				return ( ary );
			}

			const_iterator cend() const
			{
				return ( ary + sz );
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator( end() );
			}

			reverse_iterator rend()
			{
				return reverse_iterator( begin() );
			}

			const_reverse_iterator crbegin() const
			{
				return ( const_reverse_iterator(end()) );
			}

			const_reverse_iterator crend() const
			{
				return ( const_reverse_iterator(begin()) );
			}
			// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-/VECTOR CONSTRUCTORS\-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

			explicit vector (const allocator_type& alloc = allocator_type()) : alc(alloc), cpt(0), sz(0), ary(NULL) {};
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alc(alloc), cpt(0), sz(0), ary(NULL) { resize(n, val); };
			template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : alc(alloc), cpt(0), sz(0), ary(NULL) { assign(first, last); };
			vector (const vector& x) : alc(x.alc), cpt(x.cpt), sz(x.sz)
			{
				ary = alc.allocate(cpt);
				size_type i = 0;
				while (i < sz)
				{
					alc.construct(&ary[i], x.ary[i]);
					i++;
				}
			};

			~vector()
			{
				clear();
				alc.deallocate(ary, cpt);
			};

			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Assignment Operator\-*-*-*-*-*-*-*-*-*-*-*-*-*-

			vector& operator=(const vector& vcR)
			{
				if(&vcR == this)
				{
					return ( *this );
				}
				for(size_type i = 0; i < sz; i++)
				{
					alc.destroy(&ary[i]);
				}
				sz = vcR.sz;
				cpt = vcR.cpt;
				ary = alc.allocate(cpt);
				for(size_type i = 0; i < sz; i++)
				{
					alc.construct(&ary[i], &vcR.ary[i]);
				}
				return ( *this );
			}

			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Element Access\-*-*-*-*-*-*-*-*-*-*-*-*-*-

			reference operator[](size_type s)
			{
				return ( ary[s] );
			}

			const_reference operator[](size_type s) const
			{
				return ( ary[s] );
			}

			reference at(size_type s)
			{
				if(s >= sz)
				{
					throw std::out_of_range("vector limit");
				}
				return ary[s];
			}

			const_reference at(size_type s) const
			{
				if(s >= sz)
				{
					throw std::out_of_range("vector limit");
				}
				return ary[s];
			}

			reference front()
			{
				return ary[0];
			}

			const_reference front() const
			{
				return ary[0];
			}

			reference back()
			{
				return ary[sz - 1];
			}

			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Capacity\-*-*-*-*-*-*-*-*-*-*-*-*-*-
			bool empty() const
			{
				return ( sz == 0 );
			}

			size_type size() const
			{
				return sz;
			}

			size_type max_size() const
			{
				return alc.max_size();
			}

			size_type capacity() const
			{
				return cpt;
			}

			void reserve(size_type s)
			{
				if(alc.max_size() < s)
				{
					throw std::length_error("reserve length");
				}
				if(cpt < s)
				{
					value_type* ary1 = alc.allocate(s);
					if(ary != 0)
					{
						for(size_type i = 0; i < cpt; i++)
						{
							alc.construct(&ary1[i], ary[i]);
							alc.destroy(&ary[i]);
						}
						alc.deallocate(ary, cpt);
					}
					ary = ary1;
					cpt = s;
				}
			}

			void resize(size_type s, value_type v = value_type())
			{
				if(cpt < s)
				{
					reserve(s);
				}
				if(sz > s)
				{
					for (size_type i = s; i < sz; i++)
					{
						alc.destroy(&ary[i]);
					}
				}
				else
				{
					for (size_type i = sz; i < s; i++)
					{
						alc.construct(&ary[i], v);
					}
				}
				sz = s;
			}

			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Modifiers\-*-*-*-*-*-*-*-*-*-*-*-*-*-
			template <class InputIterator> void assign (InputIterator first, InputIterator last)
			{
				clear();
				for(; first != last; first++)
				{
					push_back(*first);
				}
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
				{
					push_back(val);
				}
			}

			void push_back (const value_type& val)
			{
				if(sz == cpt)
				{
					if(sz > 0)
					{
						reserve(sz * 2);
					}
					if(sz <= 0)
					{
						reserve(1);
					}
				}
				alc.construct(&ary[sz], val);
				sz++;
			}

			void pop_back()
			{
				alc.destroy(&ary[sz - 1]);
				sz--;
			}

			void clear()
			{
				if(ary != 0)
				{
					for (size_type i = 0; i < sz; i++)
					{
						alc.destroy(&ary[i]);
					}
					sz = 0;
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				insert(position, 1, val);
				return position;
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				const size_type idx = position - begin();
				if(sz + n >= cpt)
				{
					if(sz > 0)
						reserve(sz * 2);
					if(sz <= 0)
						reserve(1);
				}
				std::copy_backward(ary + idx, ary + sz, ary + sz + n);
				for (size_type i = idx, count = idx + n; i < count; i++)
					alc.construct(&ary[i], val);
				sz += n;
			}

			template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				using namespace std;
				size_type idx = position - begin();
				size_type s = last - first;

				if(idx > sz)
					resize(idx + s, 0);
				else
					sz += s;
				if(sz >= cpt)
					reserve(sz);
				for (size_type i = (sz - 1) - idx; i < sz; i++)
					ary[i] = ary[i - s];
				for (size_type i = idx, count = idx + s; i < count; i++,first++)
					alc.construct(&ary[i], *first);
			}


			iterator erase (iterator position)
			{
				size_type idx = position - begin();
				alc.destroy(&ary[idx]);
				for(; idx < sz; idx++)
					ary[idx] = ary[idx + 1];
				sz--;
				return position;
			}

			iterator erase (iterator first, iterator last)
			{
				size_type idx = first - begin();
				size_type count = last - first;
				for (size_type i = idx, size = idx + count; i < size; i++)
					alc.destroy(&ary[i]);
				sz -= count;
				for(; idx < sz; idx++)
					ary[idx] = ary[idx + count];
				return first;
			}

			void swap (vector& x)
			{
				value_type* ary1 = x.ary;
				size_type sz1 = x.sz;
				size_type cpt1 = x.cpt;
				x.ary = ary;
				x.cpt = cpt;
				x.sz = sz;
				sz = sz1;
				ary = ary1;
				cpt = cpt1;
			}
	};
	template <class T, class Alloc> bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if(lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin() );
	}
	template <class T, class Alloc> bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
	}
	template <class T, class Alloc> bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}
	template <class T, class Alloc> bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return rhs < lhs;
	}
	template <class T, class Alloc> bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
}


#endif