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

		public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		//construct
		reverse_iterator() {}
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
			reverse_iterator(this->_iter - n);
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
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() < lhs.base());
	}
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs < lhs);
	}
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (!(lhs < rhs));
	}
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

}

#endif