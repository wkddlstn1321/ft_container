// #include"vector.hpp"
#include<vector>
#include<iostream>

using namespace std;

template <typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}

template <>
double max(double a, double b)
{
	cout << a << " " << b << "중 큰수는 ? " << endl;
	return (a > b ? a : b);
}

int	main(void)
{
	cout << max(5, 6) << endl;
	cout << max(12.5, 16.7) << endl;
	// std::vector<int> vec = {1,2,3,4,5};
	// std::vector<int> vec2;
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
