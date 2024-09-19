#pragma once

#include <string>


class Brain
{

public:
	Brain();
	Brain(const Brain& other);
	~Brain();
	Brain& operator= (const Brain& other);

	void setIdea(int i, const std::string& idea);
	const std::string& getIdea(int i) const;

private:
	std::string m_ideas[100];

};
