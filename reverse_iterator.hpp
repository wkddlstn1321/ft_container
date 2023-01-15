#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include"iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		protected:
		Iterator _iter;
		typedef	typename ft::iterator_traits<Iterator>	_trait_type;

		public:
		typedef Iterator								iterator_type;
		typedef typename _trait_type::iterator_category	iterator_category;
		typedef typename _trait_type::value_type		value_type;
		typedef typename _trait_type::difference_type	difference_type;
		typedef typename _trait_type::pointer			pointer;
		typedef typename _trait_type::reference			reference;

		//construct
		reverse_iterator() : _iter() {}
		explicit reverse_iterator (iterator_type it) : _iter(it) {}
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it.base()) {}
		//Member func
		iterator_type base() const
		{
			return (this->_iter);
		}
		reference operator*() const
		{
			Iterator tmp = this->_iter;
			return (*--tmp);
		}
		reverse_iterator operator+ (difference_type n) const
		{
			return (reverse_iterator(this->_iter - n));
		}
		reverse_iterator& operator++()
		{
			--this->_iter;
			return (*this);
		}
		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp = *this;
			--this->_iter;
			return (tmp);
		}
		reverse_iterator& operator+= (difference_type n)
		{
			this->_iter -= n;
			return (*this);
		}
		reverse_iterator operator- (difference_type n) const
		{
			return (reverse_iterator(this->_iter + n));
		}
		reverse_iterator& operator--()
		{
			++this->_iter;
			return (*this);
		}
		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp = *this;
			++this->_iter;
			return (tmp);
		}
		reverse_iterator& operator-= (difference_type n)
		{
			this->_iter += n;
			return (*this);
		}
		pointer operator->() const
		{
			return (&operator*());
		}
		reference operator[] (difference_type n) const
		{
			return (*(*this + n));
		}
	};
	//Non Member func
	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (rhs.base() < lhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (rhs < lhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (!(lhs < rhs));
	}

// template <class _Iter>
	// inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
	// 	reverse_iterator<_Iter>
	// 	operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter> &__x)
	// {
	// 	return reverse_iterator<_Iter>(__x.base() - __n);
	// }

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}
	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif