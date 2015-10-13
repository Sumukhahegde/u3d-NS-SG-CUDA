//Updates u Equation Coefficients


#include<stdio.h>
#include<algorithm>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/sourceCode/control/solverControls/stepSize.c"

void uEqnCoeff()
{

	stepSize();
	
	//Convective Fluxes
	if(w[i][j][k][l] + w[i+1][j][k][l]==0)	Fte=0; 	
	else 	Fte = rho * 2 * w[i][j][k][l]   * w[i+1][j][k][l]   *dx*dy / (w[i][j][k][l]   +   w[i+1][j][k][l]);   //harmonic mean of wt and wtE

	if(w[i][j][k-1][l] + w[i+1][j][k-1][l]==0)	Fbe=0;	
	else	Fbe = rho * 2 * w[i][j][k-1][l] * w[i+1][j][k-1][l] *dx*dy / (w[i][j][k-1][l] +   w[i+1][j][k-1][l]); //harmonic mean of wb and wbE

	if(u[i][j][k][l] + u[i+1][j][k][l]==0)	FE=0;
	else	FE  = rho * 2 * u[i][j][k][l]   * u[i+1][j][k][l]   *dy*dz / (u[i][j][k][l]   +   u[i+1][j][k][l]);   //harmonic mean of ue and uee

	if(u[i][j][k][l] + u[i-1][j][k][l]==0)	FP=0;
	else	FP  = rho * 2 * u[i][j][k][l]   * u[i-1][j][k][l]   *dy*dz / (u[i][j][k][l]   +   u[i-1][j][k][l]);   //harmonic mean of ue and uw

	if(v[i][j][k][l] + v[i+1][j][k][l]==0)	Fne=0;
	else	Fne = rho * 2 * v[i][j][k][l]   * v[i+1][j][k][l]   *dx*dz / (v[i][j][k][l]   +   v[i+1][j][k][l]);   //harmonic mean of vn and vnE

	if(v[i][j-1][k][l] + v[i+1][j-1][k][l]==0)	Fse=0;
	else	Fse = rho * 2 * v[i][j-1][k][l] * v[i+1][j-1][k][l] *dx*dz / (v[i][j-1][k][l] +   v[i+1][j-1][k][l]); //harmonic mean of vs and vsE
	
	

	//constant 
 	b = mu*(v[i+1][j][k][l]-v[i][j][k][l])*dz - mu*(v[i+1][j-1][k][l]-v[i][j-1][k][l])*dz + mu*(w[i+1][j][k][l]-w[i][j][k][l])*dy - mu*(w[i+1][j][k-1][l]-w[i][j][k-1][l])*dy + rho*xGrav*dx*dy*dz + rho*u[i][j][k][l-1]*dx*dy*dz/dt; //rho at e



	if(dx==0)	printf("ERROR dx=0");
	if(dy==0)	printf("ERROR dy=0");
	if(dz==0)	printf("ERROR dz=0");
	if(dt==0)	printf("ERROR dt=0");
	

	//Diffusion Fluxes
	DE  = 2 * mu * dy * dz / dx; //mu at E
	DP  = 2 * mu * dy * dz / dx; //mu at P
	Dne =     mu * dx * dz / dy; //mu at ne
	Dse =     mu * dx * dz / dy; //mu at se
	Dte =     mu * dx * dy / dz; //mu at te
	Dbe =     mu * dx * dy / dz; //mu at be


	//Coeff of the Equation
	aee = std::max(-FE,0.0) + DE;  //upwind Scheme
	aw  = std::max(FP,0.0)  + DP;  //upwind Scheme
	aNe = Dne - Fne/2;
	aSe = Dse + Fse/2;
	aTe = Dte - Fte/2;
	aBe = Dbe + Fbe/2;
	ae  = aee + aw + aNe + aSe + aTe + aBe + (Fne - Fse + Fte - Fbe + rho*dx*dy*dz/dt); //rho at e

	Ae = dy*dz/ae;
	B  = b / ae; 

	


}
