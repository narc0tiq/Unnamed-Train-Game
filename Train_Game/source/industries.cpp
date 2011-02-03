// Variadic Function.cpp : main project file.

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
	industry()
	{
		CargoProducedSize = 0;
		CargoRequiredSize = 0;
		CargoRequired = NULL;
		CargoProduced = NULL;
	}
	
	~industry()
	{
		// destruct CargoProduced and CargoRequired if not null;
		if (CargoRequired != NULL) delete[] CargoRequired;
		if (CargoProduced != NULL) delete[] CargoProduced;
	}
	
	bool AddCargoProduced(CargoType Cargo)
	{
		CargoType* newCargo = AddCargo(CargoProduced, &CargoProducedSize, Cargo);
		if (newCargo == NULL) return false;
		
		if (CargoProduced != NULL) delete[] CargoProduced;		// Delete old data
		CargoProduced = newCargo;	// Replace with new pointer
		return true;
	}
	
	bool AddCargoRecieved(CargoType Cargo)
	{
		CargoType* newCargo = AddCargo(CargoRequired, &CargoRequiredSize, Cargo);
		if (newCargo == NULL) return false;
		
		if (CargoRequired != NULL) delete[] CargoRequired;		// Delete old data
		CargoRequired = newCargo;	// Replace with new pointer
		return true;
	}
	
private:
	/*
		Returns pointer for the cargo type
	*/
	CargoType* AddCargo(CargoType* oldCargo, int* CargoSize, CargoType Cargo)
	{
		int i = 0;	// counter

		CargoType* newCargo = new CargoType[(*CargoSize) + 1];
		
		if (newCargo == NULL) return NULL;		// Could not alocate memory
		
		// Copy old data to the new data over
		if (oldCargo != NULL)
			for (i = 0; i < *CargoSize; i ++)
				newCargo[i] = oldCargo[i];
		
		(*CargoSize)++;
		newCargo[i] = Cargo;	// Add new Cargo
		return newCargo;
	}
};



