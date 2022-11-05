#include "iter.hpp"

template <typename T>
void toupper(T &a)
{
	if (a >= 97 && a <= 122)
		a -= 32;
}

template <typename T>
void tolower(T &a)
{
	if (a >= 65 && a <= 90)
		a += 32;
}

template <typename T>
void addOne(T &a)
{
	a += 1;
}

template <typename T>
void printArr(T &a)
{
	std::cout << "[" << a << "]";
}

int main(void)
{
	{
		float arr[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f};
		size_t len = sizeof(arr) / sizeof(float);
		iter(arr, len, printArr);
		std::cout << std::endl;
		iter(arr, len, addOne);
		iter(arr, len, printArr);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::string arr[] = {"abc", "DEF", "HEllO"};
		size_t len = sizeof(arr) / sizeof(std::string);
		iter(arr, len, printArr);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-------------" << std::endl;
		std::cout << "---toupper---" << std::endl;
		std::cout << "-------------" << std::endl;
		char arr[] = {'A', 'b', 'c', 'D', 'e', 'F', 'G'};
		size_t len = sizeof(arr) / sizeof(char);
		iter(arr, len, printArr);
		std::cout << std::endl;
		iter(arr, len, toupper);
		iter(arr, len, printArr);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-------------" << std::endl;
		std::cout << "---tolower---" << std::endl;
		std::cout << "-------------" << std::endl;
		char arr[] = {'A', 'b', 'c', 'D', 'e', 'F', 'G'};
		size_t len = sizeof(arr) / sizeof(char);
		iter(arr, len, printArr);
		std::cout << std::endl;
		iter(arr, len, tolower);
		iter(arr, len, printArr);
		std::cout << std::endl;
	}
	return 0;
}
