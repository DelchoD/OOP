#include "MyString.h"
#include <cstring>
#include <stdexcept>
#include <cassert>

MyString::MyString() :str(nullptr), length(0)
{
}

MyString::MyString(const MyString& copy)
{
	this->copy(copy.str);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		copy(other.str);
	}
	return *this;
}

void MyString::copy(const MyString& other)
{
	free();

	try
	{
		str = new char[strlen(other.str) + 1];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	strcpy(str, other.str);
	length = strlen(str);
}

MyString::MyString(const char* strR)
{
	try
	{
		str = new char[strlen(strR) + 1];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	strcpy(this->str, strR);
	length = strlen(strR);
}

char& MyString::at(std::size_t pos)
{

	if (pos >= length || pos < 0)
	{
		throw std::out_of_range("This is not a valid index");
	}
	return *(str + pos);

}

const char& MyString::at(std::size_t pos) const
{
	if (pos >= length || pos < 0)
	{
		throw std::out_of_range("This is not a valid index");
	}
	return *(str + pos);
	//return const_cast<MyString*>(this)->at(pos);
}

char& MyString::operator[](std::size_t pos)
{
	assert(pos >= 0 || pos < length);
	return str[pos];
}

const char& MyString::operator[](std::size_t pos) const
{
	assert(pos >= 0 || pos < length);
	return str[pos];
	//return const_cast<MyString*>(this)->str[pos];
}

char& MyString::front()
{
	assert(str != nullptr);
	return *str;
}

const char& MyString::front() const
{
	assert(str != nullptr);
	return *str;
	//return const_cast<MyString*>(this)->str[0];
}

char& MyString::back()
{
	assert(str != nullptr);
	return *(str + length - 1);
}

const char& MyString::back() const
{
	assert(str != nullptr);
	return *(str + length - 1);
	//return const_cast<MyString*>(this)->str[length-1];
}

bool MyString::empty() const
{
	return !str;
}

std::size_t MyString::size() const
{
	return length;
}

void MyString::clear()
{
	if (str)
	{
		free();
		str = nullptr;
		length = 0;
	}
}

void MyString::push_back(char c)
{
	char* temp = nullptr;
	try
	{
		temp = new char[length + 2]{};

	}
	catch (const std::bad_alloc&) //strong exception guarantee
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	for (std::size_t i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	temp[length] = c;
	temp[length + 1] = '\0';

	free();
	try
	{
		str = new char[strlen(temp) + 1];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	strcpy(str, temp);
	length = strlen(str);

	delete[] temp;

}

void MyString::pop_back()
{
	assert(str != nullptr);

	char* temp = nullptr;
	try
	{
		temp = new char[length] {};
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	strncpy(temp, str, length - 1);
	temp[length - 1] = '\0';

	free();
	try
	{
		str = new char[strlen(temp) + 1];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	strcpy(str, temp);
	length = strlen(str);

	delete[] temp;
}

MyString& MyString::operator+=(char c)
{
	char* temp = nullptr;
	try
	{
		temp = new char[length + 2]{};
	}
	catch (const std::bad_alloc&) //strong exception guarantee
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	for (std::size_t i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	temp[length] = c;
	temp[length + 1] = '\0';


	free();
	length = length + 1;
	try
	{
		str = new char[length + 1];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	strcpy(str, temp);

	delete[] temp;
	return *this;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	std::size_t lenTemp = length + strlen(rhs.str) + 1;
	char* temp = nullptr;

	try
	{
		temp = new char[lenTemp] {};
	}
	catch (const std::bad_alloc&) //strong exception guarantee
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	strcat(temp, str);
	strcat(temp, rhs.str);

	free();
	length = lenTemp - 1;

	try
	{
		str = new char[lenTemp + 1];
	}
	catch (const std::exception&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	strcpy(str, temp);

	delete[] temp;
	return *this;
}

MyString MyString::operator+(char c) const
{
	char* temp = nullptr;
	try
	{
		temp = new char[length + 2]{};
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	for (std::size_t i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	temp[length] = c;
	temp[length + 1] = '\0';

	return temp;
	delete[] temp;
}

MyString MyString::operator+(const MyString& rhs) const
{
	char* temp = nullptr;
	std::size_t lenTemp = this->length + strlen(rhs.str);

	try
	{
		temp = new char[lenTemp] {};
	}
	catch (const std::exception&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	strcat(temp, str);
	strcat(temp, rhs.str);

	return temp;
	delete[] temp;
}

const char* MyString::c_str() const
{
	if (!str) { return nullptr; }
	else
	{
		char* temp = nullptr;
		try
		{
			temp = new  char[length] {};
		}
		catch (const std::bad_alloc&)
		{
			temp = nullptr;
			std::cerr << "Not enough memory!";
		}
		strcpy(temp, str);
		return temp;
	}
}

bool MyString::operator==(const MyString& rhs) const
{
	return !(length != rhs.length);
}

bool MyString::operator<(const MyString& rhs) const
{
	bool compare = false;
	for (size_t i = 0; i < length; i++)
	{
		if (rhs.str[i] < str[i])
		{
			return true;
		}
		else if (rhs.str[i] == str[i])
		{
		}
		else
		{
			return false;
		}
	}
	return compare;
}

void MyString::free()
{
	delete[] str;
	str = nullptr;
}

MyString::~MyString()
{
	free();
}
