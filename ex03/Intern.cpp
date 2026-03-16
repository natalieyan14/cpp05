#include "Intern.hpp"
#include <algorithm>
#include <cctype>

Intern::Intern()
{
	std::cout << "Intern default ctor called!\n";
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern copy ctor called!\n";
}

Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return (*this);
	std::cout << "Intern copy assignment operator called!\n";
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern default dtor called!\n";
}

AForm *Intern::makeForm(std::string name, std::string target)
{

	typedef AForm *(Intern::*Maker)(std::string);
	Maker	makers[3];
	int		i;

	makers[0] = &Intern::makePresidentialPardon;
	makers[1] = &Intern::makeRobotomyRequest;
	makers[2] = &Intern::makeShrubberyCreation;
	std::string names[3] = {"presidential pardon", "robotomy request",
		"shrubbery creation"};
	std::string lower = name;
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	i = 0;
	while (i < 3 && lower != names[i])
		i++;
	if (i < 3)
	{
		std::cout << "Intern creates " << names[i] << std::endl;
		return (this->*makers[i])(target);
	}
	throw Intern::NoSuchFormException();
}

AForm *Intern::makePresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

const char *Intern::NoSuchFormException::what() const throw()
{
	return ("No such form type!\n");
}
