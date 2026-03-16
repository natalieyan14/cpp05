#include "PresidentialPardonForm.hpp"

PresidentialPardonForm ::PresidentialPardonForm() : AForm("PresidentialPardon", 0, 25, 5), target("Default")
{
	std::cout << "PresidentialPardonForm default constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardon",
	0, 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor with arg called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other),
	target(other.target)
{
	if (other.getGrade_to_sign() > 25)
		throw GradeTooLowException();
	if (other.getGrade_to_execute() > 5)
		throw GradeTooLowException();
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this == &other)
    return *this;
	if (other.getGrade_to_sign() > 25)
    throw GradeTooLowException();
	if (other.getGrade_to_execute() > 5)
    throw GradeTooLowException();
	AForm::operator=(other);
	std::cout<<"PresidentialPardonForm copy assignment operator called!\n";
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called!\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox!\n";
}
