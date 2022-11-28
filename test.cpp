// #include"vector.hpp"
#include<vector>
#include<iostream>
#include<memory>

using namespace std;

int	main(void)
{
	// allocator<int> alloc;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vector<int>::iterator go_end = vec.end();
	vec.resize(3, 123);
	vector<int>::iterator beg = vec.begin();
	vector<int>::iterator end = vec.end();
	for ( ; beg != end ; beg++)
	{
		cout << *beg << endl;
	}
	cout << *(go_end - 1) << endl;
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
