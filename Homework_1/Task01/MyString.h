#pragma once
#include <iostream>
class MyString
{
private:
	char* str{};
	std::size_t length{};
	void copy(const MyString& other); //copy function
public:
	MyString(); //default constructor
	MyString(const MyString& copy); //copy constructor
	MyString& operator=(const MyString& other); //copy-assignment operator
	MyString(const char* strR); //constructor with parameter
	char& at(std::size_t pos); //return the symbol at choose position 
	const char& at(std::size_t pos) const; //return the symbol at choose position for constants
	char& operator[](std::size_t pos); // access to the symbol at chosen position without check for valid position
	const char& operator[](std::size_t pos) const; // access to the symbol at chosen position without check for valid position for constants
	char& front(); //access to the first symbol without check for validity
	const char& front() const; // access to the first symbol without check for validity for constants
	char& back(); // access to the last symbol without check for validity
	const char& back() const; // access to the last symbol without check for validity for constants
	bool empty() const; //check is the string is empty
	std::size_t size() const; //size of the string
	void clear(); //clear the string
	void push_back(char c); //add element at the back
	void pop_back(); //remove element at the back
	MyString& operator+=(char c); //add element at the back return *this
	MyString& operator+=(const MyString& rhs); //concatenate the parameter with the actual string
	MyString operator+(char c) const; //return string concatenated with the symbol
	MyString operator+(const MyString& rhs) const; //return string concatenated with this in the parameter
	const char* c_str() const; //return pointer to null-terminated char array similar to our string
	bool operator==(const MyString& rhs) const; //checks if two string are equal
	bool operator<(const MyString& rhs) const; //checks if the current string if before the one in the parameter HAS TO MAKE CORRECTIONS
	void free(); //delete the memory
	~MyString(); //destructor
};