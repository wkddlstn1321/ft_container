#include<vector>
#include<stack>
#include<map>
#include"map.hpp"
#include"vector.hpp"
#include<list>
// #include<vector>
// #include<list>
// #include<map>
// #include"map.hpp"
// #include"vector.hpp"


using namespace std;

#define T1 int
#define T2 std::string
#define _pair ft::pair
typedef _pair<const T1, T2> T3;
// static int iter = 0;

void leaks() { system("leaks ft_containers"); }

int	main(void)
{
    // atexit(leaks);
	std::map<int, int> newmap2;
	newmap2.insert(std::make_pair(0,3));
	newmap2.insert(std::make_pair(1,3));
	newmap2.insert(std::make_pair(2,13));
	newmap2.insert(std::make_pair(3,3));
	newmap2.insert(std::make_pair(4,3));
	newmap2.insert(std::make_pair(5,3));
	std::map<int, int>::iterator it = newmap2.end();
	// std::map<int, int>::reverse_iterator its = newmap.rend();
	// it++;
	it--;
	cout << it->first << endl;
	// // its--;
	// for ( ; it != its ; it++)
	// 	cout << it->first << endl;


	// ft::map<int, int> newmap;
	// newmap.insert(ft::make_pair(0,3));
	// newmap.insert(ft::make_pair(1,3));
	// newmap.insert(ft::make_pair(2,13));
	// newmap.insert(ft::make_pair(3,3));
	// newmap.insert(ft::make_pair(4,3));
	// newmap.erase(2);
	// cout << newmap2.max_size() << endl;
	// newmap2.insert(newmap.begin(), newmap.end());
	// cout << newmap.max_size() << endl;
	// newmap.insert(ft::make_pair(5,3));
	// ft::map<int, int>::iterator it = newmap.end();
	// it++;
	// it--;
	// cout << it->first << endl;
	// cout << it->first << endl;
	// ft::map<int, int>::reverse_iterator its = newmap.rend();
	// it++;
	// its--;
	// for ( ; it != its ; it++)
	// 	cout << it->first << endl;

	// its = newmap.end();
	// cout << it->first << endl;
	// newmap.erase(it->first);
	// newmap.show_me_the_depth();
	// it--;
	// its = newmap.end();
	// ft::map<int, int>::iterator its;
	// newmap.insert(ft::make_pair(12,3));
	// newmap[5] = 2;
	// newmap[1] = 3123;
	// newmap[2] = 3;
	// newmap[3] = 3;
	// newmap[4] = 3;
	// it = newmap.begin();
	// its = newmap.end();
	// if (it == its)
	// 	std::cout << "????????" << std::endl;
	// std::cout << it->first << std::endl;
	// cout << newmap.erase(1) << endl;
	// cout << "size = " << newmap.size() << endl;
	// cout << "=======================================" << endl;
	// newmap.show_me_the_depth();
	// cout << newmap.upper_bound(18)->first << endl;
	// cout << newmap.lower_bound(18)->first << endl;
	// newmap[1] = 24;

	// ft::map<int, int> map2;
	// std::cout << "insert start~~~~~~~~~~~" << std::endl;
	// map2.insert(newmap.begin(), newmap.end());
	// ft::map<int, int>::iterator it = map2.find(1);
	// std::cout << "map2 : size  = "<< map2.size() << std::endl;

	// newmap.insert(ft::make_pair(11,3));
	// newmap.insert(ft::make_pair(10,3));
	// newmap.insert(ft::make_pair(9,3));
	// newmap.insert(ft::make_pair(8,3));
	// newmap.insert(ft::make_pair(7,3));
	// newmap.insert(ft::make_pair(6,3));
	// newmap.insert(ft::make_pair(5,4));
	// newmap.insert(ft::make_pair(4,3));
	// newmap.insert(ft::make_pair(3,3));
	// newmap.insert(ft::make_pair(2,3));
	// newmap.insert(ft::make_pair(1,3));
	// newmap.show_me_the_depth();
	// newmap.insert(ft::make_pair(2,4));
	// newmap.insert(ft::make_pair(1,4));
	// newmap.insert(ft::make_pair(7,4));
	// newmap.insert(ft::make_pair(0,4));
	// newmap.insert(ft::make_pair(8,4));
	// newmap.insert(ft::make_pair(9,4));
	// newmap.insert(ft::make_pair(12,3));
	// cout << newmap.size() << endl;
	// ft::vector<int> vec(3, 2);
	// std::vector<int> nv = vec;
	// std::vector<int>::iterator it = vec.begin();
	// std::vector<int> vec2(5, 5);
	// vec.swap(vec2);
	// std::vector<int>::iterator its = vec2.end();
	// for ( ; it != its ; it++)
	// {
	// 	cout << *it << endl;
	// }
	// ft::vector<int>::iterator it = vec.begin();
	// ft::vector<int>::iterator its = vec.end();
	// ft::vector<int> vec2(it, its);
	// for (; it != its ; it++ )
	// 	cout << *it << endl;
	// ft::vector<int> newvec(3, 10);
	// ft::vector<int> newvec2;
	// newvec2 = newvec;
	// newMap.erase(newMap.begin());
	// std::map<int, int>::iterator a = newMap.begin();
	// std::map<int, int>::iterator b = newMap.end();
	// a++;
	// (void)a;
	// a--;
	// a--;
	// if (a == b)
	// 	cout << "?" << endl;
	// cout << a->first << endl;
	// for (int i = 0 ; i < 10 ; i++)
	// {
	// 	vec.push_back(i);
	// 	newvec.push_back(i);
	// }
	// ft::vector<int> newvec2(3);
	// std::vector<int> vec2(3);
	// newvec2.assign(1,2);
	// newvec.assign(15,0);
	// vec.assign(15,0);
	// vec2.assign(vec.begin(), vec.end());
	// newvec2.assign(newvec.begin(), newvec.end());
	// newvec.insert(newvec.begin(), newvec.begin() + 2, newvec.end());
	// std::vector<int>vec2(vec.begin(), vec.end());
	// cout << "newvec     " << newvec.empty() << endl;
	// cout << "vec        " << vec.empty() << endl;
	// cout << "newvec.size     " << newvec.size() << endl;
	// cout << "vec.size        " << vec.size() << endl;
	// cout << "newvec.capacity " << newvec.capacity() << endl;
	// cout << "vec.capacity    " << vec.capacity() << endl;
	// vector<int>::iterator vit = vec.begin();
	// vector<int>::iterator vits = vec.end();
	// ft::vector<int>::iterator it = newvec2.begin();
	// ft::vector<int>::iterator its = newvec2.end();
	// cout << vit + vit<< endl;
	// cout << it + it << endl;
	// cout << "================ft::vec===============" << endl;
	// cout << *(newvec.insert(newvec.begin(), 40)) << endl;
	// for ( ; it != its ; it++)
	// 	cout << *it << endl;
	// cout << "====================vec===============" << endl;
	// cout << *(vec.insert(vec.begin(), 40)) << endl;
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

  node_pointer __search_parent(const value_type& value, node_pointer position = ft::nil) {
    if (position && position != __end) {
      if (__comp(value, position->__value) && position->__left == __nil) {
        iterator prev = iterator(position, __nil);
        if (prev == begin() || __comp(*--prev, value)) {
          return position;
        }
      } else if (position->__right == __nil) {
        iterator next = iterator(position, __nil);
        if (next == end() || __comp(value, *++next)) {
          return position;
        }
      }
    }
*/

