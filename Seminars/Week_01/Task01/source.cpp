#include "functions.h"
#include <iostream>
DynArray create(int capacity = 2)
{
    DynArray dynarray;
    dynarray.capacity = capacity;
    dynarray.size = 0;
    dynarray.array = new int[dynarray.capacity];
}
void push_back(DynArray &dynArray, int element)
{
    if(dynArray.size==dynArray.capacity)
    {
        resize(dynArray);
    }
    dynArray.array[dynArray.size++] = element;
}

void resize(DynArray &dynArray)
{
    dynArray.capacity *= 2;
    int *old = dynArray.array;
    dynArray.array = new int[dynArray.capacity];
    for (int i = 0; i < dynArray.size; i++)
    {
        dynArray.array[i] = old[i];
    }
    delete[] old;
}

void pop_back(DynArray &dynArray)
{
    dynArray.size--;
}

void remove(DynArray &dynArray, int index)
{
    if(index>=0&&index<dynArray.size)
    {
        std::cout << "Not valid index " << std::endl;
        return;
    }
    for (int i = index; i < dynArray.size-1; i++)
    {
        dynArray.array[i] = dynArray.array[i + 1];
    }
    dynArray.size--;
}

int get(DynArray &dynArray, int index)
{
    if (index >= 0 && index < dynArray.size)
    {
        std::cout << "Not valid index " << std::endl;
        return;
    }
    return dynArray.array[index];
}
void print(DynArray dynArray)
{
   
}