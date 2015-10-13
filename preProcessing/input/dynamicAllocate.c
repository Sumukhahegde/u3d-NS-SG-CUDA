//dynamically allocates the size of array 


#include<stdio.h>
#include<stdlib.h>	
#include "variables.H"


void dynamicAllocate()
{

   	u	 = new double***[xNumberOfCells+5];
	v	 = new double***[xNumberOfCells+5];
	w	 = new double***[xNumberOfCells+5];
	finalU	 = new double***[xNumberOfCells+5];
	finalV	 = new double***[xNumberOfCells+5];
	finalW	 = new double***[xNumberOfCells+5];
	p	 = new double***[xNumberOfCells+5];
	pCorr	 = new double***[xNumberOfCells+5];
	xCoord	 = new double**[xNumberOfCells+5];
	yCoord	 = new double**[xNumberOfCells+5];
	zCoord	 = new double**[xNumberOfCells+5];
 
	for (int i=0; i<(xNumberOfCells+5); ++i)
	{
	  u[i]		 = new double**[yNumberOfCells+5];
	  v[i]		 = new double**[yNumberOfCells+5];
	  w[i]		 = new double**[yNumberOfCells+5];
	  finalU[i]	 = new double**[yNumberOfCells+5];
	  finalV[i]	 = new double**[yNumberOfCells+5];
	  finalW[i]	 = new double**[yNumberOfCells+5];
	  p[i]		 = new double**[yNumberOfCells+5];
	  pCorr[i]	 = new double**[yNumberOfCells+5];
	  xCoord[i]	 = new double*[yNumberOfCells+5];
	  yCoord[i]	 = new double*[yNumberOfCells+5];
	  zCoord[i]	 = new double*[yNumberOfCells+5]; 

  	  for (int j=0; j<(yNumberOfCells+5); ++j)
	  {
		u[i][j]		 = new double*[zNumberOfCells+5];
		v[i][j]		 = new double*[zNumberOfCells+5];
		w[i][j]		 = new double*[zNumberOfCells+5];
	  	finalU[i][j]	 = new double*[zNumberOfCells+5];
	  	finalV[i][j]	 = new double*[zNumberOfCells+5];
	  	finalW[i][j]	 = new double*[zNumberOfCells+5];
	  	p[i][j]		 = new double*[zNumberOfCells+5];
	  	pCorr[i][j]	 = new double*[zNumberOfCells+5];
	  	xCoord[i][j]	 = new double[zNumberOfCells+5];
	  	yCoord[i][j]	 = new double[zNumberOfCells+5];
	  	zCoord[i][j]	 = new double[zNumberOfCells+5]; 

		 for (int k=0; k<(zNumberOfCells+5); ++k)
		 {
		  u[i][j][k] 		 = new double[2];
		  v[i][j][k]		 = new double[2];
	 	  w[i][j][k]		 = new double[2];
	  	  finalU[i][j][k]	 = new double[2];
	  	  finalV[i][j][k]	 = new double[2];
	  	  finalW[i][j][k]	 = new double[2];
	  	  p[i][j][k]		 = new double[2];
	  	  pCorr[i][j][k]	 = new double[2];
	 	 }
		   
	  }
	}


	
	


}
