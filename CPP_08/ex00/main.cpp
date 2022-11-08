#include "easyfind.hpp"

#include <vector>
#include <list>

int getRand(int min, int max)
{
	return (rand() % (max + 1 - (min))) + min;
}

int main(void)
{
	srand(time(NULL));

	std::cout << "------------" << std::endl;
	std::cout << "---vector---" << std::endl;
	std::cout << "------------" << std::endl;

	std::vector<int> vec;
	std::vector<int>::iterator vec_it;
	for (int i = 0; i < 10; i++)
		vec.push_back(getRand(-10, 10));
	for (vec_it = vec.begin(); vec_it != vec.end(); vec_it++)
		std::cout << *vec_it << " ";
	std::cout << std::endl;
	std::cout << "Searching 5" << std::endl;
	try
	{
		vec_it = easyfind(vec, 5);
		std::cout << GREEN << "Found [" << *vec_it << "]" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "----------" << std::endl;
	std::cout << "---list---" << std::endl;
	std::cout << "----------" << std::endl;
	std::list<int> list;
	std::list<int>::iterator list_it;
	
	for (vec_it = vec.begin(); vec_it != vec.end(); vec_it++)
		list.push_back(*vec_it);
	list.push_front(21);
	list.push_back(-100);
	list.push_back(-200);
	try
	{
		list_it = easyfind(list, 21);
		std::cout << GREEN << "Found [" << *list_it << "]" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Searching -3" << std::endl;
	try
	{
		list_it = easyfind(list, -3);
		std::cout << GREEN << "Found [" << *list_it << "]" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (1);
}
