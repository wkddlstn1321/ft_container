#ifndef _TREE_HPP
# define _TREE_HPP

namespace ft
{
	template <typename T>
	struct _treeNode
	{
		public:
			typedef T value_type;
			value_type	data;
			_treeNode	*parent;
			_treeNode	*left;
			_treeNode	*right;
	};

	// template <>
	// class _tree
	// {

	// };
}

#endif
