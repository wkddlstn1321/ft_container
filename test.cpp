#include"vector.hpp"

class test
{
private:
	int	n;
public:
	explicit test(int a);
	void	prin(test test)
	{
		std::cout << test.n << std::endl;
	};
};

test::test(int a)
{
	this->n = a;
}

int	main(void)
{
	test c(10);
	c.prin(c);
}
