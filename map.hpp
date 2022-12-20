#ifndef MAP_HPP
#define MAP_HPP

#include<memory>
#include"utility.hpp"
#include"reverse_iterator.hpp"
#include"bidirectional_iterator.hpp"

namespace ft
{
	template <class Key,											// map::key_type
			  class T,												// map::mapped_type
			  class Compare = std::less<Key>,						// map::key_compare
			  class Alloc = std::allocator<ft::pair<const Key, T>>> // map::allocator_type
	class map
	{
	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const Key, T>									value_type;
		typedef Compare													key_compare;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename ft::bidirectional_iterator<value_type>			iterator;
		typedef typename ft::bidirectional_iterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t											difference_type;
		typedef std::size_t												size_type;

		typedef typename allocator_type::template rebind<value_type>::other type_allocator;
		// typedef std::allocator_traits<type_allocator> type_traits;
		

		//Member func
		//construct
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{

		}
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{

		}
		map (const map& x)
		{
			
		}
		//destructor
		~map()
		{
		}
		map& operator= (const map& x);

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
		mapped_type& operator[] (const key_type& k);
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
		void clear();

		//Observers
		key_compare key_comp() const;
		value_compare value_comp() const;

		//Allocator
		allocator_type get_allocator() const;
	};
}

#endif