#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string &args)
{
	if (args.size() == 0)
		throw RPNException();
	startRPN(args);
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

RPN::~RPN() {}

int RPN::add(int &top, int &botm)
{
	return top + botm;
}

int RPN::subtract(int &top, int &botm)
{
	return botm - top;
}

int RPN::divide(int &top, int &botm)
{
	if (top == 0)
		throw RPNException();
	return botm / top;
}

int RPN::multiply(int &top, int &botm)
{
	return top * botm;
}

void RPN::changeStack(int *top, int *botm)
{
	if (vals.size() < 2)
		throw RPNException();
	*top = vals.top();
	vals.pop();
	*botm = vals.top();
	vals.pop();
}

void RPN::startRPN(std::string &args)
{
	makeOperation makeOperation[] = { &RPN::add, &RPN::subtract, &RPN::divide, &RPN::multiply };

	int top = 0;
	int botm = 0;
	bool isOper = false;
	bool isNeg = false;
	for (size_t i = 0; i < args.size(); i++)
	{
		char c = args[i];
		if (isblank(c))
			continue;
		switch (c)
		{
			case '+':
				changeStack(&top, &botm);
				vals.push((this->*makeOperation[ADD])(top, botm));
				isOper = true;
				break;
			case '-':
				if (i < args.size() - 1 && isdigit(args[i + 1]))
				{
					isNeg = true;
					break;
				}
				changeStack(&top, &botm);
				vals.push((this->*makeOperation[SUBTRACT])(top, botm));
				isOper = true;
				break;
			case '/':
				changeStack(&top, &botm);
				vals.push((this->*makeOperation[DIVIDE])(top, botm));
				isOper = true;
				break;
			case '*':
				changeStack(&top, &botm);
				vals.push((this->*makeOperation[MULTIPLY])(top, botm));
				isOper = true;
				break;
			default:
				if (isdigit(c)) {
					isOper = false;
					int n = c - '0';
					if (isNeg)
					{
						n *= (-1);
						isNeg = false;
					}
					vals.push(n);	
				} else {
					throw RPNException();
				}
		}
	}
	if (isOper == false)
		throw RPNException();
	std::cout << vals.top() << std::endl;
}
