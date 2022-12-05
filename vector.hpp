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
			//n이 max_size() 보다 큰 경우 예외처리 reserve가 해줌
			//재할당 할 경우
			if (n > this->_capacity)
			{
				reserve(n);
				for (size_type i = this->_size ; i < n ; i++)
					this->_alloc.construct(this->_data[i], val);
			}
			else
			{
				//축소될 경우
				if (n < this->_size)
					for (size_type i = n ; i < this->_size ; i++)
						this->_alloc.destory(this->_data[i]);
				//채우기
				else if (n > this->_size)
					for (size_type i = this->_size ; i < n ; i++)
						this->_alloc.construct(this->_data[i], val);
			}
			this->_size = n;
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
			if (n > max_size())
				throw std::length_error("ft::vector");
			if (this->_capacity >= n)
				return ;
			pointer temp;
			//할당 실패 시 bad_alloc throw?
			temp = this->_alloc.allocate(n);
			for (size_type i = 0 ; i < this->_size ; i++)
			{
				this->_alloc.construct(temp + i, this->_data[i]);
				this->_alloc.destory(this->_data[i]);
			}
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = temp;
			this->_capacity = n;
		}
		//구현해야되는지 애매함
		// void shrink_to_fit()
		// {
		// }

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

		// Modifieres
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			//기존 요소들 제거 반복자 포인터 참조도 전부 무효화 흙으로 돌아간다.
		}
		void assign(size_type n, const value_type &val)
		{

		}
		void push_back(const value_type &val)
		{

		}
		void pop_back()
		{
			this->_alloc.destory(this->_data + this->_size - 1);
		}
		iterator insert(iterator position, const value_type &val);
		void insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector &x)
		{
			//swap 후에도 반복자는 유효
			//물론 이제는 바뀐 컨테이너를 가리키는
			//ex) iter = vec[0] -> vec.swap(vec2) -> iter = vec2[0] ㅇㅇ
			vector temp;

			temp._data = x._data;
			temp._capacity = x._capacity;
			temp._size = x._size;
			x._data = this->_data;
			x._capacity = this->_capacity;
			x._size = this->_size;
			this->_data = temp._data;
			this->_capacity = temp._capacity;
			this->_size = temp._size;

			//NULL로 안바꾸면 복사된 this의 소멸자에서 문제가 생기나? 확인해봐야됨
			temp._data = NULL;
		}
		void clear()
		{
			//요소만 제거
			for (size_type i = 0 ; i < this->_size ; i++)
				this->_alloc.destory(this->_data[i]);
			this->_size = 0;
		}
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