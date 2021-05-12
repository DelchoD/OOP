#pragma once
#include "../Task01/MyString.h"
#include "../Task02/Vehicle.h"
class Garage
{
private:
	std::size_t capacity{};
	std::size_t notUsed{};
	Vehicle** carsHere{};
	void copyFunc(const Garage& copy);
	bool findDublicates(Vehicle& v);
public:
	Garage(std::size_t size); //constructor with parameter
	Garage(const Garage& copy); //copy constructor
	Garage operator=(const Garage& other); //copy-assignment operator
	void insert(Vehicle& v); //function with which to insert vehicle in the garage with checking for memory and space problem
	void erase(const char* registration); //function to delete a car with given registration number
	const Vehicle& at(std::size_t pos) const; //access to the vehicle at chosen position for constants
	const Vehicle& operator[](std::size_t pos) const; //access to the element at chosen position via [] for constants
	bool empty() const; //checks if the garage is empty
	std::size_t size() const; //returns the used capacity of the garage
	void clear(); //clear the content of the garage
	const Vehicle* find(const char* registration) const; //returns the vehicle with given registration number, if it does not exist return nullptr for constants
	~Garage();
	void print();
};
