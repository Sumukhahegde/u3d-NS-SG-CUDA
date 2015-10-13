//shifts the values to l=0


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

void shift()
{

	for  (k=0; k<(zNumberOfCells+5); k++)
	 for (j=0; j<(yNumberOfCells+5); j++)
	  for(i=0; i<(xNumberOfCells+5); i++)
	{
	  u[i][j][k][0]=u[i][j][k][1];
	  v[i][j][k][0]=v[i][j][k][1];
	  w[i][j][k][0]=w[i][j][k][1];                          
	  p[i][j][k][0]=p[i][j][k][1];			//copying values to l=0
	  pCorr[i][j][k][0]=pCorr[i][j][k][1];

				
	  pCorr[i][j][k][1]=0;	                          //equating values in l=1 to zero
	  
	}



}



					
