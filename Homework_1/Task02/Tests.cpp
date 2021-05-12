#define CATCH_CONFIG_MAIN
#include "../Test_configuration_files/catch2.hpp"
#include "../Task01/MyString.h"
#include "Vehicle.h"

TEST_CASE("Constructor with three parameters")
{
	Vehicle car1("CB9999CB", "Audi", 3), car2("CB8888CB", "BMW", 2), car3("CA7777CA", "Mercedes", 5);

	REQUIRE(strcmp(car1.get_registration(), "CB9999CB") == 0);
	REQUIRE(strcmp(car1.get_description(), "Audi") == 0);
	REQUIRE(car1.get_space() == 3);

	REQUIRE(strcmp(car2.get_registration(), "CB8888CB") == 0);
	REQUIRE(strcmp(car2.get_description(), "BMW") == 0);
	REQUIRE(car2.get_space() == 2);

	REQUIRE(strcmp(car3.get_registration(), "CA7777CA") == 0);
	REQUIRE(strcmp(car3.get_description(), "Mercedes") == 0);
	REQUIRE(car3.get_space() == 5);
}
TEST_CASE("Function for registration number")
{
	Vehicle test("TEST", "test", 5);
	CHECK(strcmp(test.get_registration(), "TEST") == 0);
}
TEST_CASE("Function for description")
{
	Vehicle test("TEST", "test", 5);
	CHECK(strcmp(test.get_description(), "test") == 0);
}
TEST_CASE("Function for park space")
{
	Vehicle test("TEST", "test", 5);
	CHECK(test.get_space() == 5);
}