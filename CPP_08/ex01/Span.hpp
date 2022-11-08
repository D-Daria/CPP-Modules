#ifndef SPAN_HPP
# define SPAN_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <exception>
#include <limits>

class Span {

	private:
		std::vector<int> m_arr;
		unsigned int m_N;
		size_t m_size;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copySpan);
		Span &operator=(const Span &span);
		~Span();

		void addNumber(const int &n);
		void addNumber(std::vector<int>::iterator beg, std::vector<int>::iterator end);

		int shortestSpan(void);
		int longestSpan(void);

		size_t size(void) const;

		std::vector<int> getSpan(void) const;

		class SpanIsFullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif