#include"vector.hpp"
#include<vector>
#include<iostream>
#include<memory>
#include<exception>
#include<type_traits>
using namespace std;

int	main(void)
{

	std::vector<int> vec;
	ft::vector<int> newvec;
	for (int i = 0 ; i < 10 ; i++)
	{
		newvec.push_back(i);
	}
	// newvec.push_back(999);
	// newvec.push_back(999);
	// newvec.push_back(999);
	ft::vector<int>::iterator it = newvec.begin();
	ft::vector<int>::iterator its = newvec.end();
	// cout << *it << endl;
	// for ( ; it != its; it++)
	// std::copy(it, its, vec.begin());
	// vec.assign(it, its);
	// it = vec.begin();
	// its = vec.end();
	// cout << vec.size() << endl;
	// cout << its - it - 5 << endl;
	// int	i = 0;
	// for (; it != its ; it++, i++)
	// 	cout << *it << " i = " << i << endl;
	// cout << vec.size();
	// test(iter);
	// cout << vec[-1] << endl;
	// while (!vec.empty())
	// {
	// 	cout << vec.back() <<endl;
	// 	vec.pop_back();
	// }
	// vec.pop_back();
	// vec.pop_back();

	// vec.shrink_to_fit();
	// vector<int>::iterator go_end = vec.end();
	// vec.resize(6, 123);
	// vector<int>::iterator beg = vec.begin();
	// vector<int>::iterator end = vec.end();
	// vec.shrink_to_fit();
	// vec.push_back(1);
	// for ( ; beg != end ; beg++)
	// {
	// 	cout << *beg << endl;
	// }
	// cout << *(go_end - 1) << endl;
	// cout << alloc.max_size() << endl;
	// std::vector<int> vec2();
	// std::vector<int>::iterator i = vec.begin();
	// std::vector<int>::iterator j = vec.end();
	// // std::cout << vec.capacity() << std::endl;
	// vec.push_back(5);
	// std::cout << vec.capacity() << std::endl;
	// vec.shrink_to_fit();
	// std::cout << vec.capacity() << std::endl;
	// vec.push_back(5);
	// std::cout << vec.capacity() << std::endl;
	// vec.insert(vec.begin(), 2);
	// std::cout << vec.size() << "  " << *vec.begin() << std::endl;
	// vec.swap(vec2);
	// for (i = vec2.begin(), j = vec2.end() ; i != j ; i++)
	// {
	// 	std::cout << *i << std::endl;
	// }
}
