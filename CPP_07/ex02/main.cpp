#include <iostream>
#include "Array.hpp"
#include <string>

#define MAX_VAL 750

template <typename T>
void printArr(Array<T> &arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++) {
		std::cout << YELLOW << "[" << arr[i];
		if (i < size - 1)
			std::cout << "] ";
		else
			std::cout << "]" << RESET << std::endl;
	}
}

void subjectTest()
{
	std::cout << "-------------" << std::endl;
	std::cout << "---Subject---" << std::endl;
	std::cout << "-------------" << std::endl;

	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		// printArr(test, tmp.size());
	}

	for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

int main(int, char**)
{	
	subjectTest();
	std::cout << std::endl;
	{
		std::cout << "-----------" << std::endl;
		std::cout << "---Empty---" << std::endl;
		std::cout << "-----------" << std::endl;
		Array<int> arr;
		try
		{
			std::cout  << "arr[0] " << arr[0] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "arr[1] " << arr[1] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		Array<int> another;
		another = arr;
		try
		{
			std::cout  << "another[0] " << another[0] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "another[1] " << another[1] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "----------" << std::endl;
		std::cout << "---Char---" << std::endl;
		std::cout << "----------" << std::endl;
		Array<char> charArr(10);

		std::cout << "charArr.size(): " << charArr.size() << std::endl;
		for (unsigned int i = 0; i < charArr.size(); i++) {
			charArr[i] = 'a' + rand() % 26;
		}
		printArr(charArr, charArr.size());
		Array<char> newCharArr(20);
		newCharArr = charArr;
		std::cout << "newCharArr.size(): " << newCharArr.size() << std::endl;
		printArr(newCharArr, newCharArr.size());
		try
		{
			std::cout  << "newCharArr[11] " << newCharArr[11] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		for (unsigned int i = 0; i < newCharArr.size(); i++) {
			newCharArr[i] = 'a' + rand() % 26;
		}
		std::cout << "charArr" << std::endl;
		printArr(charArr, charArr.size());
		std::cout << "newCharArr" << std::endl;
		printArr(newCharArr, newCharArr.size());
		try
		{
			charArr[0] = '!';
			charArr[8] = 'A';
			newCharArr[0] = '?';
			newCharArr[8] = 'F';
			newCharArr[10] = '*';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "charArr[0] " << charArr[0] << std::endl;
			std::cout << "charArr[8] " << charArr[8] << std::endl;
			std::cout << "newCharArr[0] " << newCharArr[0] << std::endl;
			std::cout << "newCharArr[8] " << newCharArr[8] << std::endl;
			std::cout << "newCharArr[11] " << newCharArr[11] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "charArr" << std::endl;
		printArr(charArr, charArr.size());
		std::cout << "newCharArr" << std::endl;
		printArr(newCharArr, newCharArr.size());
	}
	std::cout << std::endl;
	{
		std::cout << "------------" << std::endl;
		std::cout << "---String---" << std::endl;
		std::cout << "------------" << std::endl;
		Array<std::string> str(6);
		std::string s[] = {"To", "be", "or", "not", "to", "what"};
		printArr(str, str.size());
		try
		{
			str[0] = s[0];
			str[1] = s[1];
			str[2] = s[2];
			str[3] = s[3];
			str[4] = s[4];
			str[5] = s[5];
			str[6] = s[5];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		Array<std::string> strCopy(str);
		printArr(strCopy, strCopy.size());
		strCopy[5] = "  ";
		strCopy[5].at(0) = 'b';
		strCopy[5].at(1) = 'e';
		printArr(strCopy, strCopy.size());
	}
	std::cout << std::endl;
	{
		std::cout << "------------" << std::endl;
		std::cout << "---Double---" << std::endl;
		std::cout << "------------" << std::endl;

		Array<double> db(2);
		Array<double> d(db);

		d[0] = 42.4242424242;
		d[1] = 21.2121212121;

		printArr(d, d.size());
	}
	std::cout << std::endl;
	{
		Array<int> arr(0);
		try
		{
			std::cout << arr[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
