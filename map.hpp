#ifndef MAP_HPP
#define MAP_HPP

#include<memory>
#include<functional>

#include"_tree.hpp"
#include"utility.hpp"
#include"reverse_iterator.hpp"
#include"bidirectional_iterator.hpp"

namespace ft
{
	template <class Key,											// map::key_type
			  class T,												// map::mapped_type
			  class Compare = std::less<Key>,						// map::key_compare
			  class Alloc = std::allocator<ft::pair<const Key, T>> >// map::allocator_type
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
		typedef typename ft::_tree<value_type>::iterator					iterator;
		// typedef typename ft::_tree<const value_type>		const_iterator;
		typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef std::ptrdiff_t												difference_type;
		typedef std::size_t													size_type;

		typedef typename allocator_type::template rebind<value_type>::other	type_allocator;
		typedef std::allocator_traits<type_allocator>						type_traits;

	private:
		key_compare		_comp;
		allocator_type	_alloc;

	public:
		//value_compare class~
		template <class Key, class T, class Compare, class Alloc>
		class map<Key, T, Compare, Alloc>::value_compare : std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};
		// Member func
		// construct
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: _comp(comp), _alloc(alloc)
		{
		}
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
		}
		map (const map& x) : _alloc(x._alloc), _comp(x._comp)
		{
			insert(x.begin(), x.end());
		}
		//destructor
		~map()
		{
			clear();
		}
		map& operator= (const map& x)
		{
			if (&x != this)
			{
				clear();
				insert(x.begin(), x.end());
			}
			return (*this);
		}

		//iterator
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		//capacity
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		//Element access
		mapped_type& operator[] (const key_type& k)
		{
		}
		mapped_type &at(const key_type &k);
		const mapped_type &at(const key_type &k) const;

		//Modifiers
		pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);
		void erase (iterator position);
		size_type erase (const key_type& k);
		void erase (iterator first, iterator last);
		void swap (map& x);
		void clear()
		{
			erase(begin(), end());
		}

		//Observers
		key_compare key_comp() const;
		value_compare value_comp() const;

		//Allocator
		allocator_type get_allocator() const;
	};
}

#endif