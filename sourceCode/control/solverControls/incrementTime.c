//Increments the time variables


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void incrementTime()
{

	simulationTime = simulationTime + dt;	//time increment

	t=t+1;			//output file name parameter	

}
