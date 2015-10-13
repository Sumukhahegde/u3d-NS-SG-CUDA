//calculates the value of initial w velocity


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"
#include "wEqnCoeff.c"


void wEqn()
{
	
	n=nx;  //size of Matrix A and B
	
	size = sizeof(float) *n;

	create();

	for  (j=2; j<=ny+1; j++)
 {
	 for (k=2; k<=nz;   k++)
   {
	  for(i=2; i<=nx+1; i++)
	{
		wEqnCoeff();  //updating coefficients

		if(at==0)  printf("ERROR at=0 at cell [%d, %d, %d]",i,j,k); 
	
		lower[i-2]=-atW/at;  //lower diagonal of A Matrix
		if((lower[i-2]<accuracy)&&(lower[i-2]>-accuracy))	lower[i-2]=0;

		upper[i-2]=-atE/at;  //upper diagonal of A Matrix
		if((upper[i-2]<accuracy)&&(upper[i-2]>-accuracy))	upper[i-2]=0;

		middle[i-2]=1;
		if((middle[i-2]<accuracy)&&(middle[i-2]>-accuracy))	middle[i-2]=0;
       	
		//Matrix B
		if(i==2)	
	         c[i-2]=att/at*w[i][j][k+1][l] + ab/at*w[i][j][k-1][l] + aNt/at*w[i][j+1][k][l] + aSt/at*w[i][j-1][k][l] + (p[i][j][k][l] - p[i][j][k+1][l])*At + BBB + atW/at*w[i-1][j][k][l];
		
		else if(i==nx+1)
		 c[i-2]=att/at*w[i][j][k+1][l] + ab/at*w[i][j][k-1][l] + aNt/at*w[i][j+1][k][l] + aSt/at*w[i][j-1][k][l] + (p[i][j][k][l] - p[i][j][k+1][l])*At + BBB + atE/at*w[i+1][j][k][l];

		else
		 c[i-2]=att/at*w[i][j][k+1][l] + ab/at*w[i][j][k-1][l] + aNt/at*w[i][j+1][k][l] + aSt/at*w[i][j-1][k][l] + (p[i][j][k][l] - p[i][j][k+1][l])*At + BBB;  //check this

		 if((c[i-2]<accuracy)&&(c[i-2]>-accuracy))	c[i-2]=0;
	}
	
	
	
	prepareAndCompute();	//prepares GPU and Compute


	//Equating solved value back to velocity
	for(thomasI=0;thomasI<n;thomasI++) 
	  w[thomasI+2][j][k][l]=c[thomasI];

   }}

	clear();

	ghostCells();  //updates the ghost cells

}
