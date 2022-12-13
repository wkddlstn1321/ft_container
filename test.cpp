#include<vector>
#include"vector.hpp"

using namespace std;

int	main(void)
{
	std::vector<int> vec;
	ft::vector<int> newvec(3, 2);
	ft::vector<int> newvec2(newvec);
	// for (int i = 0 ; i < 10 ; i++)
	// {
	// 	newvec.push_back(i);
	// 	vec.push_back(i);
	// }
	// ft::vector<int> newvec2(newvec);
	// cout << "this.size = " << newvec2.capacity() << endl;
	// cout << "vec .size = " << vec.capacity() << endl;
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