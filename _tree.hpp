#ifndef _TREE_HPP
# define _TREE_HPP

#include<iostream>

#include<memory>
#include "iterator.hpp"
#include "functional.hpp"
#include "type_traits.hpp"
#include "utility.hpp"

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
		size_t		depth;
		_treeNode()
		: _data(value_type()), _parent(ft::nullptr_t), _left(ft::nullptr_t), _right(ft::nullptr_t), depth(0) {}

		_treeNode(const value_type& val)
		: _data(val), _parent(ft::nullptr_t), _left(ft::nullptr_t), _right(ft::nullptr_t), depth(0) {}
		
		_treeNode(const _treeNode& node)
		: _data(node._data), _parent(node._parent), _left(node._parent), _right(node._right), depth(node.depth){}
		
		_treeNode& operator=(const _treeNode& node)
		{
			if (*this != node)
			{
				this->depth = node.depth;
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
	class tree_iterator //: public ft::iterator<ft::bidirection_iterator_tag, T>
	{
	//_value == ft::pair<key, value>
	private:
		typedef T* Node_pointer;
		typedef typename T::value_type _value_type;
		typedef typename ft::iterator<ft::bidirection_iterator_tag, _value_type> _Iterator;
	public:
		typedef typename _Iterator::iterator_category	iterator_category;
		typedef typename _Iterator::value_type			value_type;
		typedef typename _Iterator::difference_type		difference_type;
		typedef typename _Iterator::reference			reference;
		typedef typename _Iterator::pointer				pointer;

	private:
		// typedef _treeNode<value_type>*					Node_pointer;
		Node_pointer	_pointer;
	public:
		tree_iterator() : _pointer(ft::nullptr_t) {}
		tree_iterator(Node_pointer node) : _pointer(node) {}
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
				_pointer = _pointer->_right;
				while (_pointer->_left != ft::nullptr_t)
				{
					if (_pointer->_left->_right == _pointer)
						break ;
					_pointer = _pointer->_left;
				}
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
		tree_iterator operator++(int)
		{
			tree_iterator tmp = *this;
			if (_pointer->_right != ft::nullptr_t)
			{
				_pointer = _pointer->_right;
				while (_pointer->_left != ft::nullptr_t)
				{
					if (_pointer->_left->_right == _pointer)
						break;
					_pointer = _pointer->_left;
				}
			}
			else
			{
				Node_pointer y = _pointer->_parent;
				if (y == ft::nullptr_t)
					return (*this);
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
				{
					if (_pointer->_right->_left == _pointer)
						break ;
					_pointer = _pointer->_right;
				}
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
		tree_iterator operator--(int)
		{
			tree_iterator tmp = *this;
			if (_pointer->_left != ft::nullptr_t)
			{
				_pointer = _pointer->_left;
				while (_pointer->_right != ft::nullptr_t)
				{
					if (_pointer->_right->_left == _pointer)
						break ;
					_pointer = _pointer->_right;
				}
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

		pointer operator->() const
		{
			return (&(this->_pointer->_data));
		}
	};
	
template <class T>
	class tree_const_iterator //: public ft::iterator<ft::bidirection_iterator_tag, T>
	{
	//_value == ft::pair<key, value>
	private:
		typedef T* Node_pointer;
		typedef typename T::value_type _value_type;
		typedef typename ft::iterator<ft::bidirection_iterator_tag, _value_type> _Iterator;
	public:
		typedef typename _Iterator::iterator_category	iterator_category;
		typedef typename _Iterator::value_type			value_type;
		typedef typename _Iterator::difference_type		difference_type;
		typedef typename _Iterator::reference			reference;
		typedef typename _Iterator::pointer				pointer;

	private:
		// typedef _treeNode<value_type>*					Node_pointer;
		Node_pointer	_pointer;
	public:
		tree_const_iterator() : _pointer(ft::nullptr_t) {}
		tree_const_iterator(Node_pointer node) : _pointer(node) {}
		tree_const_iterator(const tree_const_iterator& a)
		{
			this->_pointer = a.base();
		}
		tree_const_iterator& operator=(const tree_const_iterator& a)
		{
			if (this != &a)
				this->_pointer = a.base();
			return (*this);
		}
		~tree_const_iterator() {}
		Node_pointer base() const
		{
			return (this->_pointer);
		}
		tree_const_iterator& operator++()
		{
			if (_pointer->_right != ft::nullptr_t)
			{
				_pointer = _pointer->_right;
				while (_pointer->_left != ft::nullptr_t)
				{
					if (_pointer->_left->_right == _pointer)
						break ;
					_pointer = _pointer->_left;
				}
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
		tree_const_iterator operator++(int)
		{
			tree_const_iterator tmp = *this;
			if (_pointer->_right != ft::nullptr_t)
			{
				_pointer = _pointer->_right;
				while (_pointer->_left != ft::nullptr_t)
				{
					if (_pointer->_left->_right == _pointer)
						break;
					_pointer = _pointer->_left;
				}
			}
			else
			{
				Node_pointer y = _pointer->_parent;
				if (y == ft::nullptr_t)
					return (*this);
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
		tree_const_iterator& operator--()
		{
			if (_pointer->_left != ft::nullptr_t)
			{
				_pointer = _pointer->_left;
				while (_pointer->_right != ft::nullptr_t)
				{
					if (_pointer->_right->_left == _pointer)
						break ;
					_pointer = _pointer->_right;
				}
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
		tree_const_iterator operator--(int)
		{
			tree_const_iterator tmp = *this;
			if (_pointer->_left != ft::nullptr_t)
			{
				_pointer = _pointer->_left;
				while (_pointer->_right != ft::nullptr_t)
				{
					if (_pointer->_right->_left == _pointer)
						break ;
					_pointer = _pointer->_right;
				}
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

		pointer operator->() const
		{
			return (&(this->_pointer->_data));
		}
	};


	template <class T>
	bool operator==(const tree_iterator<T>& a, const tree_iterator<T>& b)
	{
		return (a.base() == b.base());
	}
	template <class T>
	bool operator!=(const tree_iterator<T>& a, const tree_iterator<T>& b)
	{
		return (!(a == b));
	}

	// template <class _Tp, class _Compare, class _Allocator>
	template <typename T, typename Key, class _Compare, class Alloc = std::allocator<T> >
	class _AvlTree
	{
		// typedef __tree_iterator<value_type, __node_pointer, difference_type> iterator;
		// typedef __tree_const_iterator<value_type, __node_pointer, difference_type> const_iterator;
		//define
		public:
			typedef _Compare						key_compare;
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef Key								key_type;
			typedef _treeNode<value_type>			Node_type;
			typedef _treeNode<value_type>*			Node_pointer;

			typedef ptrdiff_t				difference_type;
			typedef size_t					size_type;

			typedef typename allocator_type::template rebind<Node_type>::other	node_allocator;

			typedef tree_iterator<Node_type>			iterator;
			typedef tree_const_iterator<Node_type>		const_iterator;
		
		//member var
		private:
			node_allocator	_alloc;
			Node_pointer	_end;
			size_type		_size;
			key_compare		_comp;

		// 	__iter_pointer __begin_node_;
		// 	__compressed_pair<__end_node_t, __node_allocator> __pair1_;
		// 	__compressed_pair<size_type, value_compare> __pair3_;
		
		public:
			_AvlTree(const allocator_type& alloc = allocator_type(), const key_compare &comp = key_compare())
			:_alloc(alloc), _comp(comp)
			{
				this->_size = 0;
				this->_end = this->_alloc.allocate(1);
				this->_alloc.construct(this->_end, value_type());
				this->_end->_parent = ft::nullptr_t;
				this->_end->_right = ft::nullptr_t;
				this->_end->_left = ft::nullptr_t;
			}
			_AvlTree(const _AvlTree& a) : _alloc(a._alloc), _size(a._size), _comp(a._comp)
			{
				this->_end = this->_alloc.allocate(1);
				this->_alloc.construct(this->_end, value_type());
				this->_end->_parent = ft::nullptr_t;
				this->_end->_right = ft::nullptr_t;
				this->_end->_left = ft::nullptr_t;
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
				return (iterator(find_min_node(_end->_parent)));
			}
			const_iterator begin() const
			{
				return (const_iterator(find_min_node(_end->_parent)));
			}
			iterator end()
			{
				return (iterator(this->_end));
			}
			const_iterator end() const
			{
				return (const_iterator(_end));
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

			// Modifiers 
			ft::pair<iterator, bool> insert(const value_type &val)
			{
				if (this->_size == 0)
				{
					Node_pointer new_node = this->_alloc.allocate(1);
					this->_alloc.construct(new_node, Node_type(val));
					new_node->_right = this->_end;
					this->_end->_parent = new_node;
					this->_end->_left = new_node;
					new_node->_left = ft::nullptr_t;
					new_node->_parent = ft::nullptr_t;
					new_node->depth = 0;
					this->_size++;
					return (ft::make_pair(iterator(new_node), true));
				}
				Node_pointer start = this->_end->_parent;
				Node_pointer last = this->_end;
				Node_pointer save_node;
				int flag = 0;
				while(start != last && start != ft::nullptr_t)
				{
					if (start->_data.first == val.first)
						return (ft::make_pair(iterator(start), false));
					save_node = start;
					if (_comp(start->_data.first, val.first))
					{
						start = start->_right;
						flag = 0;
					}
					else
					{
						start = start->_left;
						flag = 1;
					}
				}
				Node_pointer new_node = this->_alloc.allocate(1);
				this->_alloc.construct(new_node, Node_type(val));
				this->_size++;
				if (flag == 1)
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
				depth_update(new_node, 1);
				Balancing(new_node);
				this->_end->_parent = find_root_node(this->_end->_parent);
				return (ft::make_pair(iterator(new_node), true));
			}
			iterator insert(iterator position, const value_type &val)
			{
				(void)position;
				insert(val);
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			void erase(iterator position)
			{
				this->_size--;
				Node_pointer del_node = position.base();
				if (del_node->_left == ft::nullptr_t && del_node->_right == ft::nullptr_t)
				{
					Node_pointer tmp = del_node->_parent;
					this->_alloc.destroy(del_node);
					this->_alloc.deallocate(del_node, 1);
					if (tmp != ft::nullptr_t)
					{
						depth_update(tmp, 1);
						Balancing(tmp);
						this->_end->_parent = find_root_node(this->_end->_left);
					}
					else
						this->_end->_parent = ft::nullptr_t;
					return ;
				}
				Node_pointer tmp = del_node->_left;
				if (tmp == ft::nullptr_t)
				{
					tmp = del_node->_right;
					if (del_node->_parent != ft::nullptr_t)
					{
						tmp->_parent = del_node->_parent;
						if (this->_comp(del_node->_data.first, del_node->_parent->_data.first))
							del_node->_parent->_left = tmp;
						else
							del_node->_parent->_right = tmp;
					}
				}
				else
				{
					while (tmp->_right != ft::nullptr_t)
						tmp = tmp->_right;
					tmp->_right = del_node->_right;
					if (tmp->_parent != del_node)
					{
						tmp->_left = del_node->_left;
						tmp->_parent->_right = ft::nullptr_t;
					}
				}
				this->_alloc.destroy(del_node);
				this->_alloc.deallocate(del_node, 1);
				depth_update(tmp, 1);
				Balancing(tmp);
				this->_end->_parent = find_root_node(tmp);
			}
			size_type erase(const key_type &k)
			{
				iterator iter = find(k);
				if (iter == end())
					return (0);
				erase(iter);
				return (1);
			}
			void erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
			}
			void swap(_AvlTree &x)
			{
				node_allocator tmp_alloc = this->_alloc;
				Node_pointer tmp = this->_end;
				size_type tmp_size = this->_size;
				key_compare tmp_compare = this->_comp;
				this->_alloc = x._alloc;
				this->_end = x._end;
				this->_size = x._size;
				this->_comp = x._comp;
				x._alloc = tmp_alloc;
				x._end = tmp;
				x._size = tmp_size;
				x._comp = tmp_compare;
			}
			void clear()
			{
				erase(begin(), end());
			}

			// Operations
			iterator find(const key_type &k)
			{
				Node_pointer tmp = this->_end->_parent;
				while (tmp != ft::nullptr_t)
				{
					if (tmp->_data.first == k)
						return (iterator(tmp));
					else if (this->_comp(tmp->_data.first, k))
						tmp = tmp->_right;
					else
						tmp = tmp->_left;
				}
				return (end());
			}
			const_iterator find(const key_type &k) const
			{
				Node_pointer tmp = this->_end->_parent;
				while (tmp != ft::nullptr_t)
				{
					if (tmp->_data.first == k)
						return (iterator(tmp));
					else if (this->_comp(tmp->_data.first, k))
						tmp = tmp->_right;
					else
						tmp = tmp->_left;
				}
				return (end());
			}
			size_type count(const key_type &k) const
			{
				if (end() == find(k))
					return (0);
				return (1);
			}
			//k 보다 크거나 같은 원소
			iterator lower_bound(const key_type &k)
			{
				Node_pointer	root = find_root_node(this->_end->_parent);
				iterator		result = end();
				while (root != ft::nullptr_t)
				{
					if (!this->_comp(root->_data.first, k))
					{
						result = (iterator)root;
						root = root->_left;
					}
					else
						root = root->_right;
				}
				return (result);
			}
			const_iterator lower_bound(const key_type &k) const
			{
				Node_pointer	root = find_root_node(this->_end->_parent);
				const_iterator	result = end();
				while (root != ft::nullptr_t)
				{
					if (!this->_comp(root->_data.first, k))
					{
						result = (const_iterator)root;
						root = root->_left;
					}
					else
						root = root->_right;
				}
				return (result);
			}
			//k 보다 큰 원소
			iterator upper_bound(const key_type &k)
			{
				Node_pointer	root = find_root_node(this->_end->_parent);
				iterator		result = end();
				while (root != ft::nullptr_t)
				{
					if (this->_comp(k, root->_data.first))
					{
						result = (iterator)root;
						root = root->_left;
					}
					else
						root = root->_right;
				}
				return (result);
			}
			const_iterator upper_bound(const key_type &k) const
			{
				Node_pointer	root = find_root_node(this->_end->_parent);
				const_iterator	result = end();
				while (root != ft::nullptr_t)
				{
					if (this->_comp(k, root->_data.first))
					{
						result = (const_iterator)root;
						root = root->_left;
					}
					else
						root = root->_right;
				}
				return (result);
			}
			ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				retunr (ft::make_pair<lower_bound(k), upper_bound(k)>);
			}
			ft::pair<iterator, iterator> equal_range(const key_type &k)
			{
				return (ft::make_pair<lower_bound(k), upper_bound(k)>);
			}
			// Allocator
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}

			// avl manage func
		private:
			void	depth_update(Node_pointer nd, size_type depth)
			{
				nd->depth = depth > get_height(nd) ? depth : get_height(nd);
				if (nd->_parent != ft::nullptr_t)
					depth_update(nd->_parent, depth + 1);
				std::cout << " key : " << nd->_data.first << " depth : " << nd->depth << std::endl;
				// std::cout << std::endl;
			}
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
				if (root == ft::nullptr_t)
					return (ft::nullptr_t);
				while (root->_left != ft::nullptr_t)
					root = root->_left;
				return (root);
			}
			Node_pointer find_max_node(Node_pointer root)
			{
				if (root == ft::nullptr_t)
					return (ft::nullptr_t);
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
				size_type left_depth;
				size_type right_depth;
				if (nd->_left == ft::nullptr_t)
					left_depth = 0;
				else
					left_depth = nd->_left->depth;
				if (nd->_right == ft::nullptr_t)
					right_depth = 0;
				else
					right_depth = nd->_right->depth;
				return (right_depth > left_depth ? right_depth + 1 : left_depth + 1);
				// return (nd->depth);
			}
			int	get_balance_factor(Node_pointer nd)
			{
				size_type left_depth;
				size_type right_depth;
				if (nd->_left == ft::nullptr_t)
					left_depth = 0;
				else
					left_depth = nd->_left->depth;
				if (nd->_right == ft::nullptr_t)
					right_depth = 0;
				else
					right_depth = nd->_right->depth;
				return (left_depth - right_depth);
			}
			void	Balancing(Node_pointer nd)
			{
				// 균형이 깨진 노드를 찾아야 됨
				while (nd != ft::nullptr_t)
				{
					int	balance = get_balance_factor(nd);
					std::cout << "key : " << nd->_data.first << " balance : " << balance << std::endl;
					if (balance >= 2)
					{
						balance = get_balance_factor(nd->_left);
						if (balance >= 1)
						{
							std::cout << nd->_data.first;
							std::cout << " LL rotatate" << std::endl;
							nd = LL_rotate(nd);
						}
						else
						{
							std::cout << nd->_data.first;
							std::cout << " LR rotatate" << std::endl;
							nd = LR_rotate(nd);
						}
					}
					else if (balance <= -2)
					{
						balance = get_balance_factor(nd->_right);
						if (balance <= -1)
						{
							std::cout << nd->_data.first;
							std::cout << " RR rotatate" << std::endl;
							nd = RR_rotate(nd);
						}
						else
						{
							std::cout << nd->_data.first;
							std::cout << " RL rotatate" << std::endl;
							nd = RL_rotate(nd);
						}
					}
					nd = nd->_parent;
				}
			}
			Node_pointer	LL_rotate(Node_pointer nd)
			{
				std::cout << "Key & nd dep : " << nd->_data.first << " " << nd->depth << std::endl;
				if (nd->_right != ft::nullptr_t)
				{
					std::cout << "Key & rt dep : " << nd->_right->_data.first << " " << nd->_right->depth << std::endl;
					// if (nd->_right->_right != ft::nullptr_t)
					// 	std::cout << "rt dep : " << nd->_left->_dat.first << " " << nd->_right->_right->_data.first << std::endl;
				}
				if (nd->_left != ft::nullptr_t)
					std::cout << "Key & lt dep : " << nd->_left->_data.first << " " << nd->_left->depth << std::endl;
				Node_pointer child_nd = nd->_left;
				nd->_left = child_nd->_right;
				if (child_nd->_right != nullptr_t)
					child_nd->_right->_parent = nd;
				child_nd->_right = nd;
				child_nd->_parent = nd->_parent;
				if (nd->_parent != ft::nullptr_t)
				{
					if (_comp(nd->_parent->_data.first, nd->_data.first))
						nd->_parent->_right = child_nd;
					else
						nd->_parent->_left = child_nd;
				}
				nd->_parent = child_nd;
				nd->depth = child_nd->depth - 1 > 1 ? child_nd->depth - 1 : 1;
				child_nd->depth = nd->depth > get_height(child_nd->_left) ? nd->depth + 1 : get_height(child_nd->_left) + 1;
				depth_update(nd, nd->depth);
				return (child_nd);
			}
			Node_pointer	LR_rotate(Node_pointer nd)
			{
				RR_rotate(nd->_left);
				return (LL_rotate(nd));
			}
			Node_pointer	RR_rotate(Node_pointer nd)
			{
				std::cout << "Key & nd dep : " << nd->_data.first << " " << nd->depth << std::endl;
				if (nd->_right != ft::nullptr_t)
				{
					std::cout << "Key & rt dep : " << nd->_right->_data.first << " " << nd->_right->depth << std::endl;
					// if (nd->_right->_right != ft::nullptr_t)
					// 	std::cout << "rt dep : " << nd->_left->_data.first << " " << nd->_right->_right->_data.first << std::endl;
				}
				if (nd->_left != ft::nullptr_t)
					std::cout << "Key & lt dep : " << nd->_left->_data.first << " " << nd->_left->depth << std::endl;
				Node_pointer child_nd = nd->_right;
				nd->_right = child_nd->_left;
				if (child_nd->_left != nullptr_t)
					child_nd->_left->_parent = nd;
				child_nd->_left = nd;
				child_nd->_parent = nd->_parent;
				if (nd->_parent != ft::nullptr_t)
				{
					if (_comp(nd->_parent->_data.first, nd->_data.first))
						nd->_parent->_right = child_nd;
					else
						nd->_parent->_left = child_nd;
				}
				nd->_parent = child_nd;
				nd->depth = child_nd->depth - 1 > 1 ? child_nd->depth - 1 : 1;
				child_nd->depth = nd->depth > get_height(child_nd->_right) ? nd->depth + 1 : get_height(child_nd->_right) + 1;
				depth_update(nd, nd->depth);
				return (child_nd);
			}
			Node_pointer	RL_rotate(Node_pointer nd)
			{
				LL_rotate(nd->_right);
				return (RR_rotate(nd));
			}
			void	show_show(Node_pointer root)
			{
				if (root == ft::nullptr_t || root == this->_end)
					return ;
				show_show(root->_right);
				show_show(root->_left);
					std::cout << root->_data.first << " : depth = " << root->depth << std::endl;
			}
		public:
			void	show_me_the_depth()
			{
				Node_pointer root = find_root_node(this->_end->_parent);
				show_show(root);
			}
	};
}

#endif
