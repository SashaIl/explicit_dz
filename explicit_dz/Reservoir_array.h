#include "Reservoir.h"
#pragma once
class Reservoir_array
{

	int size;
	int max_size;
	Reservoir* reservoirs;
	Reservoir r;
public:

	Reservoir_array() : size{ 0 }, max_size{ 2 } 
	{
		reservoirs = new Reservoir[max_size];
	}

	Reservoir_array(const Reservoir_array& obj) : size{ obj.size }, max_size{ obj.max_size }, reservoirs{ max_size ? new Reservoir[max_size] : nullptr } {}

	~Reservoir_array() {
		delete[] reservoirs; 
		delete[] r.get_name();
		delete[] r.get_type();
	}
	 
	void resize(int);
	void add_reservoir(const Reservoir&);
	void display_all_reservoirs() const;
	void add_and_initialization();
	Reservoir* get_reservoirs() { return reservoirs; }
};

