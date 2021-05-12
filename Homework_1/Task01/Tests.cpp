#define CATCH_CONFIG_MAIN
#include "../Test_configuration_files/catch2.hpp"
#include "MyString.h"

TEST_CASE("Default constructor")
{
	MyString test;
	CHECK(test.c_str() == nullptr);
	CHECK(test.size() == 0);
}
TEST_CASE("Constructor with parameter")
{
	MyString test1("hello"), test2(""), test3("Hello world");
	SECTION("Empty string")
	{
		CHECK(strcmp(test2.c_str(), "") == 0);
		CHECK(test2.size() == 0);
	}
	SECTION("One word string")
	{
		CHECK(strcmp(test1.c_str(), "hello") == 0);
		CHECK(test1.size() == 5);
	}
	SECTION("More then one word string")
	{
		CHECK(strcmp(test3.c_str(), "Hello world") == 0);
		CHECK(test3.size() == 11);
	}
}
TEST_CASE("Copy constructor")
{
	MyString test("copyMe"), copy(test);
	REQUIRE(strcmp(test.c_str(), "copyMe") == 0);
	REQUIRE(test.size() == 6);
	CHECK(strcmp(test.c_str(), copy.c_str()) == 0);
	CHECK(test.size() == copy.size());
}
TEST_CASE("Copy assignment operator")
{
	SECTION("Two different")
	{
		MyString test("copyMe"), copy;
		copy = test;
		REQUIRE(strcmp(test.c_str(), "copyMe") == 0);
		REQUIRE(test.size() == 6);
		CHECK(strcmp(test.c_str(), copy.c_str()) == 0);
		CHECK(test.size() == copy.size());
	}
	SECTION("One to one")
	{
		MyString test("copyMe");
		test = test;
		REQUIRE(strcmp(test.c_str(), "copyMe") == 0);
		REQUIRE(test.size() == 6);
	}
}
TEST_CASE("Function At")
{
	MyString test("test");
	SECTION("With valid index")
	{
		CHECK(test.at(0) == 't');
		CHECK(test.at(1) == 'e');
		CHECK(test.at(2) == 's');
		CHECK(test.at(3) == 't');
	}
	SECTION("With index out of range")
	{
		//CHECK_THROWS_AS(test.at(20),std::out_of_range);
	}
}
TEST_CASE("Operator []")
{
	MyString test("test");
	SECTION("With valid index")
	{
		CHECK(test[0] == 't');
		CHECK(test[1] == 'e');
		CHECK(test[2] == 's');
		CHECK(test[3] == 't');
	}
	SECTION("With index out of range")
	{
		//CHECK_THROWS_AS(test[10],std::out_of_range);
	}
}
TEST_CASE("Function Front")
{
	SECTION("With not empty string")
	{
		MyString test("test");
		CHECK(test.front() == 't');
	}
	SECTION("With an empty string")
	{
		//MyString test;
		//CHECK_THROWS(test.front(),"str != nullptr");
	}
}
TEST_CASE("Function Back")
{
	SECTION("With not empty string")
	{
		MyString test("testMe");
		CHECK(test.back() == 'e');
	}
	SECTION("With an empty string")
	{
		//MyString test;
		//CHECK_THROWS(test.front(),"str != nullptr");
	}
}
TEST_CASE("Function Empty")
{
	SECTION("With not empty string")
	{
		MyString test("testMe");
		CHECK(test.empty() == false);
	}
	SECTION("With an empty string")
	{
		MyString test;
		CHECK(test.empty() == true);
	}
}
TEST_CASE("Function Size")
{
	SECTION("With not empty string")
	{
		MyString test("testMe");
		CHECK(test.size() == 6);
	}
	SECTION("With an empty string")
	{
		MyString test;
		CHECK(test.size() == 0);
	}
}
TEST_CASE("Function Clear")
{
	SECTION("With not empty string")
	{
		MyString test("testMe");
		REQUIRE(strcmp(test.c_str(), "testMe") == 0);
		REQUIRE(test.size() == 6);
		test.clear();
		CHECK(test.c_str() == nullptr);
		CHECK(test.size() == 0);
	}
	SECTION("With an empty string")
	{
		MyString test;
		REQUIRE(test.c_str() == nullptr);
		REQUIRE(test.size() == 0);
		test.clear();
		CHECK(test.c_str() == nullptr);
		CHECK(test.size() == 0);
	}
}
TEST_CASE("Function Push_back")
{
	SECTION("Without memory problems")
	{
		MyString test("testM");
		REQUIRE(strcmp(test.c_str(), "testM") == 0);
		REQUIRE(test.size() == 5);
		test.push_back('e');
		CHECK(strcmp(test.c_str(), "testMe") == 0);
		CHECK(test.size() == 6);
	}
	SECTION("With memory problem")
	{
		MyString test("M");
		REQUIRE(strcmp(test.c_str(), "M") == 0);
		REQUIRE(test.size() == 1);
		//CHECK_THROWS(test.push_back('e'));
	}
}
TEST_CASE("Function Pop_back")
{
	SECTION("With not null string")
	{
		MyString test("testMe");
		REQUIRE(strcmp(test.c_str(), "testMe") == 0);
		REQUIRE(test.size() == 6);
		test.pop_back();
		CHECK(strcmp(test.c_str(), "testM") == 0);
		CHECK(test.size() == 5);
	}
	SECTION("With null string")
	{
		MyString test("testMe");
		REQUIRE(strcmp(test.c_str(), "testMe") == 0);
		REQUIRE(test.size() == 6);
		test.pop_back();
		CHECK(strcmp(test.c_str(), "testM") == 0);
		CHECK(test.size() == 5);
	}
	SECTION("With memory problem")
	{
		MyString test("Me");
		REQUIRE(strcmp(test.c_str(), "Me") == 0);
		REQUIRE(test.size() == 2);
		//CHECK_THROWS(test.pop_back());
	}
}
TEST_CASE("Operator += with single symbol")
{
	MyString test("testM");
	SECTION("Without memory problems")
	{
		REQUIRE(strcmp(test.c_str(), "testM") == 0);
		REQUIRE(test.size() == 5);
		test += 'e';
		CHECK(strcmp(test.c_str(), "testMe") == 0);
		CHECK(test.size() == 6);
	}
	SECTION("With memory problems")
	{
		//CHECK_THROWS_AS(test+='e',std::out_of_range);
	}
}
TEST_CASE("Operator += with another object of this type")
{
	MyString test("test"), me("Me");
	SECTION("Without memory problems")
	{
		REQUIRE(strcmp(test.c_str(), "test") == 0);
		REQUIRE(test.size() == 4);
		REQUIRE(strcmp(me.c_str(), "Me") == 0);
		REQUIRE(me.size() == 2);
		test += me;
		CHECK(strcmp(test.c_str(), "testMe") == 0);
		CHECK(test.size() == 6);
	}
	SECTION("With memory problems")
	{
	}
}
TEST_CASE("Operator + with single symbol")
{
	MyString part1("testM"), test;
	char part2 = 'e';
	SECTION("Without memory problems")
	{
		REQUIRE(strcmp(part1.c_str(), "testM") == 0);
		REQUIRE(part1.size() == 5);
		test = part1 + part2;
		CHECK(strcmp(test.c_str(), "testMe") == 0);
		CHECK(test.size() == 6);
	}
	SECTION("With memory problems")
	{
	}
}
TEST_CASE("Operator + with another object of this type")
{
	MyString part1("test"), part2("Me"), test;
	SECTION("Without memory problems")
	{
		REQUIRE(strcmp(part1.c_str(), "test") == 0);
		REQUIRE(part1.size() == 4);
		REQUIRE(strcmp(part2.c_str(), "Me") == 0);
		REQUIRE(part2.size() == 2);
		test = part1 + part2;
		CHECK(strcmp(test.c_str(), "testMe") == 0);
		CHECK(test.size() == 6);
	}
	SECTION("With memory problems")
	{
	}
}
TEST_CASE("Function C_str")
{
	SECTION("With not empty string")
	{
		MyString test1("test"), test2("Hello world");
		REQUIRE(strcmp(test1.c_str(), "test") == 0);
		CHECK(test1.size() == 4);
		REQUIRE(strcmp(test2.c_str(), "Hello world") == 0);
		CHECK(test2.size() == 11);
	}
	SECTION("With an empty string")
	{
		MyString testEmpty;
		REQUIRE(testEmpty.c_str() == nullptr);
		CHECK(testEmpty.size() == 0);
	}
}
TEST_CASE("Operator ==")
{
	MyString test1("testMe"), test2("testMe"), test3("copy"), test4(test3);
	SECTION("True")
	{
		REQUIRE(strcmp(test1.c_str(), "testMe") == 0);
		REQUIRE(test1.size() == 6);
		REQUIRE(strcmp(test2.c_str(), "testMe") == 0);
		REQUIRE(test2.size() == 6);
		REQUIRE(strcmp(test3.c_str(), "copy") == 0);
		REQUIRE(test3.size() == 4);
		REQUIRE(strcmp(test4.c_str(), "copy") == 0);
		REQUIRE(test4.size() == 4);

		CHECK(test1 == test2);
		CHECK(test2 == test1);
		CHECK(test3 == test4);
		CHECK(test4 == test3);
	}
	SECTION("False")
	{
		CHECK_FALSE((test1 == test3));
		CHECK_FALSE(test3 == test1);
		CHECK_FALSE(test2 == test4);
		CHECK_FALSE(test4 == test2);
	}
}
TEST_CASE("Operator <")
{
	MyString test1("C"), test2("Perl"), test3("R"), test4("Java"), test5("MathLab"); //C--Java--MathLab--Perl--r
	SECTION("True")
	{
		REQUIRE(strcmp(test1.c_str(), "C") == 0);
		REQUIRE(test1.size() == 1);
		REQUIRE(strcmp(test2.c_str(), "Perl") == 0);
		REQUIRE(test2.size() == 4);
		REQUIRE(strcmp(test3.c_str(), "R") == 0);
		REQUIRE(test3.size() == 1);
		REQUIRE(strcmp(test4.c_str(), "Java") == 0);
		REQUIRE(test4.size() == 4);
		REQUIRE(strcmp(test5.c_str(), "MathLab") == 0);
		REQUIRE(test5.size() == 7);

		SECTION("Smaller than C")
		{
			CHECK(test2 < test1);
			CHECK(test3 < test1);
			CHECK(test4 < test1);
			CHECK(test5 < test1);
		}
		SECTION("Smaller than Java")
		{
			CHECK(test3 < test4);
			CHECK(test2 < test4);
			CHECK(test5 < test4);
		}
		SECTION("Smaller than MathLab")
		{
			CHECK(test3 < test5);
			CHECK(test2 < test5);
		}
		SECTION("Smaller than Perl")
		{
			CHECK(test3 < test2);
		}
	}
	SECTION("False")
	{
		SECTION("Smaller than C")
		{
			CHECK_FALSE(test1 < test2);
			CHECK_FALSE(test1 < test3);
			CHECK_FALSE(test1 < test4);
			CHECK_FALSE(test1 < test5);
		}
		SECTION("Smaller than Java")
		{
			CHECK_FALSE(test4 < test2);
			CHECK_FALSE(test4 < test3);
			CHECK_FALSE(test4 < test5);
		}
		SECTION("Smaller than MathLab")
		{
			CHECK_FALSE(test5 < test3);
			CHECK_FALSE(test5 < test2);
		}
		SECTION("Smaller than Perl")
		{
			CHECK_FALSE(test2 < test3);
		}
	}
}