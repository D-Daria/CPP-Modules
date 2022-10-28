#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void subjectTest(void)
{
	std::cout << "------------------" << std::endl;
	std::cout << "   Subject Test   " << std::endl;
	std::cout << "------------------" << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;//should not create a leak
	delete i;

}

void animalsTest(void)
{
	std::cout << "-----------------" << std::endl;
	std::cout << "     Animals     " << std::endl;
	std::cout << "-----------------" << std::endl;

	size_t N = 20;
	AAnimal *aanimals[N];
	for (size_t i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			aanimals[i] = new Dog();
		else
			aanimals[i] = new Cat();
	}
	std::cout << std::endl;
	for (size_t i = 0; i < N; i++)
	{
		std::cout << "I am " << aanimals[i]->getType() << " who says ";
		aanimals[i]->makeSound();
	}
	std::cout << std::endl;
	for (size_t i = 0; i < N; i++)
		delete aanimals[i];
}

void checkListTest(void)
{
	std::cout << "-----------------" << std::endl;
	std::cout << "    Checklist    " << std::endl;
	std::cout << "-----------------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}
}

int main(void)
{
	subjectTest();

	animalsTest();

	checkListTest();

	// AAnimal test;

	std::cout << "-----------------" << std::endl;
	std::cout << "    Deep copy    " << std::endl;
	std::cout << "-----------------" << std::endl;

	std::string ideas[] = {
		"Idea #1 of Dog",
		"Idea #1 of Cat",
		"Idea #2 of Dog",
		"Idea #2 of Cat",
		"Idea #3 of Dog",
		"Idea #3 of Cat",
		"I want to Bark!",
		"I want to Mew!",
	};

	Dog *dog[4];
	Cat *cat[4];

	for (int i = 0; i < 4; i++)
	{
		dog[i] = new Dog();
		for (int c = 0; c < 8; c++)
		{
			if (c % 2 == 0)
				dog[i]->setIdea(ideas[c], c);
		}
		cat[i] = new Cat();
		for (int c = 0; c < 8; c++)
		{
			if (c % 2 != 0)
				cat[i]->setIdea(ideas[c], c);
		}
	}
	std::cout << std::endl;

	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << "I am " << dog[i]->getType() << " and my ideas are\n";
	// 	dog[i]->getIdeas();
	// 	dog[i]->getIdeasAddress();
	// }
	// std::cout << std::endl;
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << "I am " << cat[i]->getType() << " and my ideas are\n";
	// 	cat[i]->getIdeas();
	// 	dog[i]->getIdeasAddress();
	// }

	std::cout << "I am dog[0] " << "and my ideas addresses are\n";
	dog[0]->getIdeas();
	dog[0]->getIdeasAddress();

	Dog *copyDog = new Dog(*dog[0]);
	std::cout << "I am copyDog " << copyDog->getType() << " and my ideas are\n";
	copyDog->getIdeas();
	copyDog->getIdeasAddress();

	std::cout << std::endl;

	copyDog->setIdea("I am new Idea of Dog", 2);
	dog[0]->getIdeas();
	copyDog->getIdeas();

	std::cout << std::endl;

	std::cout << "I am cat[3] " << "and my ideas addresses are\n";
	cat[3]->getIdeas();
	cat[3]->getIdeasAddress();
	Cat refCat;
	refCat = *cat[2];
	std::cout << "I am refCat " << refCat.getType() << " and my ideas are\n";
	refCat.getIdeas();
	refCat.getIdeasAddress();

	std::cout << std::endl;

	refCat.setIdea("I am new idea of Cat", 1);
	cat[3]->getIdeas();
	refCat.getIdeas();

	delete copyDog;
	for (int i = 0; i < 4; i++)
	{
		delete dog[i];
		delete cat[i];
	}
	return (1);
}
