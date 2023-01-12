#include<vector>
#include<map>
#include"map.hpp"
#include"vector.hpp"

using namespace std;

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}



void leaks() { system("leaks ft_containers"); }
int	main(void)
{
    // atexit(leaks);

	ft::vector<int> vct(10);
	ft::vector<int> vct2;
	ft::vector<int> vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);
	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);

	vct2.resize(4);
	printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	printSize(vct);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	printSize(vct3);
	return (0);

	// std::vector<int> newvec2;
	// for (int i = 0 ; i < 10 ; i++)
	// 	newvec.push_back(i);
	// newvec.insert(newvec.begin(), newvec.begin(), newvec.end() - 5);
	// ft::vector<int>::iterator it = newvec.begin();
	// ft::vector<int>::const_iterator its = it;
	// for ( ; it != its ; it++)
	// 	cout << *it << endl;
	// ft::map<int, int> newmap;
	// newmap.insert(ft::make_pair(18,3));
	// newmap.insert(ft::make_pair(16,3));
	// newmap.insert(ft::make_pair(17,3));
	// newmap.insert(ft::make_pair(15,13));
	// newmap.insert(ft::make_pair(14,3));
	// newmap.insert(ft::make_pair(13,3));
	// newmap.insert(ft::make_pair(12,3));
	// newmap[5] = 2;
	// newmap[1] = 3123;
	// newmap[2] = 3;
	// newmap[3] = 3;
	// newmap[4] = 3;
	// newmap[5] = 3;
	// cout << "size = " << newmap.size() << endl;
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

