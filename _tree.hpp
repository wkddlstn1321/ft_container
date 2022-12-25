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

		_treeNode() : _data(), _parent(ft::nullptr_t), _left(ft::nullptr_t), _right(ft::nullptr_t) {}
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

	template <typename T, class Node = _treeNode<T>, class Alloc = std::allocator<T>>
	class _AvlTree
	{
		public:
		
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
			void	Balancing()
			{

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
