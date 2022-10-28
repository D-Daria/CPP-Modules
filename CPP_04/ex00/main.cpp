#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	subjectTest(void)
{
	{
		std::cout << "------------------" << std::endl;
		std::cout << "   Subject Test   " << std::endl;
		std::cout << "------------------" << std::endl;

		const Animal *meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "----------------" << std::endl;
		std::cout << "   Wrong test   " << std::endl;
		std::cout << "----------------" << std::endl;

		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* c = new WrongCat();
		std::cout << c->getType() << " " << std::endl;
		c->makeSound();
		meta->makeSound();

		delete meta;
		delete c;
	}
}

int main(void)
{
	subjectTest();

	std::cout << "----------------" << std::endl;
	std::cout << "     My test    " << std::endl;
	std::cout << "----------------" << std::endl;
	Animal animal = Animal();
	WrongAnimal wrongAnimal = WrongAnimal();

	Dog d = Dog();
	Cat c = Cat();
	WrongCat notCat = WrongCat();

	Animal *aCat = &c;
	Animal *aDog = &d;
	WrongAnimal *wrongAnimalCat = &notCat;
	std::cout << std::endl;

	std::cout << "Animal "
			  << animal.getType() << " sound is ";
	animal.makeSound();
	std::cout << "WrongAnimal "
			  << wrongAnimal.getType() << " sound is ";
	wrongAnimal.makeSound();
	std::cout << std::endl;

	std::cout << c.getType() << " sounds like ";
	c.makeSound();
	std::cout << "aCat "
			  << aCat->getType() << " sound is ";
	aCat->makeSound();
	std::cout << std::endl;

	std::cout << d.getType() << " sounds like ";
	d.makeSound();
	std::cout << "aDog "
			  << aDog->getType() << " sound is ";
	aDog->makeSound();
	std::cout << std::endl;

	std::cout << notCat.getType() << " sounds like ";
	notCat.makeSound();
	std::cout << "wrongAnimalCat "
			  << wrongAnimalCat->getType() << " sound is ";
	wrongAnimalCat->makeSound();
	std::cout << std::endl;

	return (1);
}
