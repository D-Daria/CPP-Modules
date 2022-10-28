#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void subjectTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	// subjectTest();

	MateriaSource* src = new MateriaSource();

	src->getMateriaSources();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());


	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->getMateriaSources();

	std::cout << std::endl;

	// ICharacter *me = new Character("me");
	Character *me = new Character("me");
	me->displaySlots();

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->displaySlots();

	tmp = src->createMateria("ice");
	me->equip(tmp);

	me->unequip(2);
	me->displaySlots();

	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->displaySlots();

	ICharacter* bob = new Character("bob");

	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("unknown");
	bob->equip(tmp);

	bob->unequip(3);

	bob->use(1, *me);
	me->use(0, *bob);
	me->use(1, *bob);
	bob->use(2, *me);
	me->use(3, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
