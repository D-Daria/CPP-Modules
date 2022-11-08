#include "Span.hpp"

int getRand(int min, int max)
{
	return (rand() % (max + 1 - (min))) + min;
}

void printArr(const std::vector<int> &vec)
{
	std::vector<int>::const_iterator it;
	std::cout << "[ ";
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << "]" <<std::endl;
}

void subjectTest(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main(void)
{
	srand(time(NULL));
	std::cout << "-------------" << std::endl;
	std::cout << "---Subject---" << std::endl;
	std::cout << "-------------" << std::endl;
	subjectTest();
	std::cout << std::endl;

	{
		Span sp = Span(5);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(3);
			sp.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(0);
		try
		{
			sp.addNumber(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(6);
		sp.addNumber(-1);
		sp.addNumber(-10);
		sp.addNumber(0);
		sp.addNumber(23);
		sp.addNumber(-5);
		sp.addNumber(-11);

		printArr(sp.getSpan());
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(1);
		sp.addNumber(10);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(6);
		std::vector<int> vec;
		int arr[] = {-19, -10, -17, -2, -15, -1};
		for (int i = 0; i < 6; i++)
			vec.push_back(arr[i]);
		std::vector<int>::iterator beg = vec.begin();
		std::vector<int>::iterator end = vec.end();
		try
		{
			sp.addNumber(beg, end);
			printArr(sp.getSpan());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(40);
		std::vector<int> vec;
		for (int i = 0; i < 100; i++)
			vec.push_back(rand());
		std::vector<int>::iterator beg = vec.begin() + 10;
		std::vector<int>::iterator end = vec.begin() + 50;
		try
		{
			sp.addNumber(beg, end);
			// printArr(sp.getSpan());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(2);
		try
		{
			sp.addNumber(1);
			sp.addNumber(-1);
			printArr(sp.getSpan());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(20000);
		std::vector<int> vec;
		for (int i = 0; i < 20000; i++)
			vec.push_back(getRand(-2000000, RAND_MAX));
		std::vector<int>::iterator beg = vec.begin();
		std::vector<int>::iterator end = vec.end();
		try
		{
			sp.addNumber(beg, end);
			// std::cout << "span size: " << sp.size() << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (1);
}
