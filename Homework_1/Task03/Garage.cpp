#include "Garage.h"
#include <cassert>
void Garage::copyFunc(const Garage& copy)
{
	capacity = copy.capacity;
	notUsed = copy.notUsed;

	try
	{
		carsHere = new Vehicle * [copy.capacity];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	for (size_t i = 0; i < capacity; i++)
	{
		carsHere[i] = copy.carsHere[i];
	}
}

bool Garage::findDublicates(Vehicle& v)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if ((carsHere[i] != nullptr) && (strcmp(carsHere[i]->get_registration(), v.get_registration()) == 0))
		{
			return false;
		}
	}
	return true;
}

Garage::Garage(std::size_t size) :capacity(size), notUsed(size)
{
	try
	{
		carsHere = new Vehicle * [size];
	}
	catch (const std::exception&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	for (size_t i = 0; i < capacity; i++)
	{
		carsHere[i] = nullptr;
	}
}

Garage::Garage(const Garage& copy)
{
	copyFunc(copy);
}

Garage Garage::operator=(const Garage& other)
{
	if (this != &other)
	{
		copyFunc(other);
	}
	return *this;
}

void Garage::insert(Vehicle& v)
{
	if ((v.get_space() <= notUsed) && (findDublicates(v)))
	{
		for (size_t i = 0; i < capacity; i++)
		{
			if (carsHere[i] == nullptr)
			{
				//carsHere[i] = new  Vehicle(v.get_registration(), v.get_description(), v.get_space());
				carsHere[i] = &v; //strong exception is made in the constructor because there we allocate memory for the array
				notUsed -= v.get_space();
				return;
			}
		}
	}
	else
	{
		throw std::length_error("There are no free places in the garage!");
	}
}

void Garage::print()
{
	//std::cout << capacity << " " << notUsed << " " << std::endl;
	for (size_t i = 0; i < capacity; i++)
	{
		if (carsHere[i] != nullptr)
		{
			std::cout << carsHere[i]->get_registration() << " " << carsHere[i]->get_description() << " " << carsHere[i]->get_space() << std::endl;
		}
	}
}

void Garage::erase(const char* registration)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (strcmp(registration, carsHere[i]->get_registration()) == 0)
		{
			notUsed -= carsHere[i]->get_space();
			delete carsHere[i];
			carsHere[i] = nullptr;

			return;
		}
	}
}

const Vehicle& Garage::at(std::size_t pos) const
{
	if (pos >= capacity || pos < 0)
	{
		throw std::out_of_range("This is not a valid index");
	}
	return *carsHere[pos];
}

const Vehicle& Garage::operator[](std::size_t pos) const
{
	assert(pos <= 0 || pos >= capacity);
	return *carsHere[pos];
}

bool Garage::empty() const
{
	return!(capacity != notUsed);
}

std::size_t Garage::size() const //could be made with a variable but with this method we don't care for rearranging the cars(possible because in the task it is allowd)
{
	size_t carsparked = 0;
	for (size_t i = 0; i < capacity; i++)
	{
		if (carsHere[i] != nullptr)
		{
			carsparked++;
		}
	}
	return carsparked;
}

void Garage::clear()
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (carsHere[i] != nullptr)
		{
			delete carsHere[i];
			carsHere[i] = nullptr;
		}
	}
	notUsed = 0;
}

const Vehicle* Garage::find(const char* registration) const
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (strcmp(registration, carsHere[i]->get_registration()) == 0)
		{
			return carsHere[i];
		}
	}
	return nullptr;
}

Garage::~Garage()
{
	if (carsHere != nullptr)
	{
		for (size_t i = 0; i < capacity; i++)
		{
			if (carsHere[i] != nullptr)
			{
				delete carsHere[i];
				carsHere[i] = nullptr;
			}
		}
		delete[] carsHere;
		carsHere = nullptr;
		capacity = 0;
		notUsed = 0;
	}
}
