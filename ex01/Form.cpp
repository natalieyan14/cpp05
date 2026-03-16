#include "Form.hpp"

Form::Form(const std::string &name, int signGrade,
	int executeGrade) : name(name), isSigned(false), signGrade(signGrade),
	executeGrade(executeGrade)
{
	std::cout << "Form constructor with arg called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned),
	signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string &Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecuteGrade() const
{
	return (this->executeGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	const_cast<std::string &>(this->name) = other.name;
	this->isSigned = other.isSigned;
	const_cast<int &>(this->signGrade) = other.signGrade;
	const_cast<int &>(this->executeGrade) = other.executeGrade;
	std::cout << "Form copy assignment operator called" << std::endl;
	return (*this);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no") << ",sign grade required: " << form.getSignGrade() << ",execute grade required: " << form.getExecuteGrade() << std::endl;
	return (os);
}