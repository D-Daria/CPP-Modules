#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <cstdio>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class ItemNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return (RED "Item not found" RESET);
		};
};

template <typename T>
typename T::iterator easyfind(T &cont, int toFind)
{
	typename T::iterator it;

	it = std::find(cont.begin(), cont.end(), toFind);
	if (it == cont.end())
		throw(ItemNotFoundException());
	return (it);
}

#endif