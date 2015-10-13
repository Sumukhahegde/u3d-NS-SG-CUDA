//Updates v Equation Coefficients


#include<stdio.h>
#include<algorithm>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void vEqnCoeff()
{

	stepSize();

	//Convective Fluxes
	if(u[i][j+1][k][l] + u[i][j][k][l]==0)	Fned=0;
	else Fned = rho * 2 * u[i][j+1][k][l]   * u[i][j][k][l]    / (u[i][j+1][k][l]   + u[i][j][k][l]  ) *dy*dz; //harmonic mean of ue and uNe

	if(u[i-1][j+1][k][l] + u[i-1][j][k][l]==0)	Fnw=0;
	else	Fnw  = rho * 2 * u[i-1][j+1][k][l] * u[i-1][j][k][l]  / (u[i-1][j+1][k][l] + u[i-1][j][k][l]) *dy*dz; //harmonic mean of uw and uNw

	if(v[i][j+1][k][l] + v[i][j][k][l]==0)	FN=0;
	else	FN   = rho * 2 * v[i][j+1][k][l]   * v[i][j][k][l]    / (v[i][j+1][k][l]   + v[i][j][k][l]  ) *dx*dz; //harmonic mean of vn and vnn

	if(v[i][j-1][k][l] + v[i][j][k][l]==0)	FPd=0;
	else	FPd  = rho * 2 * v[i][j-1][k][l]   * v[i][j][k][l]    / (v[i][j-1][k][l]   + v[i][j][k][l]  ) *dx*dz; //harmonic mean of vn and vs

	if(w[i][j+1][k][l] + w[i][j][k][l]==0)	Fnt=0;
	else	Fnt  = rho * 2 * w[i][j+1][k][l]   * w[i][j][k][l]    / (w[i][j+1][k][l]   + w[i][j][k][l]  ) *dx*dy; //harmonic mean of wt and wNt

	if(w[i][j+1][k-1][l] + w[i][j][k-1][l]==0)	Fnb=0;
	else	Fnb  = rho * 2 * w[i][j+1][k-1][l] * w[i][j][k-1][l]  / (w[i][j+1][k-1][l] + w[i][j][k-1][l]) *dx*dy; //harmonic mean of wb and wNb

	//constant
	bb = mu*(u[i][j+1][k][l]-u[i][j][k][l])*dz - mu*(u[i-1][j+1][k][l]-u[i-1][j][k][l])*dz + mu*(w[i][j+1][k][l]-w[i][j][k][l])*dx - mu*(w[i][j+1][k-1][l]-w[i][j][k-1][l])*dx + rho*yGrav*dx*dy*dz + rho*v[i][j][k][l-1]*dx*dy*dz/dt;  //rho at n

	//Diffusion Fluxes
	Dned=     mu * dy * dz/dx; //mu at ne
	Dnw =     mu * dy * dz/dx; //mu at nw
	DN  = 2 * mu * dx * dz/dy; //mu at N
	DPd = 2 * mu * dx * dz/dy; //mu at P
	Dnt =     mu * dx * dy/dz; //mu at nt
	Dnb =     mu * dx * dy/dz; //mu at nb


	//Coeff of the Equation
	anE = Dned- Fned/ 2;
	anW = Dnw + Fnw / 2;
	ann = DN  + std::max(-FN,0.0);  //upwind Scheme
	as  = DPd + std::max(FPd,0.0);  //upwind Scheme
	anT = Dnt - Fnt / 2;
	anB = Dnb + Fnb / 2;
	an  = anE + anW + ann + as + anT + anB + (Fned - Fnw + Fnt - Fnb + rho*dx*dy*dz/dt); //rho at n

	An = dx*dz/an;
	BB = bb/an;


}

