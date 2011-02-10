
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
private:
	int			m_ID;
	CargoType	m_CargoA;
	CargoType	m_CargoB;
	char		m_Name[32];			// Name of the Car Type
	float		m_MaxSpeed;			// Maximum speed for the train
	float		m_TractiveForce;	// The tractive force the train exerts
	int			m_MaxCargoA;		// The maximum cargo for Cargo Type A
	int			m_MaxCargoB;		// The maximum cargo for Cargo Type B
	int			m_Cost;				// Cost of the car
	int			m_Mass;				// Empty weight of the car
	RailType	m_RailType;
	//Sprite		CarSpriteSet;
public:
	CargoType GetCargoA() { return m_CargoA; }
	CargoType GetCargoB() { return m_CargoB; }
};

#endif