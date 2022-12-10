#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
#include"vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T>>
	class stack
	{
	private:
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		// member func
		explicit stack(const container_type &ctnr = container_type())
		{
		}
		~stack()
		{
		}
		stack &operator=(const stack &other)
		{
		}
		bool empty() const
		{
		}
		size_type size() const
		{
		}
		value_type &top()
		{
		}
		const value_type &top() const
		{
		}
		void push(const value_type &val)
		{
		}
		void pop()
		{
		}
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
	}
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{

	}
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{

	}
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{

	}
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{

	}
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{

	}
}

#endif