#include <iostream>
#include "Reservoir_array.h"
using namespace std;

int main()
{

	char* name{ new char[10] {"Black sea"} };
	char* type{ new char[4] {"Sea"} };
	Reservoir_array r;
	
	int choice;

	do
	{
		r.add_and_initialization();
		cout << "Do you want to create a new reservoir\n1 - yes\n2 - no\n- ";
		cin >> choice;
		cin.ignore();
	} while (choice == 1);

	r.display_all_reservoirs();
	cout << "Is the first reservoir bigger than the second reservoir: " << (r.get_reservoirs()[0].compare_area(r.get_reservoirs()[1]) ? "yes\n":"no\n");

}