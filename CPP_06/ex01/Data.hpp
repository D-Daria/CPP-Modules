#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
	std::string door;
	int floor;
	char sym;
	bool isOpened;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif