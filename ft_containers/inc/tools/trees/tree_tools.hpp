/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tools.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:17 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:33:18 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_TOOLS_HPP
#define TREE_TOOLS_HPP

#include "tree_structers.hpp"

namespace ft
{
    template <typename NodePtr>
    inline bool tree_is_left_child(NodePtr ptr)
    {
        return ptr == ptr->parent->left;
    }

    template <typename NodePtr>
    NodePtr tree_max(NodePtr ptr)
    {
        while (ptr->right != NULL)
            ptr = ptr->right;
        return ptr;
    }

    template <typename NodePtr>
    NodePtr tree_min(NodePtr ptr)
    {
        while (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        return ptr;
    }

    template <typename IterPtr, typename NodePtr>
    IterPtr tree_iter_next(NodePtr ptr)
    {
        if (ptr->right != NULL)
            return tree_min(ptr->right);
        while (!tree_is_left_child(ptr))
            ptr = ptr->get_parent();
        return ptr->parent;
    }

    template <typename NodePtr, typename IterPtr>
    IterPtr tree_iter_prev(IterPtr ptr)
    {
        if (ptr->left != NULL)
            return tree_max(ptr->left);
        NodePtr nptr = static_cast<NodePtr>(ptr);
        while (tree_is_left_child(nptr))
            nptr = nptr->get_parent();
        return nptr->parent;
    }

    template <typename NodePtr>
    void tree_rotate_left(NodePtr node)
    {
        NodePtr ptr = node->right;

        node->right = ptr->left;
        if (ptr->left != NULL)
            ptr->left->set_parent(node);
        ptr->left = node;
        ptr->parent = node->parent;
        if (tree_is_left_child(node))
            node->parent->left = ptr;
        else
            node->get_parent()->right = ptr;
        node->set_parent(ptr);
    }

    template <typename NodePtr>
    void tree_rotate_right(NodePtr node)
    {
        NodePtr ptr = node->left;

        node->left = ptr->right;
        if (ptr->right != NULL)
            ptr->right->set_parent(node);
        ptr->right = node;
        ptr->parent = node->parent;
        if (tree_is_left_child(node))
            node->parent->left = ptr;
        else
            node->get_parent()->right = ptr;
        node->set_parent(ptr);
    }

    template <typename NodePtr>
    void tree_rotate_left(NodePtr &root, NodePtr node)
    {
        if (node == root)
            root = node->right;
        tree_rotate_left(node);
    }

    template <typename NodePtr>
    void tree_rotate_right(NodePtr &root, NodePtr node)
    {
        if (node == root)
            root = node->left;
        tree_rotate_right(node);
    }

    template <typename NodePtr>
    inline bool tree_node_is_black(NodePtr node)
    {
        if (node == NULL || node->is_black)
            return true;
        return false;
    }

    template <typename NodePtr>
    void tree_insert_fix(NodePtr root, NodePtr z)
    {
        z->is_black = z == root;
        while (z != root && !z->get_parent()->is_black)
        {
            if (tree_is_left_child(z->get_parent()))
            {
                NodePtr uncle = z->get_parent()->get_parent()->right;
                if (!tree_node_is_black(uncle))
                {
                    uncle->is_black = true;
                    z = z->get_parent();
                    z->is_black = true;
                    z = z->get_parent();
                    z->is_black = z == root;
                }
                else
                {
                    if (!tree_is_left_child(z))
                    {
                        z = z->get_parent();
                        tree_rotate_left(z);
                    }

                    z = z->get_parent();
                    z->is_black = true;
                    z = z->get_parent();
                    z->is_black = false;
                    tree_rotate_right(z);
                    return;
                }
            }
            else
            {
                NodePtr uncle = z->get_parent()->parent->left;
                if (!tree_node_is_black(uncle))
                {
                    uncle->is_black = true;
                    z = z->get_parent();
                    z->is_black = true;
                    z = z->get_parent();
                    z->is_black = z == root;
                }
                else
                {
                    if (tree_is_left_child(z))
                    {
                        z = z->get_parent();
                        tree_rotate_right(z);
                    }
                    z = z->get_parent();
                    z->is_black = true;
                    z = z->get_parent();
                    z->is_black = false;
                    tree_rotate_left(z);
                    return;
                }
            }
        }
    }

    template <typename NodePtr>
    void tree_delete_fix(NodePtr root, NodePtr x_parent)
    {
        NodePtr x = NULL;
        while (root != x && tree_node_is_black(x))
        {
            if (x == x_parent->left)
            {
                NodePtr w = x_parent->right;

                if (!w->is_black)
                {
                    x_parent->is_black = false;
                    w->is_black = true;
                    tree_rotate_left(root, x_parent);
                    w = x_parent->right;
                }
                if (tree_node_is_black(w->left) && tree_node_is_black(w->right))
                {
                    w->is_black = false;
                    x = x_parent;
                    x_parent = x->get_parent();
                }
                else
                {
                    if (tree_node_is_black(w->right))
                    {
                        w->is_black = false;
                        tree_rotate_right(root, w);
                        w = x_parent->right;
                        w->is_black = true;
                    }
                    w->is_black = x_parent->is_black;
                    x_parent->is_black = true;
                    w->right->is_black = true;
                    tree_rotate_left(root, x_parent);
                    x = root;
                    break;
                }
            }
            else
            {
                NodePtr w = x_parent->left;

                if (!w->is_black)
                {
                    x_parent->is_black = false;
                    w->is_black = true;
                    tree_rotate_right(root, x_parent);
                    w = x_parent->left;
                }
                if (tree_node_is_black(w->right) && tree_node_is_black(w->left))
                {
                    w->is_black = false;
                    x = x_parent;
                    x_parent = x->get_parent();
                }
                else
                {
                    if (tree_node_is_black(w->left))
                    {
                        w->is_black = false;
                        tree_rotate_left(root, w);
                        w = x_parent->left;
                        w->is_black = true;
                    }
                    w->is_black = x_parent->is_black;
                    x_parent->is_black = true;
                    w->left->is_black = true;
                    tree_rotate_right(root, x_parent);
                    x = root;
                    break;
                }
            }
        }
        if (x)
            x->is_black = true;
    }

    template <typename NodePtr>
    void tree_transplant_node(NodePtr pos, NodePtr &node)
    {
        node->is_black = pos->is_black;
        node->parent = pos->parent;
        if (tree_is_left_child(pos))
            node->parent->left = node;
        else
            node->get_parent()->right = node;
        node->left = pos->left;
        node->left->set_parent(node);
        node->right = pos->right;
        if (node->right)
            node->right->set_parent(node);
    }

    template <typename NodePtr>
    void tree_remove_node(NodePtr root, NodePtr target)
    {
        NodePtr y = target;

        if (y->left != NULL && y->right != NULL)
            y = tree_min(target->right);
        NodePtr x;
        if (y->left != NULL)
            x = y->left;
        else
            x = y->right;
        NodePtr x_parent = y->get_parent();
        if (x != NULL)
            x->parent = y->parent;
        if (tree_is_left_child(y))
        {
            y->parent->left = x;
            if (root == y)
                root = x;
        }
        else
        {
            if (target->right == y)
                x_parent = y;
            y->get_parent()->right = x;
        }
        bool removed_black = y->is_black;
        if (y != target)
        {
            tree_transplant_node(target, y);
            if (target == root)
                root = y;
        }
        if (removed_black)
        {
            if (root == NULL)
                return;
            if (x != NULL)
            {
                x->is_black = true;
                return;
            }
            tree_delete_fix(root, x_parent);
        }
    }
}

#endif