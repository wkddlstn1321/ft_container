#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <algorithm>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const_value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename allocator_type::size_type				size_type;

	//friend keyword need protected not private
	protected:
		allocator_type	_alloc;
		pointer			_data;
		size_type		_capacity;
		size_type		_size;

	public:
		//construct
		explicit vector(const allocator_type &alloc = allocator_type())
		{
			this->_alloc = alloc;
			this->_data = 0;
			this->_capacity = 0;
			this->_size = 0;
		}
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			this->_alloc = alloc;
			//n 이 vector로 할당할 수 있는 최대크기보다 큰지 체크 해야됨
			this->_data = this->_alloc.allocate(n);
			this->_capacity = n;
			this->_size = n;
			for (size_type i = 0 ; i < n ; i++)
			{
				this->_alloc.construct(this->_data + i, val);
			}
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{

		}
		vector(const vector &x)
		{

		}

		//destructor
		~vector()
		{
			this->_alloc.deallocate(this->_data, this->capacity);
		}

		//Capacity
		size_type size() const
		{
			return (this->_size);
		}
		size_type max_size() const
		{
			return (this->_alloc.maxsize());
		}
		//size 현재 크기보다 작아져도 반복자는 유지되어야 함
		void resize(size_type n, value_type val = value_type())
		{

		}
		size_type capacity() const
		{
			return (this->_capacity);
		}
		bool empty() const
		{
			return (this->_size = 0);
		}
		void reserve (size_type n)
		{

		}
		void shrink_to_fit()
		{

		}

		//Element access
		reference operator[](size_type n)
		{
			return (this->_data[n]);
		}
		const_reference operator[](size_type n) const
		{
			return (this->_data[n]);
		}
		reference at(size_type n)
		{
			if (n > 0 && n < this->_size)
				return (this->_data[n]);
			else
				throw std::out_of_range("out_of_range");
		}
		const_reference at(size_type n) const
		{
			if (n > 0 && n < this->_size)
				return (this->_data[n]);
			else
				throw std::out_of_range("out_of_range");
		}
		reference front()
		{
			return (*this->_data);
		}
		const_reference front() const
		{
			return (*this->_data);
		}
		reference back()
		{
			return (*(this->_data + this->size - 1))
		}
		const_reference back() const
		{
			return (*(this->_data + this->size - 1))
		}
		value_type *data() noexcept
		{
			return (this->_data);
		}
		const value_type *data() const noexcept
		{
			return (this->_data);
		}

		// // Modifieres
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const value_type &val);
		void push_back(const value_type &val);
		void pop_back();
		iterator insert(iterator position, const value_type &val);
		void insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector &x)
		{
			
		}
		void clear();
		template <class... Args>
		iterator emplace(const_iterator position, Args &&...args);
		template <class... Args>
		void emplace_back(Args &&...args);

		// Allocator
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

		//non member func
		template <class T, class Alloc>
		bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		template <class T, class Alloc>
		bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (!(lhs == rhs));
		}
		template <class T, class Alloc>
		bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		template <class T, class Alloc>
		bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (!(rhs < lhs))
		}
		template <class T, class Alloc>
		bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (rhs < lhs);
		}
		template <class T, class Alloc>
		bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (!(rhs < lhs));
		}
		template <class T, class Alloc>
		void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
		{
			x.swap(y);
		}
	};
}

#endif