//Inputs the default value that is required for simulation 


#include<stdio.h>
#include "variables.H"
#include "dynamicAllocate.c"

void defaultInput()
{

		xDomainLength=0.1;
		yDomainLength=0.1;
		zDomainLength=0.1;

		xNumberOfCells=20;
		yNumberOfCells=20;
		zNumberOfCells=20;

		startTime=0;
	
		endTime=0.01;

		nTimeSteps=20000;

		accuracy=1e-30;

		rho=1000;
		mu=10;
	
		uTopWallVel=0;
		vTopWallVel=0;
		wTopWallVel=0;
	
		uBottomWallVel=0;
		vBottomWallVel=0;
		wBottomWallVel=0;	

		uLeftWallVel=0;
		vLeftWallVel=0;
		wLeftWallVel=0;

		uRightWallVel=0;
		vRightWallVel=0;
		wRightWallVel=0;

		uFrontWallVel=0;
		vFrontWallVel=0;
		wFrontWallVel=0;

		uBackWallVel=1;
		vBackWallVel=0;
		wBackWallVel=0;

		uRelaxCoeff=0.8;

		xGrav=0;
		yGrav=0;
		zGrav=0;

	
			
}
                                                                 

