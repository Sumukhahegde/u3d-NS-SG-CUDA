//SIMPLE algorithm loop


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"
#include "../velocity/u/uEqn.c"
#include "../velocity/v/vEqn.c"
#include "../velocity/w/wEqn.c"
#include "../pressure/pCorrEqn.c"
#include "../pressure/updatePressure.c"
#include "../velocity/updateVelocity.c"

void simple()
{


	printf("Starting SIMPLE loop\n");
	printf("Initial mass Residual: %e\n",maxMassResidual);

	

	for(simpleVar=0;simpleVar<2;simpleVar++)                                                       
 {

	maxMassResidual=0;  //making mass residual zero so that it enters this loop and max value of Sm is equated to that 

	for(nonLinear=0;nonLinear<3;nonLinear++)
	{
	  //calculate initial velocity
	  uEqn();	
	  vEqn();
	  wEqn();
	}


	for(nonLinear=0;nonLinear<3;nonLinear++)
	 pCorrEqn();            //calculate pressure correction
	

	updatePressure();  //update the pressure values
	updateVelocity();  //update the velocity values
	
	

 	//finding final updated max mass residual
	for  (k=2; k<=nz+1; k++)
	 for (j=2; j<=ny+1; j++)
	  for(i=2; i<=nx+1; i++)
	{
          Sm = (rho*u[i][j][k][l]-rho*u[i-1][j][k][l])*dy*dz + (rho*v[i][j][k][l]-rho*v[i][j-1][k][l])*dx*dz + (rho*w[i][j][k][l]-rho*w[i][j][k-1][l])*dx*dy; 	        
	  if((Sm>maxMassResidual)||(Sm<-maxMassResidual))		maxMassResidual = Sm;
	}
 

 }
	printf("Final Mass residual: %e\n",maxMassResidual);
	printf("No of SIMPLE loops: %d\n",simpleVar);
}

