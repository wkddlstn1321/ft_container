#include<ctime>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include"vector.hpp"
#include"stack.hpp"
#include"map.hpp"

static int	test_i = 0;
static int	con = 0;
static	std::string s[3] = {"vector", "stack", "map"};

void	print_time_compare(size_t ft, size_t std)
{
	std::cout << "\nft::" << s[con];
	con++;
	if (ft < std)
	{
		std::cout << " is " << "std 보다 더 빠름" << std::endl;
	}
	else
	{
		std::cout << " is " << ft / std << "배 느림" << std::endl;
	}
	std::cout << std::endl;
}

template<class vector>
int	vector_time_test(size_t seed, vector vec)
{
	std::clock_t time = std::clock();
	for (size_t i = 0 ; i < seed ; i++)
	{
		vec.push_back(i);
		vec[i] = i * 0;
		vec.at(i);
	}
	{
		vector newvec(vec);
		newvec.assign(vec.begin(), vec.end());
		newvec.insert(newvec.begin(), vec.begin(), vec.end());
		vector newvec2;
		newvec2.swap(newvec);
	}
	vec.erase(vec.begin(), vec.end());
	std::clock_t result = std::clock() - time;
	if (test_i == 0)
	{
		std::cout << "ft::vector test times = " << result / CLOCKS_PER_SEC << "s(" << result << "ms)" << std::endl;
		test_i = 1;
	}
	else
	{
		std::cout << "std::vector test times = " << result / CLOCKS_PER_SEC << "s(" << result << "ms)" << std::endl;
		test_i = 0;
	}
	return (result);
}

template<class stack>
int	stack_time_test(size_t seed, stack st)
{
	std::clock_t time = std::clock();
	for (size_t i = 0 ; i < seed ; i++)
	{
		st.push(i);
	}
	{
		stack newst(st);
	}
	for (size_t i = 0 ; i < seed ; i++)
	{
		st.pop();
	}
	std::clock_t result = std::clock() - time;
	if (test_i == 0)
	{
		std::cout << "ft::stack test times = " << result / CLOCKS_PER_SEC << "s(" << result << "ms)" << std::endl;
		test_i = 1;
	}
	else
	{
		std::cout << "std::stack test times = " << result / CLOCKS_PER_SEC << "s(" << result << "ms)" << std::endl;
		test_i = 0;
	}
	return (result);
}

template<class Map>
int	map_time_test(size_t seed, Map map)
{
	std::clock_t time = std::clock();
	for (size_t i = 0 ; i < seed ; i++)
	{
		map[i] = i * 0;
		map.find(i);
		map.at(i);
	}
	{
		Map newmap(map);
		newmap.clear();
		newmap.insert(newmap.begin(), newmap.end());
	}
	map.erase(map.begin(), map.end());
	std::clock_t result = std::clock() - time;
	if (test_i == 0)
	{
		std::cout << "ft::map test times = " << result / CLOCKS_PER_SEC << "s(" << result << "ms)" << std::endl;
		test_i = 1;
	}
	else
	{
		std::cout << "std::map test times = " << result / CLOCKS_PER_SEC << "s(" << result << "ms)" << std::endl;
		test_i = 0;
	}
	return (result);
}

int	main(int ac, char **av)
{
	ft::vector<int>		fv;
	ft::stack<int>		fst;
	ft::map<int, int>	fmap;
	std::vector<int>	sv;
	std::stack<int>		sst;
	std::map<int, int>	smap;
	size_t				seed;

	if (ac != 2)
	{
		std::cout << "./ft_container [seed]" << std::endl;
		return (0);
	}
	seed = atoi(av[1]);
	std::cout << "################ vector ####################" << std::endl;
	print_time_compare(vector_time_test(seed, fv), vector_time_test(seed, sv));
	std::cout << "################ stack ####################" << std::endl;
	print_time_compare(stack_time_test(seed, fst), stack_time_test(seed, sst));
	std::cout << "################ map ####################" << std::endl;
	print_time_compare(map_time_test(seed, fmap), map_time_test(seed, smap));
}
