#ifndef MAP_HPP
#define MAP_HPP

#include<memory>

#include"_tree.hpp"
#include"utility.hpp"
#include"algorithm.hpp"
#include"functional.hpp"
#include"reverse_iterator.hpp"

namespace ft
{
	template <class Key,											// map::key_type
			  class T,												// map::mapped_type
			  class Compare = ft::less<Key>,						// map::key_compare
			  class Alloc = std::allocator<ft::pair<const Key, T> > >// map::allocator_type
	class map
	{
	public:
		typedef Key															key_type;
		typedef T															mapped_type;
		typedef ft::pair<const Key, T>										value_type;
		typedef Compare														key_compare;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef std::ptrdiff_t												difference_type;
		typedef std::size_t													size_type;
		typedef typename allocator_type::template rebind<value_type>::other	type_allocator;
		typedef std::allocator_traits<type_allocator>						type_traits;

		typedef typename ft::_AvlTree<value_type, key_type, key_compare>::iterator						iterator;
		typedef typename ft::_AvlTree<value_type, key_type, key_compare>::const_iterator				const_iterator;
		typedef typename ft::reverse_iterator<iterator>													reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>											const_reverse_iterator;
	private:
		key_compare													_comp;
		allocator_type												_alloc;
		_AvlTree<value_type, key_type, key_compare, allocator_type>	_tree;
	public:
		//value_compare class~
		class value_compare : public ft::binary_function<value_type, value_type, bool>
		{
			friend class map<Key, T, Compare, Alloc>;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}
			public:
				bool operator()(const value_type &x, const value_type &y) const
				{
					return (comp(x.first, y.first));
				}
		};

		// Member func
		// construct
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _tree(_alloc, _comp) {}
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nullptr_t)
		:_comp(comp), _alloc(alloc) ,_tree(_alloc, _comp)
		{
			insert(first, last);
		}
		map (const map& x) :  _comp(x._comp), _alloc(x._alloc), _tree(x._tree) { }
		~map()
		{
			// std::cout << "map destructor" << std::endl;
			clear();
		}
		map& operator= (const map& x)
		{
			if (&x != this)
			{
				this->_tree = x._tree;
			}
			return (*this);
		}

		//iterator
		iterator begin()
		{
			return (iterator(_tree.begin()));
		}
		const_iterator begin() const
		{
			return (const_iterator(_tree.begin()));
		}
		iterator end()
		{
			return (iterator(_tree.end()));
		}
		const_iterator end() const
		{
			return (const_iterator(_tree.end()));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(_tree.end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_tree.end()));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(_tree.begin()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_tree.begin()));
		}

		//capacity
		bool empty() const
		{
			return (_tree.empty());
		}
		size_type size() const
		{
			return (_tree.size());
		}
		size_type max_size() const
		{
			return (_tree.max_size());
		}

		//Element access
		mapped_type& operator[] (const key_type& k)
		{
			//find(k) == _tree.end() 면? 없는경우
			//거짓이면 이미 있는 경우
			if (find(k) == this->_tree.end())
				return (insert(ft::make_pair(k, mapped_type())).first->second);
			else
				return find(k)->second;
		}
		mapped_type &at(const key_type &k)
		{
			if (find(k) == this->_tree.end())
				throw std::out_of_range("out_of_range");
			return (find(k)->second);
		}
		const mapped_type &at(const key_type &k) const
		{
			if (find(k) == this->_tree.end())
				throw std::out_of_range("out_of_range");
			return (find(k)->second);
		}

		//Modifiers
		pair<iterator,bool> insert (const value_type& val)
		{
			return (_tree.insert(val));
		}
		iterator insert (iterator position, const value_type& val)
		{
			return (_tree.insert(position, val));
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			return (_tree.insert(first, last));
		}
		void erase (iterator position)
		{
			_tree.erase(position);
		}
		size_type erase (const key_type& k)
		{
			return (_tree.erase(k));
		}
		void erase (iterator first, iterator last)
		{
			_tree.erase(first, last);
		}
		void swap (map& x)
		{
			_tree.swap(x._tree);
		}
		void clear()
		{
			erase(begin(), end());
		}

		//Observers
		key_compare key_comp() const
		{
			return (_comp);
		}
		value_compare value_comp() const
		{
			return (value_compare(_comp));
		}

		//Operations
		iterator find (const key_type& k)
		{
			return (this->_tree.find(k));
		}
		const_iterator find (const key_type& k) const
		{
			return (this->_tree.find(k));
		}
		size_type count (const key_type& k) const
		{
			return (this->_tree.count(k));
		}
		iterator lower_bound (const key_type& k)
		{
			return (this->_tree.lower_bound(k));
		}
		const_iterator lower_bound (const key_type& k) const
		{
			return (this->_tree.lower_bound(k));
		}
		iterator upper_bound (const key_type& k)
		{
			return (this->_tree.upper_bound(k));
		}
		const_iterator upper_bound (const key_type& k) const
		{
			return (this->_tree.upper_bound(k));
		}
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (this->_tree.equal_range(k));
		}
		pair<iterator,iterator> equal_range (const key_type& k)
		{
			return (this->_tree.equal_range(k));
		}

		//Allocator
		allocator_type get_allocator() const
		{
			return (_tree.get_allocator());
		}
		// template <class _K, class _T, class _C, class _A>
		// friend bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);
		// template <class _K, class _T, class _C, class _A>
		// friend bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
}


#endif