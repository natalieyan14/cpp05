#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat a("Bob", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	try
	{
		Bureaucrat b("Alo", 151); // սխալ grade
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	try
	{
		Bureaucrat c("Jon", 150);
		std::cout << c << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n========== Form Tests ==========" << std::endl;
	
	// Test 1: Create a form and print it
	std::cout << "\n--- Test 1: Create form and print ---" << std::endl;
	Form form1("TaxForm", 50, 25);
	std::cout << form1;
	
	// Test 2: Bureaucrat signs form with sufficient grade
	std::cout << "\n--- Test 2: Bureaucrat with grade 40 signs form (requires 50) ---" << std::endl;
	Bureaucrat d("Alice", 40);
	std::cout << d;
	d.signForm(form1);
	std::cout << form1;
	
	// Test 3: Bureaucrat with high enough grade signs form
	std::cout << "\n--- Test 3: Bureaucrat with grade 50 signs form (requires 50) ---" << std::endl;
	Bureaucrat e("David", 50);
	std::cout << e;
	Form form2("ContractForm", 50, 30);
	std::cout << form2;
	e.signForm(form2);
	std::cout << form2;
	
	// Test 4: Bureaucrat with perfect grade signs form
	std::cout << "\n--- Test 4: Bureaucrat with grade 1 signs form (requires 50) ---" << std::endl;
	Bureaucrat f("Charlie", 1);
	std::cout << f;
	Form form3("ImportantForm", 50, 20);
	std::cout << form3;
	f.signForm(form3);
	std::cout << form3;
	
	// Test 5: Bureaucrat with insufficient grade cannot sign form
	std::cout << "\n--- Test 5: Bureaucrat with grade 75 tries to sign form (requires 50) ---" << std::endl;
	Bureaucrat g("Eve", 75);
	std::cout << g;
	Form form4("SecretForm", 50, 15);
	std::cout << form4;
	g.signForm(form4);
	std::cout << form4;
	
	return (0);
}

