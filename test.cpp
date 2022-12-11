#include"vector.hpp"
#include<vector>
#include<iostream>
#include<memory>
#include<exception>
#include<type_traits>
using namespace std;

int	main(void)
{
	std::allocator<int> a;
	std::vector<int> vec;
	ft::vector<int> newvec(10, 3);
	std::allocator<int> alloc;
	// for (int i = 0 ; i < 10 ; i++)
	// {
	// 	newvec.push_back(i);
	// }
	// cout << newvec.size() << " " << newvec.capacity() << endl;
	// newvec.push_back(999);
	// newvec.push_back(999);
	// newvec.push_back(999);
	// ft::vector<int>::iterator it = newvec.begin();
	// ft::vector<int>::iterator its = newvec.end();
	// cout << *it << endl;
	// for ( ; it != its; it++)
	// std::copy(it, its, vec.begin());
	// vec.assign(it, its);
	// it = vec.begin();
	// its = vec.end();
}

/*
void __init(size_type n)
{
	if (n > max_size())
	{
		throw std::length_error("allocation size too big");
	}
	__begin = __alloc.allocate(n);
	__end = __begin;
	__cap = __begin + n;
}

void __construct(size_type n)
{
	for (; n > 0; __end++, n--)
	{
		__alloc.construct(__end);
	}
}

void __construct(size_type n, T value) {
	for ( ; n > 0 ; __end++, n--)
	{
		__alloc.construct(__end);
		*__end = value;
	}
}

void __destruct(size_type n)
{
	for (; n > 0 && __end--; n--)
	{
		__alloc.destroy(__end);
	}
}

void __destruct(pointer until)
{
	for (; __end != until && __end--;)
	{
		__alloc.destroy(__end);
	}
}
*/