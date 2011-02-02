/*
	This is the class for the trains and all of their cars

	I will break out the header file later

*/

#include <iostream>
#include "trainCars.h"

class Train
{

	private:
/*
Train Car data structure
*/
	struct TrainCar
	{
		TrainCar*		NextCar;
		int				CargoVolumeA;
		int				CargoVolumeB;
		TrainCarType*	CarType;
		
		TrainCar(TrainCarType* Car_Type)
		{
			NextCar			= NULL;	// Floating pointer is bad!
			CargoVolumeA	= 0;
			CargoVolumeB	= 0;
			CarType			= Car_Type;
		}
	};

public:
	float		MaxSpeed;			// Maximum speed for the train
	float		TractiveForce;		// the tractive force the train exerts
	int			Dest;				// destination
	float		X;
	float		Y;
	char		Direction;			// 1-North 2-North/East 3-East ...
	RailType	RailType;
	bool		BrokenDown;
	
private:
	float		Speed;
	TrainCar*	RootCar;
	
	
public:
	Train(void)
	{
		RootCar = NULL;
	}
	
	
	~Train(void)
	{
		// Destroy train data here
	}
	
	
	/*
		Add a Train car to the train
		0 index
		-1 for the end
		will return false on error
	*/
	bool AddTrainCar()
	{
		TrainCar*	temp	= NULL;			// Temparary pointer
		TrainCar*	newCar	= new TrainCar(NULL);
		
		temp = RootCar;
		if (temp == NULL)
		{
			RootCar = newCar;
		}
		else
		{
			while (temp->NextCar != NULL) temp = temp->NextCar;	// Find last node
			temp->NextCar = newCar;
		}
	}
	
	/*
		Get the data from a car in the form of a pointer
		if pos does not exist return NULL
	*/
	TrainCar* GetTrainCar(int pos)
	{
		int c = 0;
		TrainCar* temp	= RootCar;
		if (RootCar == NULL) return NULL;
		
		while (temp->NextCar != NULL)
		{
			if (c == pos) return temp;
			c++;
			temp = temp->NextCar;
		}
		if (c == pos) return temp;
		return NULL;
	}
};
