#ifndef MAP_HPP
#define MAP_HPP

#include<memory>
#include"utility.hpp"

namespace ft
{
	template <class Key,											// map::key_type
			  class T,												// map::mapped_type
			  class Compare = std::less<Key>,						// map::key_compare
			  class Alloc = std::allocator<ft::pair<const Key, T>>> // map::allocator_type
	class map
	{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const Key, T>						value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;

		// typedef typename allocator_type::template rebind<value_type>::other type_allocator;
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
	};
}

#endif