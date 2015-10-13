//calculates the max courant number


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"


void courantNumber()
{

	for  (k=2; k<=nz+1; k++)
	 for (j=2; j<=ny+1; j++)
	  for(i=2; i<=nx+1; i++)
	{
		if(finalU[i][j][k][l]>uMax)	uMax=finalU[i][j][k][l];
		if(finalV[i][j][k][l]>vMax)	vMax=finalV[i][j][k][l];			//finding out max velocity
		if(finalW[i][j][k][l]>wMax)	wMax=finalW[i][j][k][l];
	}

	maxCourantNumber = (uMax/dx + vMax/dy + wMax/dz)*dt;

	printf("Max courant number: %e\n",maxCourantNumber);

	
}
