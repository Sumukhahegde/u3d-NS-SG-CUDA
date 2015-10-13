//Declaration of all variables


#ifndef VARIABLES_H
#define VARIABLES_H



	//INPUT OUTPUT VARIABLES
	double xDomainLength,yDomainLength,zDomainLength;
	int   xNumberOfCells,yNumberOfCells,zNumberOfCells,nx,ny,nz,n;   //number of cells
	int   nTimeSteps;
	double startTime,endTime,deltaT,simulationTime,realTime,start,stop;
	char  adjustTimeStep;
	char  topBoundary,bottomBoundary,leftBoundary,rightBoundary,frontBoundary,backBoundary;
	double uTopWallVel,uBottomWallVel,uLeftWallVel,uRightWallVel,uFrontWallVel,uBackWallVel;
	double vTopWallVel,vBottomWallVel,vLeftWallVel,vRightWallVel,vFrontWallVel,vBackWallVel;
	double wTopWallVel,wBottomWallVel,wLeftWallVel,wRightWallVel,wFrontWallVel,wBackWallVel;


	//COEFFICIENTS OF VELOCITY EQUATION
	double dx,dy,dz,dt;
	double b,bb,bbb;
	double xGrav,yGrav,zGrav;

	double Fte,Fbe,FE,FP,Fne,Fse;
	double Fned,Fnw,FN,FPd,Fnt,Fnb;
	double Fted,Ftw,Fntd,Fst,FT,FPdd;

	double DE,DP,Dne,Dse,Dte,Dbe;
	double Dned,Dnw,DN,DPd,Dnt,Dnb;
	double DT,DPdd,Dted,Dtw,Dntd,Dst;

	double aee,aw,aNe,aSe,aTe,aBe,ae;
	double anE,anW,ann,as,anT,anB,an;
	double att,ab,atE,atW,aNt,aSt,at;

	double Ae,An,At,Aw,As,Ab;
	double B,BB,BBB;
	

	//COEFFICIENTS OF PRESSURE CORRECTION EQUATION
	double aE,aW,aN,aS,aT,aB,aP;
	double Sm,Sc,maxMassResidual;


	//VELOCITIES and PRESSURE
	double ****u,****v,****w;
	double ****finalU,****finalV,****finalW;
	double ****p,****pCorr;
	double ***xCoord,***yCoord,***zCoord; 	

	double uMax,vMax,wMax;										//max velocities
	double maxCourantNumber;									//max courant number 
		
	int i,j,k,l,t,thomasI,simpleVar,nonLinear;         		//indices
	float *lower,*upper,*middle,*c;		   	//MATRIX A,X AND B
	
	double uRelaxCoeff;                               	// under relaxation coefficient for pressure

	double rho,mu; 						//density and viscosity


	FILE *fp; 						//file pointer
	char f0,f1,f2,f3,f4,f5,f6,f7;
	char str[100],check;
	double accuracy;


	//CUDA GPU variables
	float *d_lower,*d_upper,*d_middle,*d_c;
	size_t size;


	


#endif

