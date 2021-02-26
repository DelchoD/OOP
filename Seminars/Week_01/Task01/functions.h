#pragma once
struct DynArray
{
    int size;
    int capacity;
    int *array;
};

DynArray create(int capacity = 2);
void push_back(DynArray &dynArray, int element);

void resize(DynArray &dynArray);

void pop_back(DynArray &dynArray);

void remove(DynArray &dynArray, int index);

int get(DynArray &dynArray, int index);

void print(DynArray dynArray);