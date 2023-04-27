#include "functions/vehicle.h"  // include #include <iostream>
#include <conio.h>

int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int menu1() {
	std::system("cls");
	std::cout << "Add a vehicle: Ins" << endl;
	std::cout << "Delete a vehicle: Del" << endl;
	std::cout << "Write list of vehicles: Enter" << endl;
	std::cout << "Find the vehicle with the maximum tax: Space" << endl;
	std::cout << "\nExit: Esc" << endl;
	while (true) {
		int key = get_key();
		//Del			//Ins			//Space			//Esc			//Enter		   
		if ((key == 83) || (key == 82) || (key == 32) || (key == 27) || (key == 13)) return key;
	}
}
// Function of Exit
void exit() {
	while (true) {
		int key = get_key();
		if (key == 27) break;
	}
}
// Function Check number of figures in space
bool check_size(VehicleList& list) {
	if (list.size() == 0) {
		std::cout << "We don't have vehicle!" << endl;
		std::cout << "\nExit: Esc";
		exit();
		return true;
	}
	return false;
}
int main() {
	VehicleList list;
	double stavka;
	bool WasInsert = false;
	while (true) {
		int key = menu1();
		// Ins 
		if (key == 82) {
			std::system("cls");
			if (!WasInsert) {
				while (true) {
					std::cout << "Write stavka: ";
					std::cin >> stavka;
					if (stavka > 0) {
						WasInsert = true;
						break;
					}
					std::system("cls");
					std::cout << "Invalid stavka!\nTry again\n*------------*\n";
				}

			}
			int index;
			while (true) {
				std::cout << "Range of index: 0 - " << list.size() << endl;
				std::cout << "Write index: ";
				std::cin >> index;
				if (index >= 0 && index <= list.size()) break;
				system("cls");
				cout << "Invalid index!\n  Try again\n*------------*\n";
			}
			system("cls");
			VehicleType type;
			int index_type;
			while (true) {
				cout << "List of figures:\nCAR - 0\nTRUCK - 1\nMOTOCYCLE - 2\n-----------\nWrite type of vehicle: ";
				std::cin >> index_type;
				switch (index_type) {
				case 0: 
					type = CAR;
					break;
				case 1:
					type = TRUCK;
					break;
				case 2:
					type = MOTOCYCLE;
					break;
				default:
					system("cls");
					cout << "Invalid type!\n  Try again\n*------------*\n";
					continue;
				}
				break;
			}
			system("cls");
			double volume_of_engine = 0;
			double _tonnage = 0;
			Model model;
			switch (type) {
			case CAR:
			case MOTOCYCLE:
				
				while (true)
				{
					system("cls");
					cout << "Write model: ";
					int index_type;
					while (true) {
						cout << "List of models:\nFORD - 0\nBMW - 1\nHONDA - 2\nTOYOTA -3\n-----------\nWrite number of model: ";
						std::cin >> index_type;
						switch (index_type) {
						case 0:
							model = FORD;
							break;
						case 1:
							model = BMW;
							break;
						case 2:
							model = HONDA;
							break;
						case 3:
							model = TOYOTA;
							break;
						default:
							system("cls");
							cout << "Invalid model!\n  Try again\n*------------*\n";
							continue;
						}
						break;
					}
					break;
				}
				system("cls");
				while (true)
				{
					cout << "Write volume of engine: ";
					std::cin >> volume_of_engine;
					if (volume_of_engine > 0) break;
					else
					{
						system("cls");
						cout << "Invalid volume!\n  Try again\n*------------*\n";
						continue;
					}
				}
				system("cls");
				break;
			case TRUCK:
				while (true)
				{
					system("cls");
					cout << "Write model: ";
					int index_type;
					while (true) {
						cout << "List of models:\nFORD - 0\nBMW - 1\nHONDA - 2\nTOYOTA -3\n-----------\nWrite number of model: ";
						std::cin >> index_type;
						switch (index_type) {
						case 0:
							model = FORD;
							break;
						case 1:
							model = BMW;
							break;
						case 2:
							model = HONDA;
							break;
						case 3:
							model = TOYOTA;
							break;
						default:
							system("cls");
							cout << "Invalid model!\n  Try again\n*------------*\n";
							continue;
						}
						break;
					}
					break;
				}
				system("cls");
				while (true)
				{
					cout << "Write volume of engine: ";
					std::cin >> volume_of_engine;
					if (volume_of_engine > 0) break;
					else
					{
						system("cls");
						cout << "Invalid volume!\n  Try again\n*------------*\n";
						continue;
					}
				}
				system("cls");
				while (true)
				{
					cout << "Write tonnage: ";
					std::cin >> _tonnage;
					if (_tonnage > 0) break;
					else
					{
						system("cls");
						cout << "Invalid first line!\n  Try again\n*------------*\n";
						continue;
					}
				}
				system("cls");
				break;
			}
			Vehicle vehicle(type, model, volume_of_engine, _tonnage);
			list.insert(index, vehicle);
		}
		// Del
		if (key == 83) {
			system("cls");
			if (check_size(list)) continue;
			int index;
			while (true) {
				cout << "Range of index: 0 - " << list.size() - 1 << endl;
				cout << "Write index: ";
				std::cin >> index;
				if (index >= 0 && index <= list.size() - 1) break;
				system("cls");
				cout << "Invalid index!\n  Try again\n*------------*\n";
			}
			list.remove(index); // Delete the figure in space
			system("cls");
			cout << "Vehicle deleted!" << endl << "Exit: Esc";
			exit();
		}
		// Enter
		if (key == 13) {
			system("cls");
			if (check_size(list)) continue;
			cout << "Exit: Esc\n\n";
			cout << list;
			exit();
		}
		// Space
		if(key == 32){
			system("cls");
			if (check_size(list)) continue;
			cout << "Vehicle with max tax:" << endl;
			cout << list.highest_transport_tax(list, stavka);
			cout << "\tTax: " << list.highest_transport_tax(list, stavka).transport_tax(stavka) << endl;
			cout << "\nExit: Esc";
			exit();
		}
		// Escape
		if (key == 27) { break; }
	}
	return 0;
}