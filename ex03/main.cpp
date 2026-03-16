#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Intern someRandomIntern;

	AForm *rrf = NULL;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
			delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	return (0);
}