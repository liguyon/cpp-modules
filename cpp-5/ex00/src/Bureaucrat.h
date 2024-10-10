#pragma once

#include <string>
#include <ostream>
#include <exception>


class Bureaucrat {

public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw ();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw ();
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator= (const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int		getGrade() const;
	void	increment();
	void	decrement();

private:
	const std::string m_name;
	int m_grade;

	static const int s_maxGrade = 1;
	static const int s_minGrade = 150;

};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& bureaucrat);
