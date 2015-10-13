//calculates the value of initial v velocity


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"
#include "vEqnCoeff.c"


void vEqn()
{
	
	n=nz;  //size of Matrix A and B
		
	size = sizeof(float) *n;

	create();

	for  (i=2; i<=nx+1; i++)
 {
	 for (j=2; j<=ny;   j++)
   {
	  for(k=2; k<=nz+1; k++)
	{
		vEqnCoeff();  //updating coefficients

		if(an==0)  printf("ERROR an=0 at cell [%d, %d, %d]",i,j,k); 
	
		lower[k-2]=-anB/an;  //lower diagonal of A Matrix
		if((lower[k-2]<accuracy)&&(lower[k-2]>-accuracy))	lower[k-2]=0;

		upper[k-2]=-anT/an;  //upper diagonal of A Matrix
		if((upper[k-2]<accuracy)&&(upper[k-2]>-accuracy))	upper[k-2]=0;

		middle[k-2]=1;
		if((middle[k-2]<accuracy)&&(middle[k-2]>-accuracy))	middle[k-2]=0;
       	
		//Matrix B
		if(k==2)	
	         c[k-2]=anE/an*v[i+1][j][k][l] + anW/an*v[i-1][j][k][l] + ann/an*v[i][j+1][k][l] + as/an*v[i][j-1][k][l] + (p[i][j][k][l] - p[i][j+1][k][l])*An + BB + anB/an*v[i][j][k-1][l];
		
		else if(k==nz+1)
		 c[k-2]=anE/an*v[i+1][j][k][l] + anW/an*v[i-1][j][k][l] + ann/an*v[i][j+1][k][l] + as/an*v[i][j-1][k][l] + (p[i][j][k][l] - p[i][j+1][k][l])*An + BB + anT/an*v[i][j][k+1][l];

		else
		 c[k-2]=anE/an*v[i+1][j][k][l] + anW/an*v[i-1][j][k][l] + ann/an*v[i][j+1][k][l] + as/an*v[i][j-1][k][l] + (p[i][j][k][l] - p[i][j+1][k][l])*An + BB;  //check this
	
	   	 if((c[k-2]<accuracy)&&(c[k-2]>-accuracy))	c[k-2]=0;	
	}
	
	
	
	prepareAndCompute();	//prepares GPU and Compute


	//Equating solved value back to velocity
	for(thomasI=0;thomasI<n;thomasI++) 
	  v[i][j][thomasI+2][l]=c[thomasI];

   }}

	clear();

	ghostCells();  //updates the ghost cells

}
