#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Reservoir
{

	char* name;
	char* type;
	double length;
	double width;
	double depth;
public:
	explicit Reservoir(char* name_f, char* type_f, double length_f, double width_f, double depth_f) :
		name{ name_f ? new char[strlen(name_f) + 1] : new char[8] },
		type{ type_f ? new char[strlen(type_f) + 1] : new char[8] },
		length{length_f},
		width{width_f},
		depth{depth_f}

	{

		if (name_f) {
			strcpy_s(name, strlen(name_f) + 1, name_f); 
		}
		else {
			strcpy_s(name,8, "Unknown");
		}

		if (type_f) {
			strcpy_s(type, strlen(type_f) + 1, type_f);
		}
		else {
			strcpy_s(type, 8, "Unknown");
		}
	
	}


	Reservoir() :Reservoir{ nullptr,nullptr,0,0,0 } {}

	Reservoir(const Reservoir& obj) :
		name{ obj.name ? new char[strlen(obj.name) + 1]:nullptr},
		type{obj.type ? new char[strlen(obj.type) + 1] : nullptr },
		length{obj.length},
		width{ obj.width},
		depth{obj.depth}
		
	{
		if (obj.name) { strcpy_s(name, strlen(obj.name) + 1, obj.name); }
		if (obj.type) { strcpy_s(type, strlen(obj.type) + 1, obj.type); }
	}
	/*~Reservoir() {
		delete[] name;
		delete[] type;
	}*/

	bool operator==(const Reservoir& obj) {
		return strcmp(this->type, obj.type);
	}

	long long approx_volume() const;
	double surface_area() const;
	bool compare_area(const Reservoir& obj) const;
	void display();


	char* get_name() const { return name; }
	char* get_type() const { return type; }
	double get_length() const { return length; }
	double get_width() const { return width; }
	double get_depth() const { return depth; }

};

