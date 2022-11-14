#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template <typename T>
	class Alloc
	{
	};

	template <typename T, typename  Alloc = Alloc<T> >
	class vector
	{
	private:
		T	*data;
		int capacity;
		int	length;
		int	size;
	public:
		explicit vector(const allocator_type &alloc = allocator_type())
		{

		}
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{

		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{

		}
		vector(const vector &x)
		{

		}
		// vector()
		// {
		// 	this->capacity = 10;
		// }
		// ~vector()
		// {
		// }
		// Capacity
		// size_type size() const
		// {
		// 	return static_cast<size_type>(this->__end_ - this->__begin_);
		// }
		// size_type max_size() const;
		// void resize (size_type n, value_type val = value_type());
		// size_type capacity() const
		// {
		// 	return static_cast<size_type>(__end_cap() - __begin_);
		// }
		// bool empty() const
		// {
		// 	return this->__begin_ == this->__end_;
		// }
		// void reserve (size_type n);
		// void shrink_to_fit();

		// // Element access
		// reference operator[] (size_type n);const_reference operator[] (size_type n) const;
		// reference at (size_type n);
		// const_reference at (size_type n) const;
		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;
		// value_type* data() noexcept;
		// const value_type* data() const noexcept;

		// // Modifieres
		// template <class InputIterator>  void assign (InputIterator first, InputIterator last);
		// void assign (size_type n, const value_type& val);
		// void push_back (const value_type& val);
		// void pop_back();
		// iterator insert (iterator position, const value_type& val);
    	// void insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
		// iterator erase (iterator position);iterator erase (iterator first, iterator last);
		// void swap (vector& x);
		// void clear();
		// template <class... Args>iterator emplace (const_iterator position, Args&&... args);
		// template <class... Args>  void emplace_back (Args&&... args);

		// // Allocator
		// allocator_type get_allocator() const;

		// //non member func
		// template <class T, class Alloc>
		// bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
	};
}

#endif