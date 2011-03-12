// ConsoleDataTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "trains.h"
#include "companies.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	Train* NewTrain = new Train();

	printf("New Train\n");
	
	TrainCar* a = new TrainCar(NULL);
	TrainCar* b = new TrainCar(NULL);
	TrainCar* c = new TrainCar(NULL);
	
	a->SetCargoVolumeA(10);
	b->SetCargoVolumeA(20);
	c->SetCargoVolumeA(30);
	printf("3 New Cars\n");
	printf("\n");

	NewTrain->AddTrainCar(a);
	printf("Added Car A\n");
	for (int i = 0; TrainCar* temp = NewTrain->GetTrainCar(i) ; i++ )
	{
		printf("Cargo in car #%i: %i\n" , i,temp->GetCargoVolumeA());
	}
	printf("\n");
	
	NewTrain->AddTrainCar(b);
	printf("Added Car B\n");
	for (int i = 0; TrainCar* temp = NewTrain->GetTrainCar(i) ; i++ )
	{
		printf("Cargo in car #%i: %i\n" , i,temp->GetCargoVolumeA());
	}
	printf("\n");
	
	NewTrain->AddTrainCar(c);
	printf("Added Car C\n");
	for (int i = 0; TrainCar* temp = NewTrain->GetTrainCar(i) ; i++ )
	{
		printf("Cargo in car #%i: %i\n" , i,temp->GetCargoVolumeA());
	}
	

	
	printf("\nEnd of Line\n");
	getchar();
	return 0;
}

