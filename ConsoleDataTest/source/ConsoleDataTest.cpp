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

	NewTrain->AddTrainCar(a);
	printf("Added Car A\n");



	printf("this is a test\n");
	getchar();
	return 0;
}

