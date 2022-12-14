#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include<iterator>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirection_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirection_iterator_tag {};

	template <class Category,              // iterator::iterator_category
			  class T,                     // iterator::value_type
			  class Distance = ptrdiff_t,  // iterator::difference_type
			  class Pointer = T*,          // iterator::pointer
			  class Reference = T&         // iterator::reference
			  > class iterator
	{
		typedef	T value_type;
		typedef	Distance difference_type;
		typedef	Pointer pointer;
		typedef	Reference reference;
		typedef	Category iterator_category;
	};
}

#endif