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
	newvec.assign(1,1);
	cout << "newvec     " << newvec.empty() << endl;
	cout << "vec        " << vec.empty() << endl;
	cout << "newvec.size     " << newvec.size() << endl;
	cout << "vec.size        " << vec.size() << endl;
	cout << "newvec.capacity " << newvec.capacity() << endl;
	cout << "vec.capacity    " << vec.capacity() << endl;
	vector<int>::iterator vit;
	vector<int>::iterator vits;
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator its;
	it = newvec.begin();
	its = newvec.end();
	vit = vec.begin();
	vits = vec.end();
	cout << *(it) << endl;
	// for ( ; it != its ; it++)
	// 	cout << *it << endl;
	// for (; vit != vits ; vit++)
	// 	cout << *vit << endl;
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