#include<vector>
#include"vector.hpp"

using namespace std;

int	main(void)
{
	// std::vector<int> vec(3, 2);
	std::vector<int> vec;
	ft::vector<int> newvec;
	for (int i = 0 ; i < 10 ; i++)
	{
		vec.push_back(i);
		newvec.push_back(i);
	}
	vec.insert(vec.begin(), vec.begin() + 2, vec.end());
	newvec.insert(newvec.begin(), newvec.begin() + 2, newvec.end());
	cout << "newvec     " << newvec.empty() << endl;
	cout << "vec        " << vec.empty() << endl;
	cout << "newvec.size     " << newvec.size() << endl;
	cout << "vec.size        " << vec.size() << endl;
	cout << "newvec.capacity " << newvec.capacity() << endl;
	cout << "vec.capacity    " << vec.capacity() << endl;
	vector<int>::iterator vit = vec.begin();
	vector<int>::iterator vits = vec.end();
	ft::vector<int>::iterator it = newvec.begin();
	ft::vector<int>::iterator its = newvec.end();
	// cout << vit + vit<< endl;
	// cout << it + it << endl;
	cout << "================ft::vec===============" << endl;
	// cout << *(newvec.insert(newvec.begin(), 40)) << endl;
	for ( ; it != its ; it++)
		cout << *it << endl;
	cout << "====================vec===============" << endl;
	// cout << *(vec.insert(vec.begin(), 40)) << endl;
	for (; vit != vits ; vit++)
		cout << *vit << endl;
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

void reserve(size_type n) {
	if (n <= size() || n <= capacity()) {
	  return;
	}
	if (n < capacity() * 2) {
	  n = capacity() * 2;
	}
	size_type pre_size = size();
	size_type pre_capacity = capacity();
	pointer begin = __alloc.allocate(n);
	std::uninitialized_copy(__begin, __end, begin);
	__destruct(__begin);
	__alloc.deallocate(__begin, pre_capacity);
	__begin = begin;
	__end = __begin + pre_size;
	__cap = __begin + n;
  }
*/
