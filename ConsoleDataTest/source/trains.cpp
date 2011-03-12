/*
	This is the class for the trains and all of their cars

*/

#include "trains.h"
/*	
	Default constructor for a Train Car
*/
TrainCar::TrainCar(TrainCarType* Car_Type)
{
	m_NextCar		= NULL;	// Floating pointer is bad!
	m_CargoVolumeA	= 0;
	m_CargoVolumeB	= 0;
	m_CarType		= Car_Type;
}

void	TrainCar::SetCargoVolumeA(int A) { m_CargoVolumeA = A; }
void	TrainCar::SetCargoVolumeB(int B) { m_CargoVolumeB = B; }
void	TrainCar::SetContract(contract* C) { m_Contract = C; }
void	TrainCar::GetCarType(TrainCarType* T) { m_CarType = T; }

int		TrainCar::GetCargoVolumeA() { return m_CargoVolumeA; }
int		TrainCar::GetCargoVolumeB() { return m_CargoVolumeB; }
contract*	TrainCar::GetContract() { return m_Contract; }
TrainCarType*	TrainCar::GetCarType() { return m_CarType; }



Train::Train(void)
{
	m_RootCar = NULL;
}
Train::~Train(void)
{
	// Destroy train data here
}
	
/*
	Add a Train car to the train
	0 index
	-1 for the end
	will return false on error
*/
bool Train::AddTrainCar(TrainCar* NewCar)
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
TrainCar* Train::GetTrainCar(int pos)
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

/*
bool Train::RemoveTrainCar(int pos)
{
	int c = 1;
	TrainCar* temp	= m_RootCar;
	if (m_RootCar == NULL) return false;
		
	while ((temp->m_NextCar != NULL) && (c == pos))
	{
		if (c == pos) break;
		c++;
		temp = temp->m_NextCar;
	}
	if (c != pos) return false;
		
	if ( temp->m_NextCar->m_NextCar == NULL )
	{
		delete temp->m_NextCar;
		temp->m_NextCar = NULL;
	}


	return true;
}

*/