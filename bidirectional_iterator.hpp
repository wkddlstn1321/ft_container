#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

#include<iterator>
#include"iterator_traits.hpp"

namespace ft
{
	class bidirectional_iterator
	{
	private:
		/* data */

	public:
		bidirectional_iterator();
		bidirectional_iterator(const bidirectional_iterator &ref);
		~bidirectional_iterator();

		bidirectional_iterator &operator=(const bidirectional_iterator &ref);
	};
}

#endif
