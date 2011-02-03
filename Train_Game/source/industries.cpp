// Variadic Function.cpp : main project file.

#include <iostream>
#include "trainCars.h"



class company_industry;



class company_player
{
	std::string		Name;

	
	
};

class industryPlayerRating
{
	industryPlayerRating*	NextPlayer;
	company_player*			Player;
	float	Rating;
};

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

class contract
{
	industry*	Sending;	// Sending industry
	industry*	Recieving;	// Recieving industry
	int			Rate;		// Resorces needed per month
	int			Remaining;	// Quantity remaining (not recieved)
	int			Expires;	// Expirey date in game time
	bool		Renew;		// Wether the contract can be renewed
	company_player*	Player;	// Player owning the contract, Null for nobody

	contract()
	{
		Sending = NULL;
		Recieving = NULL;
		Rate = 0;
		Remaining = -1;
		Expires = 0;
		Renew = false;
		Player = NULL;
	}

	//person(std::string N, int A) : name(N), age(A) {}
	contract(industry* sending,industry* recieving, int rate, int remaining, int expires, bool renew)
	{
		Sending = sending;
		Recieving = recieving;
		Rate = rate;
		Remaining = remaining;
		Expires = expires;
		Renew = renew;
		Player = NULL;
	}

	void SetPlayer(company_player*	player)	{ Player = player; }
	void SetRate(int rate) { Rate = rate; }
	void SetRemaining(int remaining) { Remaining = remaining; }
	void SetExpires(int expires ) { Expires = expires; }
	void SetRenewable(bool renew) { Renew = renew; }

	company_player* GetPlayer(void) { return Player; }
	industry*	GetSending(void)	{ return Sending; }
	industry*	GetRecieving(void)	{ return Recieving; }
	int			GetRate(void)		{ return Rate; }
	int			GetRemaining(void)	{ return Remaining; }
	int			GetExpires(void)	{ return Expires; }
	bool		GetRenew(void)		{ return Renew; }

};

