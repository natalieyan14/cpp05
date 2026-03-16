*This project has been created as part of the 42 curriculum by nharutyu*
# C++ Module 05: Repetition and Exceptions

A comprehensive C++ project demonstrating object-oriented programming concepts including exception handling, inheritance, polymorphism, and the Orthodox Canonical Form.

## Overview

This module introduces fundamental OOP concepts through a bureaucratic form management system. The project progresses from basic exception handling with a `Bureaucrat` class to complex form workflows with abstract base classes and concrete implementations.

## Project Structure

```
cpp05/
├── ex00/  - Bureaucrat class with exception handling
├── ex01/  - Form class with signing mechanism
├── ex02/  - Abstract forms with concrete implementations
├── ex03/  - Intern class with form factory pattern
└── README.md
```

## Exercises

### Exercise 00: Bureaucrat
**Directory:** `ex00/`

Create a `Bureaucrat` class representing a government official.

**Features:**
- Constant name attribute
- Grade system (1 = highest, 150 = lowest)
- Exception handling for invalid grades:
  - `GradeTooHighException` (grade < 1)
  - `GradeTooLowException` (grade > 150)
- Member functions to increment/decrement grade
- Getters for name and grade
- Operator overload for output

**Key Concept:** Exception handling and basic C++ OOP

```cpp
try {
    Bureaucrat bob("Bob", 2);
    bob.incrementGrade();  
}
catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
}
```

---

### Exercise 01: Form
**Directory:** `ex01/`

Extend the previous exercise by adding a `Form` class that bureaucrats can sign.

**Features:**
- Constant name attribute
- Boolean signing status (initially false)
- Constant grades required to sign and execute
- Private attributes (not protected)
- Exception handling for invalid grades
- `beSigned()` method to sign the form
- `signForm()` method in Bureaucrat class

**Key Concept:** Object relationships and delegation

---

### Exercise 02: Concrete Forms
**Directory:** `ex02/`

Create an abstract base class `AForm` with three concrete implementations.

**Concrete Forms:**

1. **ShrubberyCreationForm**
   - Required grades: sign 145, execute 137
   - Action: Creates `<target>_shrubbery` file with ASCII art trees

2. **RobotomyRequestForm**
   - Required grades: sign 72, execute 45
   - Action: Performs "robotomy" on target (50% success rate)

3. **PresidentialPardonForm**
   - Required grades: sign 25, execute 5
   - Action: Pardons target by Zaphod Beeblebrox

**Features:**
- Pure virtual `execute()` method in `AForm`
- Grade validation in base class
- Form-specific actions in derived classes
- `executeForm()` method in Bureaucrat class
- Proper exception handling for unsigned/invalid forms

**Key Concept:** Polymorphism, inheritance, and virtual functions

---

### Exercise 03: Intern
**Directory:** `ex03/`

Create an `Intern` class with a form factory mechanism.

**Features:**
- `makeForm()` function takes form name and target
- Returns pointer to `AForm` with initialized target
- Case-insensitive form name matching
- Member function pointer array for form creation
- `NoSuchFormException` for invalid form names
- Clean dispatching (no if/else chains)

**Key Concept:** Function pointers, factory pattern, and design patterns

```cpp
Intern intern;
AForm *form = intern.makeForm("robotomy request", "Bender");
delete form;
```

---

## Building and Running

### Prerequisites
- C++ compiler supporting C++98
- GNU Make

### Compile Individual Exercises

```bash
cd ex00 && make
./Mommy_when_I_grow_up_I_want_to_be_a_bureaucrat

cd ../ex01 && make
./Form_up_maggots

cd ../ex02 && make
./No_you_need_form_28B_not_28C

cd ../ex03 && make
./At_least_this_beats_coffee_making
```

### Compilation Flags
All exercises compile with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

### Clean Up
```bash
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Rebuild from scratch
```

---

## Key Concepts

### Exception Handling
- Custom exception classes inheriting from `std::exception`
- Try-catch blocks for graceful error handling
- Exceptions thrown during construction and member function calls

### Orthodox Canonical Form
All classes implement:
1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

### Polymorphism
- Virtual functions in abstract base class
- Derived classes override abstract methods
- Runtime polymorphic behavior

### Grade System
- Grade 1 is **highest** (best rank)
- Grade 150 is **lowest** (worst rank)
- Incrementing grade 3 → grade 2
- Decrementing grade 2 → grade 3

### Design Patterns
- **Factory Pattern** (Intern class)
- **Member Function Pointers** (form creation dispatch)
- **Abstract Factory** (AForm base class)

---

## Important Rules

### Allowed
✅ C++ Standard Library (except containers in ex00-ex02)
✅ Exception handling
✅ Operator overloading
✅ Virtual functions
✅ File I/O operations

### Forbidden
❌ C-style functions: `malloc()`, `calloc()`, `free()`, `printf()`
❌ `using namespace` statement
❌ `friend` keyword
❌ C++11 and later features
❌ External libraries
❌ Function implementations in headers (except templates)

---

## Memory Management

- All dynamically allocated memory in ex03 is properly deallocated
- No memory leaks detected
- Proper use of `new` and `delete` for form objects

---

## Testing

Each exercise includes a `main.cpp` with comprehensive tests demonstrating:
- Valid grade operations
- Exception throwing and catching
- Form creation and signing
- Form execution with various bureaucrat grades
- Edge cases and error conditions

---

## Implementation Highlights

### Exception Hierarchy
```
std::exception
├── Bureaucrat::GradeTooHighException
├── Bureaucrat::GradeTooLowException
├── Form/AForm::GradeTooHighException
└── Form/AForm::GradeTooLowException
```

### Form Dispatching (Ex03)
```cpp
typedef AForm *(Intern::*Maker)(std::string);
Maker makers[3] = {
    &Intern::makePresidentialPardon,
    &Intern::makeRobotomyRequest,
    &Intern::makeShrubberyCreation
};
```

---

## Compilation Output

```
✓ ex00: Mommy_when_I_grow_up_I_want_to_be_a_bureaucrat
✓ ex01: Form_up_maggots
✓ ex02: No_you_need_form_28B_not_28C
✓ ex03: At_least_this_beats_coffee_making

All exercises compile cleanly with -Wall -Wextra -Werror -std=c++98
```

---

## Project Status

✅ **Complete and fully functional**

All exercises implemented according to specification with:
- Proper exception handling
- Correct grade validation
- Clean object-oriented design
- Zero memory leaks
- C++98 standard compliance

---

## Author Notes

This project demonstrates mastery of:
- Exception handling in modern C++
- Object-oriented design principles
- Inheritance and polymorphism
- Design patterns (Factory, Member Function Pointers)
- Resource management

The bureaucratic theme serves as an effective metaphor for understanding class hierarchies, validation rules, and exception propagation in larger applications.

---

## References

- C++ Standard Library Documentation
- Exception Handling Best Practices
- Design Patterns in C++
- 42 School C++ Module Guidelines
