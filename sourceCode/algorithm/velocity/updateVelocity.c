//Updates the values of the velocity


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void updateVelocity()
{

	//updates u velocity
	for  (k=2; k<=nz+1; k++)
	 for (i=2; i<=nx;   i++)
	  for(j=2; j<=ny+1; j++)
	{
	  uEqnCoeff();  //updates the value of Ae
	  	
	  u[i][j][k][l] = u[i][j][k][l] + Ae * (pCorr[i][j][k][l] - pCorr[i+1][j][k][l]);
	}


	//updates v velocity
	for  (i=2; i<=nx+1; i++)
	 for (j=2; j<=ny;   j++)
	  for(k=2; k<=nz+1; k++)
	{
	  vEqnCoeff();  //updates the value of An
	
	  v[i][j][k][l] = v[i][j][k][l] + An * (pCorr[i][j][k][l] - pCorr[i][j+1][k][l]);
	}


	//updates w velocity
	for  (j=2; j<=ny+1; j++)
	 for (k=2; k<=nz;   k++)
	  for(i=2; i<=nx+1; i++)
	{
	  wEqnCoeff();  //updates the value of At

	  w[i][j][k][l] = w[i][j][k][l] + At * (pCorr[i][j][k][l] - pCorr[i][j][k+1][l]);
	}
	

}
	
