#include "VehicleAllocator.h"


void VehicleAllocator::resize()
{
	capacity *= INCREMENT_STEP;
	Vehicle** temp = cars;
	try
	{
		cars = new Vehicle * [capacity];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}

	for (int i = 0; i < used; i++) {
		cars[i] = temp[i];
	}

	delete[] temp;
}

VehicleAllocator::VehicleAllocator() :capacity(INITIAL_CAPACITY), used(0)
{
	try
	{
		cars = new Vehicle * [capacity];
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	for (size_t i = 0; i < capacity; i++)
	{
		cars[i] = nullptr;
	}
}

VehicleAllocator::~VehicleAllocator()
{
	//Problems with deleting
	/*for (size_t i = 0; i < capacity; i++)
	{
			delete cars[i];
			cars[i] = nullptr;
	}*/
	delete[] cars;
	cars = nullptr;
}

Vehicle* VehicleAllocator::allocate(const char* registration, const char* description, std::size_t space)
{
	if (used >= capacity) {
		resize();
	}

	try
	{
		cars[used] = new Vehicle(registration, description, space);
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "Not enough memory!";
		throw;
	}
	used++;

	return cars[used - 1];
}
