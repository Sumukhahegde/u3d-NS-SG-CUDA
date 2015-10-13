//Calculates the coefficients of the pressure correction equation


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void pCorrEqnCoeff()
{

		
	i=i-1; 
	uEqnCoeff();	//gives the value of Ae at (i-1) i.e Aw 
	Aw=Ae;		//hence equating Ae to Aw
	i=i+1;

	j=j-1; 
	vEqnCoeff();	//gives the value of An at (j-1) i.e As 
	As=An;		//hence equating An to As
	j=j+1;

	k=k-1; 
	wEqnCoeff();	//gives the value of At at (k-1) i.e Ab 
	Ab=At;		//hence equating At to Ab
	k=k+1;


	uEqnCoeff();    //updates the value of Ae
	vEqnCoeff();	//updates the value of An
	wEqnCoeff();	//updates the value of At


	aE = rho * Ae * dy*dz; //rho at e
	aW = rho * Aw * dy*dz; //rho at w
	aN = rho * An * dx*dz; //rho at n
	aS = rho * As * dx*dz; //rho at s
	aT = rho * At * dx*dy; //rho at t
	aB = rho * Ab * dx*dy; //rho at b
	aP = aE + aW + aN + aS + aT + aB;

	//residual mass
	Sm = (rho*u[i][j][k][l]-rho*u[i-1][j][k][l])*dy*dz + (rho*v[i][j][k][l]-rho*v[i][j-1][k][l])*dx*dz + (rho*w[i][j][k][l]-rho*w[i][j][k-1][l])*dx*dy;  // rho at respective places
	Sc=-Sm;
	
	

}
