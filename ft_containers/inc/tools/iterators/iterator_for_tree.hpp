#ifndef ITERATOR_FOR_TREE_HPP
#define ITERATOR_FOR_TREE_HPP

#include "../trees/tree_tools.hpp"
#include "../trees/tree_structers.hpp"
#include <iostream>

namespace ft
{
	template <typename T, typename DiffType> class const_tree_iterator;

	template <typename T, typename DiffType> class tree_for_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef T&									reference
			typedef T* 									pointer;
			typedef DiffType							difference_type;
			typedef const_tree_iterator<T, DiffType>	const_iterator;

		private:
			typedef typename tree_node_types<T>::end_node_pointer end_node_pointer;
			typedef typename tree_node_types<T>::node_pointer node_pointer;

		public:
			tree_for_iterator() : ptr(NULL) {};
			tree_for_iterator(end_node_pointer enp) : ptr(enp) {};
			tree_for_iterator(node_pointer np) : ptr(static_cast<end_node_pointer>(p)) {};

			end_node_pointer &base() { return ptr; }
			const end_node_pointer &base() const { return ptr; }
			node_pointer node_ptr() const { return static_cast<node_pointer>(ptr); }
			reference operator*() const { return static_cast<node_pointer>(ptr)->value; }
			pointer operator->() const { return &(operator*()); }

			tree_for_iterator& operator++()
			{
				ptr = tree_iter_next<end_node_pointer>(static_cast<node_pointer>(ptr));
				return ( *this );
			}

			tree_for_iterator operator++(int)
			{
				tree_for_iterator tfit = *this;
				++(*this);
				return tfit;
			}

			tree_for_iterator& operator--()
			{
				ptr = tree_iter_prev<node_pointer>(ptr);
				return ( *this );
			}

			tree_for_iterator operator--(int)
			{
				tree_for_iterator tfi = *this;
				--(*this);
				return tfi;
			}

			bool operator==(const tree_for_iterator& any) const { return ptr == any.ptr; }
			bool operator==(const const_iterator& any) const { return ptr == any.base(); }
			bool operator!=(const tree_for_iterator& any) const { return !(*this == any); }
			bool operator!=(const const_iterator& any) const { return !(*this == any); }

		private:
			end_node_pointer ptr;
	};

	template <typename T, typename DiffType> class const_tree_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag		iterator_tag;
			typedef T									value_type;
			typedef const T&							reference;
			typedef const T* 							pointer;
			typedef DiffType							difference_type;
			typedef tree_for_iterator<T, DiffType>		non_const_iterator;

		private:
			typedef typename tree_node_types<T>::end_node_pointer	end_node_pointer;
			typedef typename tree_node_types<T>::node_pointer		node_pointer;

		public:
			const_tree_iterator() : ptr(NULL) {};
			const_tree_iterator(end_node_pointer enp) : ptr(enp) {};
			const_tree_iterator(node_pointer np) : ptr(static_cast<end_node_pointer>(np)) {};
			const_tree_iterator(non_const_iterator nit) : ptr(nit.base()) {};
			
		public:
			end_node_pointer& base() { return ptr; }
			const end_node_pointer& base() const { return ptr; }
			node_pointer node_ptr() const { return static_cast<node_pointer>(ptr); }
			reference operator*() const { return static_cast<node_pointer>(ptr)->value; }
			pointer operator->() const { return &(operator*()); }
			
			const_tree_iterator& operator++()
			{
				ptr = tree_iter_next<end_node_pointer>(static_cast<node_pointer>(ptr));
				return ( *this );
			}

			const_tree_iterator operator++(int)
			{
				const_tree_iterator cti = *this;
				++(*this);
				return cti;
			}

			const_tree_iterator& operator--()
			{
				ptr = tree_iter_prev<node_pointer>(ptr);
				return ( *this );
			}

			const_tree_iterator operator--(int)
			{
				const_tree_iterator cti = *this;
				--(*this);
				return cti;
			}

			bool operator==(const const_tree_iterator &any ) const { return ptr == any.ptr; }
			bool operator==(const non_const_iterator &any) const { return ptr == any.base(); }
			bool operator!=(const const_tree_iterator &any) const { return !(*this == any); }
			bool operator!=(const non_const_iterator &any) const { return !(*this) == any; }

		private:
			end_node_pointer ptr;

	};
};

#endif