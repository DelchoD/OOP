#include "../Task02/Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const char* registration, const char* descriptionR, std::size_t space) :registrationNumber(registration), description(descriptionR), parkspace(space)
{
}

const char* Vehicle::get_registration() const
{
	return registrationNumber.c_str();
}

const char* Vehicle::get_description() const
{
	return description.c_str();
}

std::size_t Vehicle::get_space() const
{
	return parkspace;
}

