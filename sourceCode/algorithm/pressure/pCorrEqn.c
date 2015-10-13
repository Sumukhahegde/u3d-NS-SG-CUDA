//calculates the value of pressure correction


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"
#include "pCorrEqnCoeff.c"

void pCorrEqn()
{
	
	n=nx;  //size of Matrix A and B

	size = sizeof(float) *n;
	
	create();


	for  (k=2; k<=nz+1; k++)
  {
	 for (j=2; j<=ny+1; j++)
   {
	  for(i=2; i<=nx+1; i++)
	{
		pCorrEqnCoeff();  //updating pressure correction coefficients

		if(aP==0)  printf("ERROR aP=0 at cell [%d, %d, %d]",i,j,k); 
	
		lower[i-2]=-aW/aP;  //lower diagonal of A Matrix
		if((lower[i-2]<accuracy)&&(lower[i-2]>-accuracy))	lower[i-2]=0;

		upper[i-2]=-aE/aP;  //upper diagonal of A Matrix
		if((upper[i-2]<accuracy)&&(upper[i-2]>-accuracy))	upper[i-2]=0;

		middle[i-2]=1;
		if((middle[i-2]<accuracy)&&(middle[i-2]>-accuracy))	middle[i-2]=0;
       	
		//Matrix B
		if(i==2)	
	         c[i-2] = aN/aP*pCorr[i][j+1][k][l] + aS/aP*pCorr[i][j-1][k][l] + aT/aP*pCorr[i][j][k+1][l] + aB/aP*pCorr[i][j][k-1][l] + Sc/aP + aW/aP*pCorr[i-1][j][k][l]; //check this
		
		else if(i==nx+1)
		 c[i-2] = aN/aP*pCorr[i][j+1][k][l] + aS/aP*pCorr[i][j-1][k][l] + aT/aP*pCorr[i][j][k+1][l] + aB/aP*pCorr[i][j][k-1][l] + Sc/aP + aE/aP*pCorr[i+1][j][k][l];

		else
		 c[i-2] = aN/aP*pCorr[i][j+1][k][l] + aS/aP*pCorr[i][j-1][k][l] + aT/aP*pCorr[i][j][k+1][l] + aB/aP*pCorr[i][j][k-1][l] + Sc/aP;

		 if((c[i-2]<accuracy)&&(c[i-2]>-accuracy))	c[i-2]=0;
		
	}
	
	
	
	prepareAndCompute();	//prepares GPU and Compute
	

	//Equating solved value back to pressure correction
	for(thomasI=0;thomasI<n;thomasI++) 
	  pCorr[thomasI+2][j][k][l]=c[thomasI];

 	
   }}


	clear();

	ghostCells();  //updates the ghost cells

}
