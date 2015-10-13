//Updates the values of the pressure


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void updatePressure()
{
	
	for  (k=2; k<=nz+1; k++)
	 for (j=2; j<=ny+1; j++)
	  for(i=2; i<=nx+1; i++)
	p[i][j][k][l]=p[i][j][k][l]+uRelaxCoeff*pCorr[i][j][k][l];

}
	
