#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstdio>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

template <typename T>
class Array {

	private:
		T *m_array;
		unsigned int m_size;
	
	public:
		Array() : m_array(NULL), m_size(0)
		{
			std::cout << BLUE << "Creating empty array" << RESET << std::endl;
		}
		Array(unsigned int n) : m_size(n)
		{
			std::cout << BLUE << "Creating array with size " << m_size << RESET << std::endl;
			m_array = new T[m_size];
		}
		Array(const Array &copyArray) : m_size(copyArray.size())
		{
			std::cout << BLUE << "Copy constructor" << RESET << std::endl;
			m_array = new T[m_size];
			for (unsigned int i = 0; i < m_size; i++) {
				m_array[i] = copyArray.m_array[i];
			}
		}
		Array &operator=(const Array &array)
		{
			std::cout << BLUE << "Assignment operator" << RESET << std::endl;
			if (this == &array)
				return (*this);
			delete[] m_array;
			m_size = array.size();
			m_array = new T[m_size];
			for (unsigned int i = 0; i < m_size; i++) {
				m_array[i] = array.m_array[i];
			}
			return (*this);
		}
		~Array()
		{
			delete[] m_array;
		}

		T &operator[](int index)
		{
			if (index < 0 || index >= static_cast<int>(m_size))
				throw(OutOfBoundsException());
			return m_array[index];
		}

		unsigned int size(void) const
		{
			return (m_size);
		}

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return (RED"Index is out of bounds"RESET);
				}
		};
};

#endif