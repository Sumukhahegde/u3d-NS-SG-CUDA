//calculates the value of initial u velocity


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"
#include "uEqnCoeff.c"
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/mesh/ghostCells.c"
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/sourceCode/solver/prepareAndCompute.cu"
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/sourceCode/solver/create.c"
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/sourceCode/solver/clear.c"

void uEqn()
{
	
	n=ny;  //size of Matrix A and B

	size = sizeof(float) *n;

	create();


	for  (k=2; k<=nz+1; k++)
 {
	 for (i=2; i<=nx;   i++)
   {
	  for(j=2; j<=ny+1; j++)
	{
		uEqnCoeff();  //updating coefficients

		if(ae==0)  printf("ERROR ae=0 at cell [%d, %d, %d]",i,j,k); 
	
		lower[j-2]=(float)-aSe/ae;  //lower diagonal of A Matrix
		if((lower[j-2]<accuracy)&&(lower[j-2]>-accuracy))	lower[j-2]=0;

		upper[j-2]=(float)-aNe/ae;  //upper diagonal of A Matrix
		if((upper[j-2]<accuracy)&&(upper[j-2]>-accuracy))	upper[j-2]=0;

		middle[j-2]=(float)1;
		if((middle[j-2]<accuracy)&&(middle[j-2]>-accuracy))	middle[j-2]=0;
       	
		//Matrix B
		if(j==2)	
	         c[j-2]=(float)aee/ae*u[i+1][j][k][l] + aw/ae*u[i-1][j][k][l] + aTe/ae*u[i][j][k+1][l] + aBe/ae*u[i][j][k-1][l] + (p[i][j][k][l] - p[i+1][j][k][l])*Ae + B + aSe/ae*u[i][j-1][k][l];
		
		else if(j==ny+1)
		 c[j-2]=(float)aee/ae*u[i+1][j][k][l] + aw/ae*u[i-1][j][k][l] + aTe/ae*u[i][j][k+1][l] + aBe/ae*u[i][j][k-1][l] + (p[i][j][k][l] - p[i+1][j][k][l])*Ae + B + aNe/ae*u[i][j+1][k][l];

		else
		 c[j-2]=(float)aee/ae*u[i+1][j][k][l] + aw/ae*u[i-1][j][k][l] + aTe/ae*u[i][j][k+1][l] + aBe/ae*u[i][j][k-1][l] + (p[i][j][k][l] - p[i+1][j][k][l])*Ae + B;	//check this
	
		 if((c[j-2]<accuracy)&&(c[j-2]>-accuracy))	c[j-2]=0;
	}
	
	
	prepareAndCompute();	//prepares GPU and Computes

	
	//Equating solved value back to velocity
	for(thomasI=0;thomasI<n;thomasI++)
         u[i][thomasI+2][k][l]=c[thomasI];




 	
   }}

	clear();

	ghostCells();  //updates the ghost cells
	
}
