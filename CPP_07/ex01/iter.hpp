#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cstdio>

template <typename T>
void iter(T *arr, size_t len, void (*func)(T &))
{
	if (len <= 0 || arr == nullptr || func == nullptr)
		return ;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif