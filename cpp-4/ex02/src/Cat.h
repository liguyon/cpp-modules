#pragma once

#include "AAnimal.h"
#include "Brain.h"


class Cat : public AAnimal
{

public:
	Cat();
	Cat(const Cat& other);
	~Cat();
	Cat& operator= (const Cat& other);

	void	makeSound() const;
	Brain*	getBrain() const;

private:
	Brain* m_brain;

};
