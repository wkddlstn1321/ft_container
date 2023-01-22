#ifndef STACK_HPP
#define STACK_HPP

#include"vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	protected:
		container_type c;

	public:
		// member func
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}
		~stack() {}
		stack &operator=(const stack &other)
		{
			if (this != &other)
				c = other.c;
			return (*this);
		}
		bool empty() const
		{
			return (c.empty());
		}
		size_type size() const
		{
			return (c.size());
		}
		value_type &top()
		{
			return (c.back());
		}
		const value_type &top() const
		{
			return (c.back());
		}
		void push(const value_type &val)
		{
			c.push_back(val);
		}
		void pop()
		{
			c.pop_back();
		}
		template <class T1, class _Container>
		friend bool operator==(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs);
		template <class T1, class _Container>
		friend bool operator<(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs);
	};
	template <class T1, class _Container>
	bool operator==(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class T1, class _Container>
	bool operator!=(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T1, class _Container>
	bool operator<(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class T1, class _Container>
	bool operator<=(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T1, class _Container>
	bool operator>(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs)
	{
		return (rhs < lhs);
	}
	template <class T1, class _Container>
	bool operator>=(const stack<T1, _Container> &lhs, const stack<T1, _Container> &rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif