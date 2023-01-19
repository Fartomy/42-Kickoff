#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../tools/random_access_iterator.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/utils/enable_if.hpp"
#include "../tools/utils/is_integral.hpp"
#include "../tools/utils/equal.hpp"
#include "../tools/utils/lexicographical_compare.hpp"
#include <cstring>
#include <stdexcept>
#include <memory>

// https://cplusplus.com/reference/vector/vector/?kw=vector

namespace ft
{
	template < class T, class Alloc = allocator<T> > class vector
	{
		public:
			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Member Types\-*-*-*-*-*-*-*-*-*-*-*-*-*-
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef ft::random_access_iterator<pointer> iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef ft::random_access_iterator<const_pointer> const_iterator;
			typedef typename allocator_type::size_type size_type;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

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
			// -*-*-*-*-*-*-*-*-*-*-*-*-*-/Vector Constructors\-*-*-*-*-*-*-*-*-*-*-*-*-*-
			explicit vector (const allocator_type& alloc = allocator_type()) : ary(0), sz(0), cpt(0), alc(alloc)
			{};
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : ary(0), sz(0), cpt(0), alc(alloc)
			{
				resize(n, val);
			};
			template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : ary(0), sz(0), cpt(0), alc(alloc)
			{
				assign(first, last);
			};
			vector (const vector& x)
			{
				alc = x.alc;
				cpt = x.cpt;
				sz = x.sz;
				ary = alc.allocate(cpt);
				unsigned int i = 0;
				while (i < sz)
				{
					alc.construct(&ary[i], x.ary[i])
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
					throw std::out_of_range("vectorLimit");
				}
				return ary[s];
			}
			const_reference at(size_type s) const
			{
				if(s >= sz)
				{
					throw std::out_of_range("vectorLimit");
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
			const_reference front() const
			{
				return ary[sz - 1];
			}
			/*
			pointer data()
			{
				return ptr;
			}
			const_pointer data() const
			{
				return ptr;
			}
			*/
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
					reserve(2);
				}
				if(sz < 0)
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
			const size_type idx = position - begin();
			insert(position, 1, val);
			return position;
		}
		// insert'ler bitmedi!!!
		private:
			allocator_type		alc;
			size_type			cpt;
			size_type			sz;
			//pointer			ptr;
			value_type 			*ary;

	};
}


#endif