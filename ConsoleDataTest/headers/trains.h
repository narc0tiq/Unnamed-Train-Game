

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
		
		TrainCar(TrainCarType* Car_Type);
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
				Train(void);
				~Train(void);
	bool		AddTrainCar();			// Adds to the end
	TrainCar*	GetTrainCar(int pos);


	// TODO: Define these functions
	bool		AddTrainCar(int pos);	// Add a car at a position
	bool		SwapTrainCar(int pos);	// Swaps a train car with the one after it - False on Fail
	bool		RemoveTrainCar(int pos);// Removes a train car
	void		MergeTrain(Train* Trn);	// Merges two Trains
	Train*		SplitTrain(int pos);	// Splits a train at a car
	void		CalcTrain();			// Recalculates the trains maxspeed, weight, Tractive Force, and Rail Types

	// TODO: Define get/set
	float		GetSpeed();
	float		GetMaxSpeed();
	float		GetTractiveForce();
	int			GetDest();
	float		GetX();
	float		GetY();
	char		GetDirection();
	RailType	GetRailType();
	bool		IsBrokenDown();

	void		SetSpeed(float);
	bool		SetDest(int);
	void		SetDirection(char);
	void		SetBrokenDown(bool);
};