#pragma once

#include "WrongAnimal.h"


class WrongCat : public WrongAnimal
{

public:
	WrongCat();
	WrongCat(const WrongCat& other);
	~WrongCat();
	WrongCat& operator= (const WrongCat& other);

	void makeSoul() const;
};
