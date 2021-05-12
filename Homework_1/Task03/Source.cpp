#include "Garage.h"
#include "VehicleAllocator.h"

int main()
{
	VehicleAllocator myCars;
	size_t sizeOfTheGarage = 0, tempSpace = 0;
	char tempReg[80]{}, tempDes[1024]{};
	int choice;

	std::cout << "Welcome to your garage management!\n";
	std::cout << "Please select the size of your garage: ";
	std::cin >> sizeOfTheGarage;
	std::cin.get();
	std::cout << std::endl;

	Garage myGarage(sizeOfTheGarage); //the parking could be made resize-able but I think that the Garage is something that we build and we can not change the number of spaces used by it
	do
	{
		std::cout << "Please select an option from the main menu: \n";
		std::cout << "Main menu:\n";
		std::cout << "1. Add a car in the garage,\n";
		std::cout << "2. Print all the cars in the garage,\n";
		std::cout << "3. Erase a car with given registration number,\n";
		std::cout << "4. Print a car at chosen position,\n";
		std::cout << "5. Check if the garage is empty,\n";
		std::cout << "6. Get the number of parked car,\n";
		std::cout << "7. Find a car with given registration number,\n";
		std::cout << "8. Clear the content of the garage,\n";
		std::cout << "9. Exit.\n";
		std::cout << "Please make your choice: \n";
		std::cin >> choice;
		std::cout << std::endl;
		system("cls");
		std::cout << "------------------------------------------------------------\n";

		switch (choice)
		{
			case 1:
			{
				std::cout << "Enter registration number of the vehicle or 0 to terminate: ";
				std::cin >> tempReg;
				std::cout << "Enter description of the vehicle or 0 to terminate: ";
				std::cin >> tempDes;
				std::cout << "Enter park spaces used by the vehicle or 0 to terminate: ";
				std::cin >> tempSpace;
				try
				{
					myGarage.insert(*myCars.allocate(tempReg, tempDes, tempSpace));
				}
				catch (const std::length_error& e)
				{
					std::cout << e.what() << " Please try with another car\n";
				}
				break;
			}
			case 2: myGarage.print(); break;
			case 3:
			{
				std::cout << "Enter registration number: ";
				std::cin >> tempReg;
				myGarage.erase(tempReg);
				break;
			}
			case 4:
			{
				std::cout << "Enter index of car: ";
				std::cin >> tempSpace;
				std::cout << myGarage.at(tempSpace - 1).get_registration() << " " << myGarage.at(tempSpace - 1).get_description() << " " << myGarage.at(tempSpace - 1).get_space() << std::endl;
				break;
			}
			case 5: std::cout << std::boolalpha << myGarage.empty() << std::endl; break;
			case 6: std::cout << myGarage.size() << std::endl; break;
			case 7:
			{
				std::cout << "Enter registration number: ";
				std::cin >> tempReg;
				std::cout << myGarage.find(tempReg)->get_registration() << " " << myGarage.find(tempReg)->get_description() << " " << myGarage.find(tempReg)->get_space() << std::endl;
				break;
			}
			case 8: myGarage.clear(); break;
			case 9: return 0; break;
			default:
				break;
			}
			std::cout << "------------------------------------------------------------\n";
	} while (true);
	do
	{
		std::cout << "Enter registration number of the vehicle or 0 to terminate: ";
		std::cin >> tempReg;
		if (tempReg[0] == '0') { break; }

		std::cout << "Enter description of the vehicle or 0 to terminate: ";
		std::cin >> tempDes;
		if (tempDes[0] == '0') { break; }

		std::cout << "Enter park spaces used by the vehicle or 0 to terminate: ";
		std::cin >> tempSpace;
		if (tempSpace == 0) { break; }

		try
		{
			myGarage.insert(*myCars.allocate(tempReg, tempDes, tempSpace));
		}
		catch (const std::length_error& e)
		{
			std::cout << e.what() << " Please try with another car\n";
		}

	} while (tempSpace != 0 || tempReg[0] != '0' || tempDes[0] != '0');
	myGarage.print();
	return 0;
}
