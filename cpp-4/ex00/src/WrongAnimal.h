#pragma once

#include <string>


class WrongAnimal
{

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();
	WrongAnimal& operator= (const WrongAnimal& other);

	void makeSound() const;

protected:
	std::string type;

};
