#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include<iterator>
#include"iterator_traits.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public std::iterator<std::input_iterator_tag, T>
	{
	private:

	public:
		typedef T*																iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
	};
}

#endif