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

class contract
{
	contract*	m_NextContract;	// Link List
	industry*	m_Sending;	// Sending industry
	industry*	m_Recieving;	// Recieving industry
	int			m_Rate;		// Resorces needed per month
	int			m_Remaining;	// Quantity remaining (not recieved)
	int			m_Expires;	// Expirey date in game time
	bool		m_Renew;		// Wether the contract can be renewed

	contract()
	{
		m_Sending = NULL;
		m_Recieving = NULL;
		m_Rate = 0;
		m_Remaining = -1;
		m_Expires = 0;
		m_Renew = false;
	}

	//person(std::string N, int A) : name(N), age(A) {}
	contract(industry* sending,industry* recieving, int rate, int remaining, int expires, bool renew)
	{
		m_Sending = sending;
		m_Recieving = recieving;
		m_Rate = rate;
		m_Remaining = remaining;
		m_Expires = expires;
		m_Renew = renew;
	}

	void SetRate(int rate) { m_Rate = rate; }
	void SetRemaining(int remaining) { m_Remaining = remaining; }
	void SetExpires(int expires ) { m_Expires = expires; }
	void SetRenewable(bool renew) { m_Renew = renew; }

	industry*	GetSending(void)	{ return m_Sending; }
	industry*	GetRecieving(void)	{ return m_Recieving; }
	int			GetRate(void)		{ return m_Rate; }
	int			GetRemaining(void)	{ return m_Remaining; }
	int			GetExpires(void)	{ return m_Expires; }
	bool		GetRenew(void)		{ return m_Renew; }

};

class AvailableContracts
{
	contract*		RootContract;	// Contract List
};

class company_player
{
	bool			m_Human;
	std::string		m_Name;			// Company 
	int				m_StartDate;
	int				m_Money;		// Money dosent include loan
	int				m_Loan;			// Current loan
	int				m_CValue;		// Company Value
	contract*		RootContract;	// Contract List
};

class industryPlayerRating
{
	industryPlayerRating*	NextPlayer;
	company_player*			Player;
	float	Rating;
};