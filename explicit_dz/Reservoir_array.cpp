#include "Reservoir_array.h"

void Reservoir_array::resize(int new_max_size) {
	Reservoir* new_arr = new Reservoir[new_max_size];
	for (int i = 0; i < size; i++) {
		new_arr[i] = reservoirs[i];
	}
	delete[] reservoirs;
	reservoirs = new_arr;
	max_size = new_max_size;
}

void Reservoir_array::add_reservoir(const Reservoir& reservoir) {
	if (size >= max_size) {
		resize(max_size + 2);
	}
	reservoirs[size] = reservoir;
	size += 1;
}

void Reservoir_array::add_and_initialization() {
	char* name = new char[50];
	char* type = new char[50];
	double length, width, depth;
	cout << "Input name: ";
	cin.getline(name, 50);
	cout << "Input type: ";
	cin.getline(type, 50);
	cout << "Input length(km): "; cin >> length;
	cout << "Input width(km): "; cin >> width;
	cout << "Input depth(m): "; cin >> depth;

	add_reservoir(Reservoir(name, type, length, width, depth));
}


void Reservoir_array::display_all_reservoirs() const{
	FILE* f;
	fopen_s(&f, "reservoirs.txt", "w");
	if (!f) {
		cout << "eror\n";
		return;
	}


	for (int i = 0; i < size; i++) {
		reservoirs[i].display();
		cout << "____________________________________\n";
		fprintf(f, "\nname: %s\n", reservoirs[i].get_name());
		fprintf(f, "type: %s\n", reservoirs[i].get_type());
		fprintf(f, "lenght: %.2f\n", reservoirs[i].get_length());
		fprintf(f, "width: %.2f\n", reservoirs[i].get_width());
		fprintf(f, "depth: %.2f\n\n", reservoirs[i].get_depth());
	}
	_fcloseall();
	cout << "Data written to file successfully.\n";
}