#pragma once
#include "../Task01/MyString.h"
class Vehicle
{
private:
	MyString registrationNumber{};
	MyString description{};
	std::size_t parkspace{};
public:
	Vehicle(const char* registration, const char* description, std::size_t space); //constructor with parameters
	const char* get_registration() const; //returns the registration number as a c-style string
	const char* get_description() const; //returns the description as a c-style string
	std::size_t get_space() const; //returns the space used by the vehicle to park
};

