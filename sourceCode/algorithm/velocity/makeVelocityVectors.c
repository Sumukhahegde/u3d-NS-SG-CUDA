//Interpolation of the velocity vectors back from staggerd cell centers to the pressure cell centers


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void makeVelocityVectors()
{

	for  (k=2; k<=nz+1; k++)
	 for (i=2; i<=nx+1; i++)
	  for(j=2; j<=ny+1; j++)
	{
	finalU[i][j][k][l] = (u[i][j][k][l] + u[i-1][j][k][l])/2;
	finalV[i][j][k][l] = (v[i][j][k][l] + v[i][j-1][k][l])/2;
	finalW[i][j][k][l] = (w[i][j][k][l] + w[i][j][k-1][l])/2;	

	}
}
