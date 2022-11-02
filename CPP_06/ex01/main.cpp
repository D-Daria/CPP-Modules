#include "Data.hpp"

void print_struct(Data *d)
{
	std::cout << d << std::endl;
	std::cout << (uintptr_t)&d << std::endl;
	std::cout << "door:\t" << d->door << '\n'
			  << "floor:\t" << d->floor << '\n'
			  << "symbol:\t" << d->sym << '\n'
			  << "opened:\t" << d->isOpened
	<< std::endl;
}

int main(void)
{
	Data *d = new Data;
	Data *desD;

	d->door = "Red";
	d->floor = 9;
	d->sym = '*';
	d->isOpened = true;

	print_struct(d);
	std::cout << "sizeof(d): " << sizeof(d) << std::endl;
	std::cout << std::endl;

	uintptr_t raw = serialize(d);
	std::cout << "Serialized: " << raw << " -> " << reinterpret_cast<char *>(raw) << std::endl;
	std::cout << "sizeof(raw): " << sizeof(raw) << std::endl;
	std::cout << std::endl;

	desD = deserialize(raw);
	desD->door = "Yellow";
	print_struct(desD);
	std::cout << "sizeof(desD): " << sizeof(desD) << std::endl;
	std::cout << std::endl;

	d = deserialize(raw);
	d->floor = 3;
	d->isOpened = false;
	print_struct(d);
	std::cout << "sizeof(d): " << sizeof(d) << std::endl;

	delete d;
}
