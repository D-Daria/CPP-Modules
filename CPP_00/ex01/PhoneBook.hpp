#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

# define CONTACT_MAX 8

class PhoneBook {
	
	private:
		Contact contacts[CONTACT_MAX];
		int c_index;
	
	public:
		PhoneBook(void);
		void setGlobalIndex(int c_index);
		int getGlobalIndex(void);
		void setDefaultContacts(void);
		int addContact(void);
		void displayAvailableContacts(void);
		int	displayByIndex(void);
		~PhoneBook(void);
};

#endif