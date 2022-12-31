#ifndef _TREE_HPP
# define _TREE_HPP

#include<memory>
#include "iterator.hpp"
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
		: _data(value_type()), _parent(ft::nullptr_t), _left(ft::nullptr_t), _right(ft::nullptr_t) {}

		_treeNode(const value_type& val)
		: _data(val), _parent(ft::nullptr_t), _left(ft::nullptr_t), _right(ft::nullptr_t) {}
		
		_treeNode(const _treeNode& node)
		: _data(node._data), _parent(node._parent), _left(node._parent), _right(node._right), {}
		
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

	//T == _treeNode<>
	template <class T>
	class tree_iterator : public ft::iterator<ft::bidirection_iterator_tag, T>
	{
	public:
		typedef typename iterator::iterator_category	iterator_category;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::reference			reference;
		typedef typename iterator::pointer				Node_pointer;

	private:
		// typedef _treeNode<value_type>*					Node_pointer;
		Node_pointer	_pointer;
	public:
		tree_iterator() : _pointer(ft::nullptr_t);
		tree_iterator(Node_pointer node) : _pointer(node);
		tree_iterator(const tree_iterator& a)
		{
			this->_pointer = a.base();
		}
		tree_iterator& operator=(const tree_iterator& a)
		{
			if (this != &a)
				this->_pointer = a.base();
			return (*this);
		}
		~tree_iterator() {}
		Node_pointer base() const
		{
			return (this->_pointer);
		}
		tree_iterator& operator++()
		{
			if (_pointer->_right != ft::nullptr_t)
			{
				_pointer = _pointer->right;
				while (_pointer->_left != ft::nullptr_t)
					_pointer = _pointer->_left;
			}
			else
			{
				Node_pointer y = _pointer->_parent;
				while (_pointer == y->_right)
				{
					_pointer = y;
					y = y->_parent;
				}
				if (_pointer->_right != y)
					_pointer = y;
			}
			return (*this);
		}
		tree_iterator& operator++(int)
		{
			tree_iterator tmp = *this;
			if (_pointer->_right != ft::nullptr_t)
			{
				_pointer = _pointer->right;
				while (_pointer->_left != ft::nullptr_t)
					_pointer = _pointer->_left;
			}
			else
			{
				Node_pointer y = _pointer->_parent;
				while (_pointer == y->_right)
				{
					_pointer = y;
					y = y->_parent;
				}
				if (_pointer->_right != y)
					_pointer = y;
			}
			return (tmp);
		}
		tree_iterator& operator--()
		{
			if (_pointer->_left != ft::nullptr_t)
			{
				_pointer = _pointer->_left;
				while (_pointer->_right != ft::nullptr_t)
					_pointer = _pointer->_right;
			}
			else
			{
				Node_pointer y = _pointer->_parent;
				while (_pointer == y->_left)
				{
					_pointer = y;
					y = y->_parent;
				}
				if (_pointer->_left != y)
					_pointer = y;
			}
			return (*this);
		}
		tree_iterator& operator--(int)
		{
			tree_iterator tmp = *this;
			if (_pointer->_left != ft::nullptr_t)
			{
				_pointer = _pointer->_left;
				while (_pointer->_right != ft::nullptr_t)
					_pointer = _pointer->_right;
			}
			else
			{
				Node_pointer y = _pointer->_parent;
				while (_pointer == y->_left)
				{
					_pointer = y;
					y = y->_parent;
				}
				if (_pointer->_left != y)
					_pointer = y;
			}
			return (tmp);
		}
		reference operator*() const 
		{
			return (this->_pointer->_data);
		}

		Node_pointer operator->() const
		{
			return (&(this->_pointer->_data));
		}
	};
	
	template <class T>
	bool operator==(const tree_iterator<T>& a, const tree_iterator<T>& b)
	{
		return (a._pointer == b._pointer);
	}
	template <class T>
	bool operator!=(const tree_iterator<T>& a, const tree_iterator<T>& b)
	{
		return (!(a == b));
	}

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

			typedef ptrdiff_t				difference_type;
			typedef size_t					size_type;

			typedef typename allocator_type::template rebind<Node_type>::other	node_allocator;

			typedef tree_iterator<T>			iterator;
			typedef tree_iterator<const T>		const_iterator;
		
		//member var
		private:
			node_allocator	_alloc;
			Node_pointer	_end;
			size_type		_size;
		// 	__iter_pointer __begin_node_;
		// 	__compressed_pair<__end_node_t, __node_allocator> __pair1_;
		// 	__compressed_pair<size_type, value_compare> __pair3_;
		
		public:
			_AvlTree(const allocator_type& alloc = allocator_type()) :_alloc(alloc)
			{
				this->_size = 0;
				this->_end = this->_alloc.allocate(1);
				this->_alloc.construct(this->_end, value_type());
			}
			_AvlTree(const _AvlTree& a) : _alloc(a._alloc), _size(a._size)
			{
				this->_end = this->_alloc.allocate(1);
				this->_alloc.construct(this->_end, value_type());
				this->_size = a._size;
				insert(a.begin(), a.end());
			}
			_AvlTree& operator=(const _AvlTree& a)
			{
				if (this != &a)
				{
					_AvlTree tmp(a);
					swap(tmp);
				}
				return (*this);
			}
			~_AvlTree()
			{
				// this->_alloc.destroy()
			}
			// iterator
			iterator begin()
			{
				return (iterator(find_min_node(_end->_right)));
			}
			const_iterator begin() const
			{
				return (iterator(find_min_node(_end->_right)));
			}
			iterator end()
			{
				return (iterator(_end));
			}
			const_iterator end() const
			{
				return (iterator(_end));
			}

			// capacity
			bool empty() const
			{
				return (this->_size == 0);
			}
			size_type size() const
			{
				return (this->_size);
			}
			size_type max_size() const
			{
				return (this->_alloc.max_size());
			}

			// Element access
			// mapped_type &operator[](const key_type &k)
			// {
			// }
			// mapped_type &at(const key_type &k);
			// const mapped_type &at(const key_type &k) const;

			// Modifiers 
			pair<iterator, bool> insert(const value_type &val)
			{
				if (this->_size == 0)
				{
					Node_pointer *new_node = this->_alloc.allocate(1);
					this->_alloc.construct(new_node, Node_type(val));
					new_node->_right = this->_end;
					this->_end->_right = new_node;
					this->_end->_left = new_node;
					new_node->_left = ft::nullptr_t;
					new_node->_parent = ft::nullptr_t;
					this->_size++;
					return (ft::make_pair(iterator(new_node), true));
				}
				Node_pointer *start = this->_end->_right;
				Node_pointer *last = this->_end;
				Node_pointer *save_node;
				int flag = 0;
				while(start != last && start != ft::nullptr_t)
				{
					if (start->_data.first == val.first)
						return (ft::make_pair(iterator(start), false));
					save_node = start;
					if (start->_data.first > val.first)
					{
						start = start->_left;
						flag = 0;
					}
					else
					{
						start = start->_right;
						flag = 1;
					}
				}
				Node_pointer *new_node = this->_alloc.allocate(1);
				this->_alloc.construct(new_node, Node_type(val));
				this->_size++;
				if (flag == 0)
					save_node->_left = new_node;
				else
					save_node->_right = new_node;
				new_node->_parent = save_node;
				new_node->_right = ft::nullptr_t;
				new_node->_left = ft::nullptr_t;
				if (start == last)
				{
					new_node->_right = this->_end;
					this->_end->_left = new_node;
				}
				Balancing(new_node);
				this->_end->_right = find_root_node(this->_end->_right);
				return (ft::make_pair(iterator(start), true));
			}
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
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}

			// avl manage func
		private:
			Node_pointer next_node(Node_pointer nd)
			{
				Node_pointer *next_nd = nd;
				if (next_nd->_right != ft::nullptr_t)
				{
					next_nd = next_nd->right;
					while (next_nd->_left != ft::nullptr_t)
						next_nd = next_nd->_left;
				}
				else
				{
					Node_pointer y = next_nd->_parent;
					while (next_nd == y->_right)
					{
						next_nd = y;
						y = y->_parent;
					}
					if (next_nd->_right != y)
						next_nd = y;
				}
				return (next_nd);
			}
			Node_pointer find_min_node(Node_pointer root)
			{
				while (root->_left != ft::nullptr_t)
					root = root->_left;
				return (root);
			}
			Node_pointer find_max_node(Node_pointer root)
			{
				while (root->_right != ft::nullptr_t)
					root = root->_right;
				return (root);
			}
			Node_pointer find_root_node(Node_pointer nd)
			{
				while (nd->_parent != ft::nullptr_t)
					nd = nd->_parent;
				return (nd);
			}
			size_type	get_height(Node_pointer nd)
			{
				if (nd == ft::nullptr_t)
					return (0);
				int	h = 0;
				int	left = get_height(nb->_left);
				int right = get_height(nb->_right);
				return (left > right ? left + 1 : right + 1);
			}
			int	get_balance_factor(Node_pointer nd)
			{
				return (get_height(nd->_left) - get_height(nd->_right));
			}
			void	Balancing(Node_pointer nd)
			{
				while (nd->_parent != ft::nullptr_t)
				{
					//?? 효율 garbage
					nd = nd->_parent;
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
							nd = RR_rotate(nd);
						else
							nd = RL_rotate(nd);
					}
				}
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
