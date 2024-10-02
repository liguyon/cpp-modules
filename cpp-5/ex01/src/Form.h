#pragma once

#include <string>
#include <exception>


class Bureaucrat;

class Form {

public:
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator= (const Form& other);
	~Form();

	const std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);


private:
	const std::string m_name;
	const int m_gradeToSign;
	const int m_gradeToExecute;
	bool m_isSigned;

};

std::ostream& operator<< (std::ostream& out, const Form& form);
