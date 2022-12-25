#ifndef _TREE_HPP
# define _TREE_HPP

#include<memory>
#include "type_traits.hpp"

namespace ft
{
	template <typename T>
	struct _treeNode
	{
		typedef T value_type;
		value_type	_data;
		_treeNode	*_parent;
		_treeNode	*_left;
		_treeNode	*_right;

		_treeNode()
		: _data(), _parent(ft::nullptr_t), _left(ft::nullptr_t), _right(ft::nullptr_t) {}

		_treeNode(const value_type& val)
		: _data(val), _parent(ft::nullptr_t), _left(ft::nullptr_t), _right(ft::nullptr_t) {}
		
		_treeNode(const _treeNode& node)
		: _data(node._data), _parent(node._parent), _left(node._parent), _right(node._right) {}
		
		_treeNode& operator=(const _treeNode& node)
		{
			if (*this != node)
			{
				this->_data = node._data;
				this->_left = node._left;
				this->_right = node._right;
				this->_parent = node._parent;
			}
			return (*this);
		}
		~_treeNode() {}
	};
// private:
// 	typedef allocator_traits<allocator_type> __alloc_traits;
// 	typedef typename __make_tree_node_types<value_type,
// 											typename __alloc_traits::void_pointer>::type
// 		_NodeTypes;
// 	typedef typename _NodeTypes::key_type key_type;

// public:
// 	typedef typename _NodeTypes::__node_value_type __node_value_type;
// 	typedef typename _NodeTypes::__container_value_type __container_value_type;

// 	typedef typename __alloc_traits::pointer pointer;
// 	typedef typename __alloc_traits::const_pointer const_pointer;
// 	typedef typename __alloc_traits::size_type size_type;
// 	typedef typename __alloc_traits::difference_type difference_type;

// public:
// 	typedef typename _NodeTypes::__void_pointer __void_pointer;

// 	typedef typename _NodeTypes::__node_type __node;
// 	typedef typename _NodeTypes::__node_pointer __node_pointer;

// 	typedef typename _NodeTypes::__node_base_type __node_base;
// 	typedef typename _NodeTypes::__node_base_pointer __node_base_pointer;

// 	typedef typename _NodeTypes::__end_node_type __end_node_t;
// 	typedef typename _NodeTypes::__end_node_pointer __end_node_ptr;

// 	typedef typename _NodeTypes::__parent_pointer __parent_pointer;
// 	typedef typename _NodeTypes::__iter_pointer __iter_pointer;

// 	typedef typename __rebind_alloc_helper<__alloc_traits, __node>::type __node_allocator;
// 	typedef allocator_traits<__node_allocator> __node_traits;

	// template <class _Tp, class _Compare, class _Allocator>
	template <typename T, class _Compare, class Alloc>
	class _AvlTree
	{
		public:
			typedef T						value_type;
			typedef _Compare				value_compare;
			typedef Alloc					allocator_type;

			typedef _treeNode<value_type>	Node_type;
			typedef _treeNode<value_type>*	Node_pointer;
			
			// typedef tree_iterator<T>			iterator
			// typedef tree_iterator<const T>		const_iterator

		private:
			Node*	_root;
			int	get_height(Node *nd)
			{
				if (nd == ft::nullptr_t)
					return (0);
				int	h = 0;
				int	left = get_height(nb->_left);
				int right = get_height(nb->_right);
				int high_height = max(left, right);
				h = high_height + 1;
				return (h);
			}
			int	get_balance_factor()
			{

			}
			void	Balancing(Node* root)
			{
				int	balance = get_balance_factor(root);

			}
			void	LL_rotate()
			{

			}
			void	LR_rotate()
			{

			}
			void	RR_rotate()
			{

			}
			void	RL_rotate()
			{

			}
	};
}

#endif
