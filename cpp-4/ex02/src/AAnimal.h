#pragma once

#include <string>


class AAnimal // becomes abstract base class due to pure virtual func
{

public:
	AAnimal();
	AAnimal(const AAnimal& other);
	virtual ~AAnimal();
	AAnimal& operator= (const AAnimal& other);

	virtual void makeSound() const = 0; // pure virtual function

protected:
	std::string type;

};
