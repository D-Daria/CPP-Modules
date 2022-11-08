#include "Span.hpp"

Span::Span() : m_N(0), m_size(0)
{}

Span::Span(unsigned int N) : m_N(N), m_size(m_arr.size())
{}

Span::Span(const Span &copySpan) : m_N(copySpan.m_N), m_size(copySpan.size())
{
	m_arr = copySpan.m_arr;
}

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return (*this);
	m_arr = span.m_arr;
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(const int &n)
{
	if (m_size + 1 > m_N)
		throw(SpanIsFullException());
	m_arr.push_back(n);
	m_size += 1;
}

void Span::addNumber(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	std::vector<int>::iterator it;

	for (it = beg; it != end; it++)
	{
		if (m_size + 1 > m_N)
			throw(SpanIsFullException());
		m_arr.push_back(*it);
		m_size += 1;
	}
}

int Span::shortestSpan(void)
{
	if (m_size <= 1)
		throw(NoSpanException());
	std::vector<int>::iterator l;
	std::vector<int>::iterator r;

	int shortest = std::numeric_limits<int>::max();
	std::vector<int> vec = m_arr;
	std::sort(vec.begin(), vec.end());
	for (l = vec.begin(); l != vec.end() - 1; l++)
	{
		r = l + 1;
		if (*r - *l < shortest)
			shortest = std::abs(*r - *l);
	}
	return (shortest);
}

int Span::longestSpan(void)
{
	if (m_size <= 1)
		throw(NoSpanException());
	std::vector<int>::iterator min = std::min_element(m_arr.begin(), m_arr.end());
	std::vector<int>::iterator max = std::max_element(m_arr.begin(), m_arr.end());
	return (*max - *min);
}

size_t Span::size(void) const
{
	return (m_size);
}

std::vector<int> Span::getSpan(void) const
{
	return (m_arr);
}

const char* Span::SpanIsFullException::what() const throw()
{
	return (RED "Span is full" RESET);
}

const char* Span::NoSpanException::what() const throw()
{
	return (RED "Span can't be found" RESET);
}
