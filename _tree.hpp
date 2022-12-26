#ifndef _TREE_HPP
# define _TREE_HPP

#include<memory>
#include "functional.hpp"
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
	template <typename T, class _Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class _AvlTree
	{
		//define
		public:
			typedef T						value_type;
			typedef _Compare				value_compare;
			typedef Alloc					allocator_type;

			typedef _treeNode<value_type>	Node_type;
			typedef _treeNode<value_type>*	Node_pointer;

			// typedef tree_iterator<T>			iterator
			// typedef tree_iterator<const T>		const_iterator
		
		//member var
		// private:
		// 	__iter_pointer __begin_node_;
		// 	__compressed_pair<__end_node_t, __node_allocator> __pair1_;
		// 	__compressed_pair<size_type, value_compare> __pair3_;
		
		public:
			//삽입
			//삭제

			// iterator
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			// capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			// Element access
			mapped_type &operator[](const key_type &k)
			{
			}
			mapped_type &at(const key_type &k);
			const mapped_type &at(const key_type &k) const;

			// Modifiers
			pair<iterator, bool> insert(const value_type &val);
			iterator insert(iterator position, const value_type &val);
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last);
			void erase(iterator position);
			size_type erase(const key_type &k);
			void erase(iterator first, iterator last);
			void swap(map &x);
			void clear()
			{
			erase(begin(), end());
			}

			// Observers
			key_compare key_comp() const;
			value_compare value_comp() const;

			// Operations
			iterator find(const key_type &k);
			const_iterator find(const key_type &k) const;
			size_type count(const key_type &k) const;
			iterator lower_bound(const key_type &k);
			const_iterator lower_bound(const key_type &k) const;
			iterator upper_bound(const key_type &k);
			const_iterator upper_bound(const key_type &k) const;
			pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
			pair<iterator, iterator> equal_range(const key_type &k);

			// Allocator
			allocator_type get_allocator() const;

			// avl manage func
		private:
			int	get_height(Node_pointer nd)
			{
				if (nd == ft::nullptr_t)
					return (0);
				int	h = 0;
				int	left = get_height(nb->_left);
				int right = get_height(nb->_right);
				return (left > right ? left + 1 : right + 1);
			}
			int	get_balance_factor(Node_pointer nb)
			{
				return (get_height(nb->_left) - get_height(nb->_right));
			}
			Node_pointer	Balancing(Node_pointer nd)
			{
				int	balance = get_balance_factor(nd);
				if (balance >= 2)
				{
					balance = get_balance_factor(nd->_left);
					if (balance >= 1)
						nd = LL_rotate(nd);
					else
						nd = LR_rotate(nd);
				}
				else if (balance <= -2)
				{
					get_balance_factor(nd->_right);
					if (balance <= -1)
						nb = RR_rotate(nd);
					else
						nb = RL_rotate(nd);
				}
				return (nb);
			}
			Node_pointer	LL_rotate(Node_pointer nd)
			{
				Node_pointer child_nd = nd->_left;
				nd->_left = child_nd->_right;
				if (child_nd->_right != nullptr_t)
					child_nd->_right->_parent = nd;
				child_nd->_right = nd;
				child_nd->_parent = nd->_parent;
				nd->_parent = child_nd;
				return (child_nd);
			}
			Node_pointer	LR_rotate(Node_pointer nd)
			{
				nd->_left = RR_rotate(nd->_left);
				return (LL_rotate(nd));
			}
			Node_pointer	RR_rotate(Node_pointer nb)
			{
				Node_pointer child_nd = nb->_right;
				nd->_left = child_nd->_left;
				if (child_nd->_left != nullptr_t)
					child_nd->_left->_parent = nd;
				child_nd->_left = nd;
				child_nd->_parent = nd->_parent;
				nd->_parent = child_nd;
				return (child_nd);
			}
			Node_pointer	RL_rotate(Node_pointer nd)
			{
				nd->_right = LL_rotate(nd->_right);
				return (RR_rotate(nd));
			}
	};
}

#endif
