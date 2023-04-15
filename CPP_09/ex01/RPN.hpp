#ifndef RPN_HPP
# define RPN_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <stack>

# define ADD		0
# define SUBTRACT	1	
# define DIVIDE		2
# define MULTIPLY	3

class RPN {

	private:
		std::stack<int> vals;
		int add(int &top, int &botm);
		int subtract(int &top, int &botm);
		int divide(int &top, int &botm);
		int multiply(int &top, int &botm);

	public:
		RPN();
		RPN(std::string &args);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();

		typedef int (RPN::*makeOperation)(int &top, int &botm);

		void changeStack(int *top, int *botm);
		void startRPN(std::string &args);

		class RPNException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error";
				}
		};
};

#endif