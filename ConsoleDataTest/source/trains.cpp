/*
	This is the class for the trains and all of their cars

	I will break out the header file later

*/

#include <iostream>
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
	int				m_Age;				// Age of the car (built year/month)

public:
	TrainCar(TrainCarType* Car_Type)
	{
		m_NextCar		= NULL;	// Floating pointer is bad!
		m_CargoVolumeA	= 0;
		m_CargoVolumeB	= 0;
		m_CarType		= Car_Type;
	}
	void	SetCargoVolumeA(int A) { m_CargoVolumeA = A; }
	void	SetCargoVolumeB(int B) { m_CargoVolumeB = B; }
	void	SetContract(contract* C) { m_Contract = C; }
	void	GetCarType(TrainCarType* T) { m_CarType = T; }

	int		GetCargoVolumeA() { return m_CargoVolumeA; }
	int		GetCargoVolumeB() { return m_CargoVolumeB; }
	contract*	GetContract() { return m_Contract; }
	TrainCarType*	GetCarType() { return m_CarType; }

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
	Train(void)
	{
		m_RootCar = NULL;
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
	bool AddTrainCar(TrainCar* NewCar)
	{
		TrainCar*	temp	= m_RootCar;			// Temparary pointer

		if (temp == NULL)
		{
			m_RootCar = NewCar;
		}
		else
		{
			while (temp->m_NextCar != NULL)
			{
				if (temp->m_NextCar == NewCar) return false;
				temp = temp->m_NextCar;	// Find last node
			}
			temp->m_NextCar = NewCar;
		}
		return true;
	}
	
	/*
		Get the data from a car in the form of a pointer
		if pos does not exist return NULL
	*/
	TrainCar* GetTrainCar(int pos)
	{
		int c = 0;
		TrainCar* temp	= m_RootCar;
		if (m_RootCar == NULL) return NULL;
		
		while (temp->m_NextCar != NULL)
		{
			if (c == pos) return temp;
			c++;
			temp = temp->m_NextCar;
		}
		if (c == pos) return temp;
		return NULL;
	}
};


void test()
{
	
	Train* NewTrain = new Train();
	printf("New Train\n");
	
	TrainCar* a = new TrainCar(NULL);
	TrainCar* b = new TrainCar(NULL);
	TrainCar* c = new TrainCar(NULL);
	
	a->SetCargoVolumeA(10);
	b->SetCargoVolumeA(20);
	c->SetCargoVolumeA(30);

	NewTrain->AddTrainCar(a);

}