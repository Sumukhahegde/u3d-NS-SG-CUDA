//Gives initial values to all the variables and fields at time 0


#include<stdio.h>
#include "variables.H"

void zeroTimeValues()
{

	//INPUT OUTPUT VARIABLES
	
	nx = ny = nz = n = 0;
	deltaT = simulationTime = 0;
	adjustTimeStep = 0;
	topBoundary = bottomBoundary = leftBoundary = rightBoundary = frontBoundary = backBoundary = 0;
	

	//COEFFICIENTS OF VELOCITY EQUATION
	dx = dy = dz = dt = 0;
	b = bb = bbb = 0;
	
	Fte = Fbe = FE = FP = Fne = Fse = 0;
	Fned = Fnw = FN = FPd = Fnt = Fnb = 0;
	Fted = Ftw = Fntd = Fst = FT = FPdd = 0;

	DE = DP = Dne = Dse = Dte = Dbe = 0;
	Dned = Dnw = DN = DPd = Dnt = Dnb = 0;
	DT = DPdd = Dted = Dtw = Dntd = Dst = 0;

	aee = aw = aNe = aSe = aTe = aBe = ae = 0;
	anE = anW = ann = as = anT = anB = an = 0;
	att = ab = atE = atW = aNt = aSt = at = 0;

	Ae = An = At = Aw = As = Ab = 0;
	B = BB = BBB = 0;
	

	//COEFFICIENTS OF PRESSURE CORRECTION EQUATION
	aE = aW = aN = aS = aT = aB = aP = 0;
	Sc = 0;
	Sm = 100;
	maxMassResidual=100;
	
	
        
	//VELOCITIES and PRESSURE
	for   (l=0; l<2; l++)
	 for  (k=0; k<(zNumberOfCells+5); k++)
	  for (j=0; j<(yNumberOfCells+5); j++)
	   for(i=0; i<(xNumberOfCells+5); i++)
	{
		u[i][j][k][l]	  = 0;
		v[i][j][k][l]	  = 0;
		w[i][j][k][l] 	  = 0; 
             	      	
		finalU[i][j][k][l]	  = 0;
		finalV[i][j][k][l]	  = 0;
		finalW[i][j][k][l] 	  = 0; 

		p[i][j][k][l]     = 0;
		pCorr[i][j][k][l] = 0;
		
		xCoord[i][j][k] = 0;
		yCoord[i][j][k] = 0;
		zCoord[i][j][k] = 0;			
	}


		

	i = j = k = l = t = thomasI = simpleVar = nonLinear = 0;   //indices
	
	nx = ny = nz = n = 0;                                  //Number of Cells

	uMax = vMax = wMax = maxCourantNumber = 0;

	check = f0 = f1 = f2 = f3 = f4 = f5 = f6 = f7 = 0;

	
}

