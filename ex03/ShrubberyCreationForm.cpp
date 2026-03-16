#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 0,
	145, 137), target("Default")
{
	std::cout << "ShrubberyCreationForm default constructor called!\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation",
	0, 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm with arg constructor called!\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
	target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called!\n" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	if (other.getGrade_to_sign() > 145)
		throw GradeTooLowException();
	if (other.getGrade_to_execute() > 137)
		throw GradeTooLowException();
	AForm::operator=(other);
	std::cout << "ShrubberyCreationForm copy assignment operator called!\n";
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!\n" << std::endl;
}

const char* ShrubberyCreationForm::FileOpenningException::what() const throw()
{
	return "Error occurred while opening file!";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream out_file((target + "_shrubbery").c_str());
	if (!out_file)
		throw ShrubberyCreationForm::FileOpenningException();
	out_file << "          @\n"
				<< "     @ @ @  @ @ @\n"
				<< "   @  @\\/@ @ /__@\n"
				<< "   @@@ @\\ / @/  @ @\n"
				<< "  @\\  \\/@| @ | @\n"
				<< " @__\\@ \\ |/ \\| / @\n"
				<< "    __\\|@|  ||/__/@\n"
				<< "   /  \\ \\  / /__\n"
				<< "  @    \\  \\/ /   @\n"
				<< "        |\" '|\n"
				<< "        |\"  |\n"
				<< "        |\"  |\n"
				<< "       ~|\"  |~\n"
				<< "   ~~~~       ~~~~\n"
				<< " ~~               ~~~\n";
	out_file.close();
}
