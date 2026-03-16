#pragma once

#include "Bureaucrat.hpp"

class Form
{
  private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;

  public:
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	Form(const std::string &name, int signGrade, int executeGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	void beSigned(const Bureaucrat &bureaucrat);

	const std::string &getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);
