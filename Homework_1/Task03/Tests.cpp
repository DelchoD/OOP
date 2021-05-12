//#define CATCH_CONFIG_MAIN
//#include "../Test_configuration_files/catch2.hpp"
//#include "../Task01/MyString.h"
//#include "../Task02/Vehicle.h"
//#include "VehicleAllocator.h"
//#include "Garage.h"
//
//TEST_CASE("Constructor with parameter")
//{
//	Garage test(10);
//	REQUIRE(test.size() == 0);
//}
//TEST_CASE("Copy constructor")
//{
//	Garage test(10), copy(test);
//	CHECK(test.size() == 0);
//	REQUIRE(copy.size() == 0);
//}
//TEST_CASE("Operator =")
//{
//	SECTION("Two different object")
//	{
//		Garage test(10), copy(5);
//		CHECK(test.size() == 0);
//		CHECK(copy.size() == 0);
//		test = copy;
//		REQUIRE(test.size() == 0);
//		REQUIRE(copy.size() == 0);
//	}
//	SECTION("One object")
//	{
//		Garage test(10);
//		CHECK(test.size() == 0);
//		test = test;
//		REQUIRE(test.size() == 0);
//	}
//}
//TEST_CASE("Insert vehicle function")
//{
//	SECTION("With free places in the parking")
//	{
//		Garage testGarage(10);
//		CHECK(testGarage.size() == 0);
//		VehicleAllocator car;
//		testGarage.insert(*car.allocate("CB9999CB", "TEST", 3));
//		REQUIRE(testGarage.size() == 1);
//	}
//	SECTION("Overload in the parking")
//	{
//		Garage testGarage(10);
//		CHECK(testGarage.size() == 0);
//		VehicleAllocator car;
//		CHECK_THROWS(testGarage.insert(*car.allocate("CB9999CB", "TEST", 20)));
//		REQUIRE(testGarage.size() == 0);
//	}
//}
//TEST_CASE("Erase function")
//{
//	Garage testGarage(10);
//	CHECK(testGarage.size() == 0);
//	VehicleAllocator testCar1, testCar2;
//	testGarage.insert(*testCar1.allocate("CB9999CB", "TEST", 3));
//	testGarage.insert(*testCar2.allocate("CB7777CB", "COPY", 6));
//	CHECK(testGarage.size() == 2);
//	testGarage.erase("CB9999CB");
//	REQUIRE(testGarage.size() == 1);
//}
//TEST_CASE("At function")
//{
//	SECTION("With valid index")
//	{
//		Garage testGarage(10);
//		CHECK(testGarage.size() == 0);
//		VehicleAllocator testCar1, testCar2;
//		testGarage.insert(*testCar1.allocate("CB9999CB", "TEST", 3));
//		testGarage.insert(*testCar2.allocate("CB7777CB", "COPY", 6));
//		CHECK(testGarage.size() == 2);
//		REQUIRE(strcmp(testGarage.at(0).get_registration(), "CB9999CB") == 0);
//		REQUIRE(strcmp(testGarage.at(0).get_description(), "TEST") == 0);
//		REQUIRE(testGarage.at(0).get_space() == 3);
//	}
//	SECTION("With non-valid index")
//	{
//		Garage testGarage(10);
//		CHECK(testGarage.size() == 0);
//		VehicleAllocator car;
//		testGarage.insert(*car.allocate("CB9999CB", "TEST", 3));
//		CHECK(testGarage.size() == 1);
//		REQUIRE_THROWS_AS(testGarage.at(12), std::out_of_range);
//	}
//}
//TEST_CASE("[] operator")
//{
//	SECTION("With valid index")
//	{
//		Garage testGarage(10);
//		CHECK(testGarage.size() == 0);
//		VehicleAllocator testCar1, testCar2;
//		testGarage.insert(*testCar1.allocate("CB9999CB", "TEST", 3));
//		testGarage.insert(*testCar2.allocate("CB7777CB", "COPY", 6));
//		CHECK(testGarage.size() == 2);
//		REQUIRE(strcmp(testGarage[0].get_registration(), "CB9999CB") == 0);
//		REQUIRE(strcmp(testGarage[0].get_description(), "TEST") == 0);
//		REQUIRE(testGarage[0].get_space() == 3);
//	}
//	SECTION("With non-valid index")
//	{
//	}
//}
//TEST_CASE("Empty function")
//{
//	Garage testGarage(10);
//	SECTION("Empty")
//	{
//		CHECK(testGarage.size() == 0);
//		REQUIRE(testGarage.empty());
//	}
//	SECTION("With car in it")
//	{
//		VehicleAllocator car;
//		testGarage.insert(*car.allocate("CB9999CB", "TEST", 3));
//		CHECK(testGarage.size() == 1);
//		REQUIRE(!testGarage.empty());
//	}
//}
//TEST_CASE("Size function")
//{
//	Garage testGarage(10);
//	SECTION("Empty")
//	{
//		REQUIRE(testGarage.size() == 0);
//	}
//	SECTION("With car in it")
//	{
//		VehicleAllocator testCar1, testCar2;
//		testGarage.insert(*testCar1.allocate("CB9999CB", "TEST", 3));
//		testGarage.insert(*testCar2.allocate("CB7777CB", "COPY", 6));
//		REQUIRE(testGarage.size() == 2);
//	}
//}
//TEST_CASE("Clear function")
//{
//	Garage testGarage(10);
//	VehicleAllocator testCar1, testCar2;
//	testGarage.insert(*testCar1.allocate("CB9999CB", "TEST", 3));
//	testGarage.insert(*testCar2.allocate("CB7777CB", "COPY", 6));
//	CHECK(testGarage.size() == 2);
//	testGarage.clear();
//	REQUIRE(testGarage.size() == 0);
//}
//TEST_CASE("Find function")
//{
//	Garage testGarage(10);
//	VehicleAllocator testCar1, testCar2;
//	testGarage.insert(*testCar1.allocate("CB9999CB", "TEST", 3));
//	testGarage.insert(*testCar2.allocate("CB7777CB", "COPY", 6));
//	SECTION("With not existing car")
//	{
//		//CHECK(testGarage.find("CB1234CB") == nullptr);
//	}
//	SECTION("With existing car")
//	{
//		CHECK(testGarage.size() == 2);
//		REQUIRE(strcmp(testGarage.find("CB9999CB")->get_registration(), "CB9999CB") == 0);
//		REQUIRE(strcmp(testGarage.find("CB9999CB")->get_description(), "TEST") == 0);
//		REQUIRE(testGarage.find("CB9999CB")->get_space() == 3);
//	}
//
//}