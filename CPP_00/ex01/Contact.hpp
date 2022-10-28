#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>

# define RED		"\033[0;31m"
# define YELLOW		"\033[0;33m"
#define BOLDYELLOW  "\033[1m\033[33m"
# define BLUE		"\033[0;34m"
# define GREEN		"\033[0;32m"
# define BREAK		"\033[0m"

class Contact {

	private:
		bool		isCreated;
		int			m_index;
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickname;
		std::string m_phoneNumber;
		std::string m_darkestSecret;
	
	public:
		void setIsCreated(bool ans);
		bool getIsCreated(void);
		void setIndex(int index);
		int getIndex(void);
		void setFirstName(std::string firstName);
		std::string getFirstName(void);
		void setLastName(std::string firstName);
		std::string getLastName(void);
		void setNickname(std::string nickname);
		std::string getNickname(void);
		void setPhoneNumber(std::string phoneNumber);
		std::string getPhoneNumber(void);
		void setDarkestSecret(std::string darkestSecret);
		std::string getDarkestSecret(void);
};

#endif