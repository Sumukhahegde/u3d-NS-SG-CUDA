//Calculation of the spacial and temporal step sizes 


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void stepSize()
{

	if(xNumberOfCells==0)	printf("Error at stepSize.C, no of cells along x is zero");
	if(yNumberOfCells==0)	printf("Error at stepSize.C, no of cells along y is zero");
	if(zNumberOfCells==0)	printf("Error at stepSize.C, no of cells along z is zero");
	if(nTimeSteps==0)	printf("Error at stepSize.C, no of time steps is zero");

	dx = xDomainLength/xNumberOfCells;
	dy = yDomainLength/yNumberOfCells;
	dz = zDomainLength/zNumberOfCells; 
	deltaT=(endTime-startTime)/nTimeSteps;  //initial time step
	
	dt=deltaT;
	//if((std::min(deltaT,maxCourantNumber*std::max((std::max(dx,dy)),dz))>0)&&(maxCourantNumber>0.001))	  dt = 0.001*std::min(deltaT,maxCourantNumber*std::max((std::max(dx,dy)),dz));
	//else	dt=deltaT;	
	

	nx=xNumberOfCells;
	ny=yNumberOfCells;
	nz=zNumberOfCells;

}
