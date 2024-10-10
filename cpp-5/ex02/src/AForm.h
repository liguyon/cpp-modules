#pragma once

#include <string>
#include <exception>


class Bureaucrat;

class AForm {

public:
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw ();
	};

	class AlreadySignedException : public std::exception {
	public:
		virtual const char* what() const throw ();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw ();
	};

	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator= (const AForm& other);
	virtual ~AForm();

	const std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& executor) const;

protected:
	virtual void beExecuted() const = 0;

private:
	const std::string m_name;
	const int m_gradeToSign;
	const int m_gradeToExecute;
	bool m_isSigned;

};

std::ostream& operator<< (std::ostream& out, const AForm& AForm);
