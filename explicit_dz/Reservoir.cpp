#include "Reservoir.h"


long long Reservoir::approx_volume()const {
	return width * length * depth;
}

double Reservoir::surface_area() const {
	return width * length;
}

bool Reservoir::compare_area(const Reservoir& obj) const {
	return this->surface_area() > obj.surface_area();
}

void Reservoir::display() {
	cout <<
		"name: " << name << "\n" <<
		"type: " << type << "\n" <<
		"length: " << length << " km" << "\n" <<
		"width: " << width << " km" << "\n" <<
		"depth: " << depth << " m" << "\n";
}


