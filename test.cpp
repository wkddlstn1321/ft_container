// #include"vector.hpp"
#include<vector>
#include<iostream>

int	main(void)
{
	std::vector<int> vec = {1,2,3,4,5};
	std::vector<int> vec2;
	std::vector<int>::iterator i = vec.begin();
	std::vector<int>::iterator j = vec.end();
	// std::cout << vec.capacity() << std::endl;
	vec.push_back(5);
	std::cout << vec.capacity() << std::endl;
	vec.shrink_to_fit();
	std::cout << vec.capacity() << std::endl;
	vec.push_back(5);
	std::cout << vec.capacity() << std::endl;
	// vec.insert(vec.begin(), 2);
	// std::cout << vec.size() << "  " << *vec.begin() << std::endl;
	// vec.swap(vec2);
	// for (i = vec2.begin(), j = vec2.end() ; i != j ; i++)
	// {
	// 	std::cout << *i << std::endl;
	// }
}
