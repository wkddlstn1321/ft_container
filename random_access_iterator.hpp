#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include"iterator.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
	protected:
		T*											_pointer;
		typedef	typename ft::iterator_traits<T*>	_trait_type;

	public:
		typedef T*										iterator_type;
		typedef typename _trait_type::iterator_category	iterator_category;
		typedef typename _trait_type::value_type		value_type;
		typedef typename _trait_type::difference_type	difference_type;
		typedef typename _trait_type::pointer			pointer;
		typedef typename _trait_type::reference			reference;


	public:
		//copy ,default construct & copy assignable & destruct
		random_access_iterator()
		{
			this->_pointer = NULL;
		}
		random_access_iterator(T* pointer)
		{
			this->_pointer = pointer;
		}
		random_access_iterator(const random_access_iterator<T>& a)
		{
			this->_pointer = a.base();
		}
		~random_access_iterator() {}
		random_access_iterator&	operator=(const random_access_iterator<T>& a)
		{
			this->_pointer = a.base();
			return (*this);
		}
		iterator_type base() const
		{
			return (this->_pointer);
		}
		reference operator*() const
		{
			return (*(this->_pointer));
		}
		random_access_iterator operator+ (difference_type n) const
		{
			return (random_access_iterator(this->_pointer + n));
		}
		random_access_iterator& operator++()
		{
			++this->_pointer;
			return (*this);
		}
		random_access_iterator  operator++(int)
		{
			random_access_iterator tmp = (*this);
			++this->_pointer;
			return (tmp);
		}
		reference& operator+= (difference_type n)
		{
			this->_pointer += n;
			return (*this);
		}
		random_access_iterator operator- (difference_type n) const
		{
			return (random_access_iterator(this->_pointer - n));
		}
		random_access_iterator& operator--()
		{
			--this->_pointer;
			return (*this);
		}
		random_access_iterator  operator--(int)
		{
			random_access_iterator tmp = *this;
			--this->_pointer;
			return (tmp);
		}
		random_access_iterator& operator-= (difference_type n)
		{
			this->_pointer -= n;
			return (*this);
		}
		pointer operator->() const
		{
			return (this->_pointer);
		}
		reference operator[] (difference_type n) const
		{
			return (*(this->_pointer + n));
		}
	};
	// relational operator
	template <class Iterator1, class Iterator2>
	bool operator==(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator!=(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Iterator1, class Iterator2>
	bool operator<(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
	{
		return (rhs.base() < lhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator<=(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class Iterator1, class Iterator2>
	bool operator>(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
	{
		return (rhs < lhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator>=(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
	{
		return (!(lhs < rhs));
	}
	template <class Iterator>
	random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &rev_it)
	{
		return (random_access_iterator<Iterator>(rev_it.base() + n));
	}
	template <class Iterator1, class Iterator2>
	typename random_access_iterator<Iterator1>::difference_type operator-(const random_access_iterator<Iterator2> &lhs, const random_access_iterator<Iterator1> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

}

#endif