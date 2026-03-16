#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

int	main(void)
{
	RobotomyRequestForm	roboAssign;

	std::srand(static_cast<unsigned int>(time(0)));
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat john("John", 140);
		Bureaucrat jim("Jim", 150);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Bender");
		PresidentialPardonForm pres("Marvin");
		std::cout << "--- Initial state ---" << std::endl;
		std::cout << bob << john << jim;
		std::cout << "\n--- Signing attempts ---" << std::endl;
		john.signForm(shrub); // should succeed (140 <= 145)
		jim.signForm(shrub);  // should fail (150 > 145)
		bob.signForm(robo);
		bob.signForm(pres);
		std::cout << "\n--- Execution attempts ---" << std::endl;
		// Shrubbery: requires exec grade 137; John (140) should fail to execute
		john.executeForm(shrub);
		// Bob can execute everything
		bob.executeForm(shrub);
		bob.executeForm(robo);
		bob.executeForm(pres);
		std::cout << "\n--- Additional tests ---" << std::endl;
		// 1) Construction exceptions for Bureaucrat
		try
		{
			Bureaucrat badHigh("TooHigh", 0);
		}
		catch (std::exception &e)
		{
			std::cout << "Ctor exception (high): " << e.what() << std::endl;
		}
		try
		{
			Bureaucrat badLow("TooLow", 151);
		}
		catch (std::exception &e)
		{
			std::cout << "Ctor exception (low): " << e.what() << std::endl;
		}
		// 2) Attempt to sign with too-low grade
		Bureaucrat low("Low", 150);
		RobotomyRequestForm robo2("Robbie");
		low.signForm(robo2); // should fail
		// 3) Attempt to execute an unsigned form
		ShrubberyCreationForm shrub2("garden");
		bob.executeForm(shrub2); // should print couldn't execute (not signed)
		// 4) Copy constructor and assignment for forms
		RobotomyRequestForm roboCopy(robo);
		roboAssign = roboCopy;
		bob.signForm(roboCopy);
		bob.executeForm(roboCopy);
		bob.executeForm(roboAssign); // roboAssign not signed -> should fail
		// 5) Verify shrubbery file creation for "home"
		{
			std::ifstream f("home_shrubbery");
			if (f)
				std::cout << "home_shrubbery exists (OK)" << std::endl;
			else
				std::cout << "home_shrubbery missing (FAIL)" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}
	return (0);
}
