#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int &argc, char **(&argv))
{
	this->argc = argc;
	this->argv = argv;
	if (!validate_input())
		throw PmergeMeException();
	process_vector();
	if (!is_sorted(vec))
		throw PmergeMeException();
	process_deque();
	if (!is_sorted(deq))
		throw PmergeMeException();
	output("Before:\t", BEF_AF_MSG);
	before_after = vec;
	output("After:\t", BEF_AF_MSG);
	output("std::vector", 'v');
	output("std::deque ", 'd');
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this == &copy)
		return *this;
	this->argc = copy.argc;
	this->argv = copy.argv;
	this->before_after = copy.before_after;
	this->vec = copy.vec;
	this->deq = copy.deq;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::process_vector()
{
	time_t start = clock();
	for (int i = 1; i < argc; i++) {
		vec.push_back(atoi(argv[i]));
	}
	sort_vector(0, vec.size() - 1);
	time_t end = clock();
	vec_duration = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);
}

void PmergeMe::sort_vector(int l, int r)
{
	int mid;
	if (r - l > THRESHOLD) {
		mid = (l + r) / 2;
		sort_vector(l, mid);
		sort_vector(mid + 1, r);
		merge_vector(l, mid, r);
	}
	else
		insertion_sort_vector(l, r);
}

void PmergeMe::merge_vector(int l, int mid, int r)
{
	int l_size = mid - l + 1;
	int r_size = r - mid;

	std::vector<int> l_vec;
	std::vector<int> r_vec;

	for (int i = 0; i < l_size; i++) {
		l_vec.push_back(vec[l + i]);
	}
	for (int i = 0; i < r_size; i++) {
		r_vec.push_back(vec[mid + i + 1]);
	}

	int l_ind = 0;
	int r_ind = 0;
	int k = l;
	while (l_ind < l_size && r_ind < r_size)
	{
		if (l_vec[l_ind] <= r_vec[r_ind]) {
			vec[k] = l_vec[l_ind];
			l_ind++;
		}
		if (l_vec[l_ind] > r_vec[r_ind]) {
			vec[k] = r_vec[r_ind];
			r_ind++;
		}
		k++;
	}
	while (l_ind < l_size)
	{
		vec[k] = l_vec[l_ind];
		k++;
		l_ind++;
	}
	while (r_ind < r_size)
	{
		vec[k] = r_vec[r_ind];
		k++;
		r_ind++;
	}
}

void PmergeMe::insertion_sort_vector(int l, int r)
{
	for (int i = l; i <= r; i++) {
		for (int j = i; j > 0; j--) {
			if (vec[j] < vec[j - 1]) {
				int temp = vec[j - 1];
				vec[j - 1] = vec[j];
				vec[j] = temp;
			}
			else
				break;
		}
	}
}

void PmergeMe::process_deque()
{
	time_t start = clock();
	for (int i = 1; i < argc; i++) {
		deq.push_back(atoi(argv[i]));
	}
	sort_deque(0, deq.size() - 1);
	time_t end = clock();
	deq_duration = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);
}

void PmergeMe::sort_deque(int l, int r)
{
	int mid;
	if (r - l > THRESHOLD) {
		mid = (l + r) / 2;
		sort_deque(l, mid);
		sort_deque(mid + 1, r);
		merge_deque(l, mid, r);
	}
	else
		insertion_sort_deque(l, r);
}

void PmergeMe::merge_deque(int l, int mid, int r)
{
	int l_size = mid - l + 1;
	int r_size = r - mid;

	std::vector<int> l_deq;
	std::vector<int> r_deq;

	for (int i = 0; i < l_size; i++) {
		l_deq.push_back(deq[l + i]);
	}
	for (int i = 0; i < r_size; i++) {
		r_deq.push_back(deq[mid + i + 1]);
	}

	int l_ind = 0;
	int r_ind = 0;
	int k = l;
	while (l_ind < l_size && r_ind < r_size)
	{
		if (l_deq[l_ind] <= r_deq[r_ind]) {
			deq[k] = l_deq[l_ind];
			l_ind++;
		}
		if (l_deq[l_ind] > r_deq[r_ind]) {
			deq[k] = r_deq[r_ind];
			r_ind++;
		}
		k++;
	}
	while (l_ind < l_size)
	{
		deq[k] = l_deq[l_ind];
		k++;
		l_ind++;
	}
	while (r_ind < r_size)
	{
		deq[k] = r_deq[r_ind];
		k++;
		r_ind++;
	}
}

void PmergeMe::insertion_sort_deque(int l, int r)
{
	for (int i = l; i <= r; i++) {
		for (int j = i; j > 0; j--) {
			if (deq[j] < deq[j - 1]) {
				int temp = deq[j - 1];
				deq[j - 1] = deq[j];
				deq[j] = temp;
			}
			else
				break;
		}
	}
}

void PmergeMe::output(const std::string s, int type)
{
	if (type == 1)
	{
		std::cout << YELLOW << s << RESET;
		std::vector<int>::iterator it = before_after.begin();
		std::vector<int>::iterator end = before_after.end();

		while (it != end)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << '\n';
		return;
	}
	std::cout << "Time to process a range of " << argc - 1 << " elements with ";
	std::cout << BLUE;
	if (type == 'v')
		std::cout << "std::vector" << RESET << " : " << vec_duration;
	else
		std::cout << "std::deque " << RESET << " : " << deq_duration;
	std::cout << "s" << std::endl;
}

bool PmergeMe::validate_input()
{
	for (int i = 1; i < argc; i++)
	{
		std::string s(argv[i]);
		for (size_t j = 0; j < s.size(); j++)
		{
			if (!isdigit(s[j]))
				return false;
		}
		before_after.push_back(atoi(s.c_str()));
	}
	return true;
}

template <typename T>
bool PmergeMe::is_sorted(T &cont)
{
	typename T::iterator it = cont.begin();
	typename T::iterator end = cont.end();

	while (it != (end - 1))
	{
		int n = *(it + 1);
		if (*it > n)
			return false;
		it++;
	}
	return true;
}
