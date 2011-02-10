

#include "trainCars.h"
#include "contracts.h"


class TrainCar
{
	friend class Train;
	
private:
	TrainCar*		m_NextCar;
	int				m_CargoVolumeA;
	int				m_CargoVolumeB;
	TrainCarType*	m_CarType;
	contract*		m_Contract;

public:
	TrainCar(TrainCarType* Car_Type);

	void	SetCargoVolumeA(int A);
	void	SetCargoVolumeB(int B);
	void	SetContract(contract* C);
	void	GetCarType(TrainCarType* T);

	int		GetCargoVolumeA();
	int		GetCargoVolumeB();
	contract*	GetContract();
	TrainCarType*	GetCarType();
};

class Train
{
private:
	float		m_MaxSpeed;			// Maximum speed for the train
	float		m_TractiveForce;		// the tractive force the train exerts
	int			m_Dest;				// destination
	float		m_X;
	float		m_Y;
	char		m_Direction;			// 1-North 2-North/East 3-East ...
	RailType	m_RailType;
	bool		m_BrokenDown;
	float		m_Speed;
	TrainCar*	m_RootCar;
	
public:
				Train(void);
				~Train(void);
	//bool		AddTrainCar();			
	bool		AddTrainCar(TrainCar*);	// Adds to the end
	TrainCar*	GetTrainCar(int pos);

/*
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
*/
};