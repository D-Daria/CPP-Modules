#include "Contact.hpp"

void Contact::setIsCreated(bool ans)
{
	isCreated = ans;
}

bool	Contact::getIsCreated(void)
{
	return (isCreated);
}

void Contact::setIndex(int index)
{
	m_index = index;
}

int	Contact::getIndex(void)
{
	return (m_index);
}

void Contact::setFirstName(std::string firstName)
{
	m_firstName = firstName;
}

std::string Contact::getFirstName(void)
{
	return (m_firstName);
}

void Contact::setLastName(std::string lastName)
{
	m_lastName = lastName;
}

std::string Contact::getLastName(void)
{
	return (m_lastName);
}

void Contact::setNickname(std::string nickname)
{
	m_nickname = nickname;
}

std::string Contact::getNickname(void)
{
	return (m_nickname);
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber(void)
{
	return (m_phoneNumber);
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	m_darkestSecret = darkestSecret;
}

std::string Contact::getDarkestSecret(void)
{
	return (m_darkestSecret);
}
