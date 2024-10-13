#include <stdint.h>
#include <iostream>

#include "Serializer.h"
#include "Data.h"


int main()
{
	{ // TEST: non instantiable
        std::cout << "==== TESTS: non instantiable (remove comment) ====\n";
		// Serializer a;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: serializer
        std::cout << "==== TESTS: serializer ====\n";

		Data* myAccountCredentials  = new Data;
		myAccountCredentials->login = "mayalabeille";
		myAccountCredentials->password = "testPass123!";

		uintptr_t serialized = Serializer::serialize(myAccountCredentials);
		std::cout << serialized << std::endl;
		std::cout << Serializer::deserialize(serialized)->login << std::endl;
		std::cout << Serializer::deserialize(serialized)->password << std::endl;
	}

	return 0;
}
