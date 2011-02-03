
#ifndef TRAINCARS_H
#define TRAINCARS_H

enum CargoType
{
	None,
	Unknown,
	EngineWater,
	EngineCoal,
	EngineGasoline,
	Caboose,
	Pax,
	Mail,
	Coal,
	Iron,
	Steel
};

enum RailType
{
	Normal		=	1,
	Electric	=	2,
	HighSpeed	=	4,
	SlowSpeed	=	8
};


class TrainCarType
{
	int			ID;
	CargoType	CargoA;
	CargoType	CargoB;
	char		Name[32];				// Name of the Car Type
	float		MaxSpeed;			// Maximum speed for the train
	float		TractiveForce;		// The tractive force the train exerts
	int			MaxCargoA;			// The maximum cargo for Cargo Type A
	int			MaxCargoB;			// The maximum cargo for Cargo Type B
	int			Cost;				// Cost of the car
	int			Mass;				// Empty weight of the car
	RailType	RailType;
	//Sprite		CarSpriteSet;
};

#endif