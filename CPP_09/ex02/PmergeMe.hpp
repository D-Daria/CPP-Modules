#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>

# define BEF_AF_MSG	1

# define THRESHOLD	5

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class PmergeMe {

	private:
		int					argc;
		char				**argv;
		double				vec_duration;
		double				deq_duration;
		std::vector<int>	vec;
		std::deque<int>		deq;
		std::vector<int>	before_after;

	public:
		PmergeMe();
		PmergeMe(int &argc, char **(&argv));
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		bool validate_input();
		void output(const std::string s, int type);
		void process_vector();
		void sort_vector(int l, int r);
		void merge_vector(int l, int mid, int r);
		void insertion_sort_vector(int l, int r);

		void process_deque();
		void sort_deque(int l, int r);
		void merge_deque(int l, int mid, int r);
		void insertion_sort_deque(int l, int r);

		template <typename T>
		bool is_sorted(T &cont);

		class PmergeMeException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error";
				}
		};
};

#endif