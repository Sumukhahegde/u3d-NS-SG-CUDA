//Updates w Equation Coefficients


#include<stdio.h>
#include<algorithm>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void wEqnCoeff()
{

	stepSize();
	
	//Convective Fluxes
	if(u[i][j][k+1][l] + u[i][j][k][l]==0)	Fted=0;
	else	Fted = rho * 2 * u[i][j][k+1][l]   * u[i][j][k][l]   / (u[i][j][k+1][l]   + u[i][j][k][l]  ) *dy*dz; //harmonic mean of ue and uTe
	
	if(u[i-1][j][k+1][l] + u[i-1][j][k][l]==0)	Ftw=0;
	else	Ftw  = rho * 2 * u[i-1][j][k+1][l] * u[i-1][j][k][l] / (u[i-1][j][k+1][l] + u[i-1][j][k][l]) *dy*dz; //harmonic mean of uw and uTw

	if(v[i][j][k+1][l] + v[i][j][k][l]==0)	Fntd=0;
	else	Fntd = rho * 2 * v[i][j][k+1][l]   * v[i][j][k][l]   / (v[i][j][k+1][l]   + v[i][j][k][l]  ) *dx*dz; //harmonic mean of vn and vnT

	if(v[i][j-1][k+1][l] + v[i][j-1][k][l]==0)	Fst=0;
	else	Fst  = rho * 2 * v[i][j-1][k+1][l] * v[i][j-1][k][l] / (v[i][j-1][k+1][l] + v[i][j-1][k][l]) *dx*dz; //harmonic mean of vs and vsT

	if(w[i][j][k+1][l] + w[i][j][k][l]==0)	FT=0;
	else	FT   = rho * 2 * w[i][j][k+1][l]   * w[i][j][k][l]   / (w[i][j][k+1][l]   + w[i][j][k][l]  ) *dx*dy; //harmonic mean of wt and wtt

	if(w[i][j][k-1][l] + w[i][j][k][l]==0)	FPdd=0;
	else	FPdd = rho * 2 * w[i][j][k-1][l]   * w[i][j][k][l]   / (w[i][j][k-1][l]   + w[i][j][k][l]  ) *dx*dy; //harmonic mean of wt and wb

	
	//constant
	bbb = mu*(u[i][j][k+1][l]-u[i][j][k][l])*dy - mu*(u[i-1][j][k+1][l]-u[i-1][j][k][l])*dy + mu*(v[i][j][k+1][l]-v[i][j][k][l])*dx - mu*(v[i][j-1][k+1][l]-v[i][j-1][k][l])*dx + rho*zGrav*dx*dy*dz + rho*w[i][j][k][l-1]*dx*dy*dz/dt;  //rho at t


	//Diffusion Fluxes
	DT   = 2 * mu * dx*dy/dz; //mu at T
	DPdd = 2 * mu * dx*dy/dz; //mu at P
	Dted =     mu * dy*dz/dx; //mu at te
	Dtw  =     mu * dy*dz/dx; //mu at tw
	Dntd =     mu * dx*dz/dy; //mu at nt
	Dst  =     mu * dx*dz/dy; //mu at st

	//Coefficients of Equation	
	att = DT   + std::max(-FT,0.0);
	ab  = DPdd + std::max(FPdd,0.0);
	atE = Dted - Fted/2;
	atW = Dtw  + Ftw/2;
	aNt = Dntd - Fntd/2;
	aSt = Dst  + Fst/2;
	at  = att + ab + atE + atW + aNt + aSt + (Fted - Ftw + Fntd - Fst + rho*dx*dy*dz/dt); //rho at t

	At  = dx*dy/at;
	BBB = bbb / at;

}

		


	
	
	

