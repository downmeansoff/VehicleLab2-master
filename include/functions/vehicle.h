#pragma once
#include <iostream>
#include <string>
using namespace std;

	enum VehicleType {
		CAR,
		TRUCK,
		MOTOCYCLE
	};
	enum Model {
		FORD,
		BMW,
		HONDA,
		TOYOTA
	};

	class Vehicle {
	private:
		VehicleType _type;
		Model _model;
		float _volume_of_engine;
		float _tonnage;
	public:
		Vehicle(); //DEFAULT
		Vehicle(VehicleType type, Model model, float volume_of_engine, float tonnage);
		float transport_tax(float s);

		//sets and gets
		void set_type(VehicleType _type);
		void set_model(Model _model);
		void set_volume_of_engine(float _volume_of_engine);
		void set_tonnage(float _tonnage);

		VehicleType get_type();
		Model get_model();
		float get_volume_of_engine();
		float get_tonnage();
	};

	class VehicleList {
	private:
		Vehicle** _vehicle;
		int _size;

	public:
		VehicleList();
		VehicleList(const VehicleList& other);
		~VehicleList();

		Vehicle& operator[](int index);
		Vehicle operator[](int index) const;
		VehicleList& operator=(const VehicleList& other);

