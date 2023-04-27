#include <functions/vehicle.h>
#include <stdexcept>

using namespace std;


}
ostream& operator<<(std::ostream& stream, VehicleList& vList) {
	for (int i = 0; i < vList.size(); ++i) {
		stream << vList[i] << endl;
	}
	return stream;
}

 Vehicle::Vehicle(VehicleType type, Model model, float volume_of_engine, float tonnage)
{
	this->_type = type;
	this->_model = model;
	this->_volume_of_engine = volume_of_engine;
	this->_tonnage = tonnage;
}

Vehicle::Vehicle() {
	_type = CAR;
	_model = BMW;
	_volume_of_engine = 0.0;
	_tonnage = 0.0;
}

float Vehicle::transport_tax(float s) {
	switch (_type) {
	case CAR:
		return _volume_of_engine * s;
	case TRUCK:
		return _volume_of_engine * s * ((_tonnage / 2) + 1);
	case MOTOCYCLE:
		return 0.3 * s * _volume_of_engine;
	default: 
	    throw runtime_error("error2");
	}
}

Vehicle& VehicleList::highest_transport_tax(VehicleList& t, float s) {
	const int n = t.size();
	int max = 0;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		if (max < t[i].transport_tax(s)) {
			max = t[i].transport_tax(s);
			index = i;
		}
	}
	return t[index];
}

int VehicleList::size() const {
	return _size;
}

VehicleType Vehicle::get_type() {
	return _type;
}

Model Vehicle::get_model() {
	return _model;
}

float Vehicle::get_volume_of_engine() {
	return _volume_of_engine;
}

float Vehicle::get_tonnage() {
	return _tonnage;
}

void Vehicle::set_type(VehicleType _type) {
	this->_type = _type;
}

void Vehicle::set_model(Model _model) {
	this->_model = _model;
}

void Vehicle::set_volume_of_engine(float _volume_of_engine) {
	this->_volume_of_engine = _volume_of_engine;
}

void Vehicle::set_tonnage(float _tonnage) {
	this->_tonnage = _tonnage;
}

VehicleList::VehicleList(): _vehicle(nullptr), _size(0) {}
VehicleList::VehicleList(const VehicleList& other) {
	this->_size = other.size();
	_vehicle = new Vehicle*[_size];
	for (size_t i = 0; i < _size; ++i) {
		this->_vehicle[i] = new Vehicle(other[i].get_type(), other[i].get_model(), other[i].get_volume_of_engine(), other[i].get_tonnage());
	}
}
VehicleList::~VehicleList() {
	for (int i = 0; i < _size; ++i) {
		delete _vehicle[i];
	}
	delete[] _vehicle;
}



void VehicleList::swap(VehicleList& rhs) noexcept {
	std::swap(_vehicle, rhs._vehicle);
	std::swap(_size, rhs._size);
}

Vehicle& VehicleList::operator[](int index) {
	if (index >= _size || index < 0) {
		throw runtime_error("error1");
	}
	return *_vehicle[index];
}

Vehicle VehicleList::operator[](int index) const {
	if (index >= _size || index < 0) {
		throw runtime_error("error1");
	}
	return *_vehicle[index];
}

VehicleList& VehicleList::operator=(const VehicleList& other) {
	VehicleList tmp(other);
	tmp.swap(*this);
	return *this;
}