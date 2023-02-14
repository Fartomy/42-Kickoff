/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_structers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:15 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:33:16 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_STRUCTERS_HPP
#define TREE_STRUCTERS_HPP

#include <cstddef>

namespace ft
{
	template<typename T> class tree_end_node;
	template <typename T> class tree_node;
	template<typename T> struct tree_node_types
	{
		typedef tree_end_node<T> end_node_type;
		typedef end_node_type* end_node_pointer;
		typedef tree_node<T> node_type;
		typedef node_type* node_pointer;
	};

	template <typename T> class tree_end_node
	{
	public:
		typedef typename tree_node_types<T>::node_pointer node_pointer;
		node_pointer left;
		tree_end_node() : left(NULL) {}
	};

	template <typename T> class tree_node : public tree_node_types<T>::end_node_type
	{
	public:
		typedef typename tree_node_types<T>::end_node_pointer end_node_pointer;
		typedef typename tree_node_types<T>::node_pointer node_pointer;
		node_pointer right;
		end_node_pointer parent;
		bool is_black;
		T value;
		tree_node() : right(NULL), parent(NULL), is_black(false){}

		node_pointer get_parent() const
		{
			return static_cast<node_pointer>(parent);
		}

		void set_parent(node_pointer ptr)
		{
			parent = static_cast<end_node_pointer>(ptr);
		}
	};
}

#endif
