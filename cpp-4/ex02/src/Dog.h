#pragma once

#include "AAnimal.h"
#include "Brain.h"


class Dog : public AAnimal
{

public:
	Dog();
	Dog(const Dog& other);
	~Dog();
	Dog& operator= (const Dog& other);

	void makeSound() const;
	Brain*	getBrain() const;

private:
	Brain* m_brain;

};
