# ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date {

	private:
	
	public:
		int year;
		int month;
		int day;

		Date();
		Date(int year, int month, int day);
		Date(const Date &copy);
		Date &operator=(const Date &copy);
		~Date();

		int getYear() const;
		int getMonth() const;
		int getDay() const;

		Date findClosestLowerDate();

		bool operator>(const Date &dt);
		bool operator<(const Date &dt);
		bool operator==(const Date &dt);
		bool operator!=(const Date &dt);

};

std::ostream &operator<<(std::ostream &os, const Date &dt);
bool operator<(const Date &d1, const Date &d2);

# endif
