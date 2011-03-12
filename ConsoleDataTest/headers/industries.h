#ifndef INDUSTRIES_H
#define INDUSTRIES_H

#include <iostream>
#include "trainCars.h"

class company_industry;


class industry
{
public:
	//industryPlayerRating*	RootPlayerRating;
	int			CargoProducedSize;	// The number of cargos produced
	int			CargoRequiredSize;	// The number of cargos required
	CargoType*	CargoProduced;		// Pointer to array of Cargo
	CargoType*	CargoRequired;
	
public:
	// constructor
	industry();
	~industry();
	bool AddCargoProduced(CargoType Cargo);
	bool AddCargoRecieved(CargoType Cargo);
	
private:
	CargoType* AddCargo(CargoType* oldCargo, int* CargoSize, CargoType Cargo);
};

#endif