#pragma once
#include "../Task02/Vehicle.h"
const int INCREMENT_STEP = 2;
const int INITIAL_CAPACITY = 2;

class VehicleAllocator
{
private:
    //capacity and used for the purpose of the container
    size_t capacity=INITIAL_CAPACITY;
    size_t used{};
    Vehicle** cars{};

    void resize();

public:
    // Creates empty allocator
    VehicleAllocator();

    //Delete the allocator and releases the allocated memory
    //here we need to store information about all objects
    ~VehicleAllocator();

    //Create new vehicle object and return pointer to the object
    Vehicle* allocate(const char* registration, const char* description, std::size_t space);
};

