//Updates the values of the pressure and velocity ghost cells


#include<stdio.h>
#include "../input/variables.H"

void ghostCells()
{
	//velocity ghost cells
	for  (k=1; k<=nz+2; k++)
	 for (i=1; i<=nx+2; i++)
	  for(j=1; j<=ny+2; j++)
	{
	
	 //u[i][1][k][l]    = u[i][2][k][l];						
	u[i][1][k][l]    = 2 * uFrontWallVel  - u[i][2][k][l];
	 //u[i][ny+2][k][l] = u[i][ny+1][k][l]; 						
	u[i][ny+2][k][l] = 2 * uBackWallVel   - u[i][ny+1][k][l] ;
	 u[i][j][1][l]    = u[i][j][2][l];						
	//u[i][j][1][l]    = 2 * uBottomWallVel - u[i][j][2][l];
	 u[i][j][nz+2][l] = u[i][j][nz+1][l];						
	//u[i][j][nz+2][l] = 2 * uTopWallVel    - u[i][j][nz+1][l];
	
	 //v[1][j][k][l]    = v[2][j][k][l];						
	v[1][j][k][l]    = 2 * vLeftWallVel   - v[2][j][k][l];
	 v[nx+2][j][k][l] = 2 * vRightWallVel  - v[nx+1][j][k][l];
	 v[i][j][1][l]    = v[i][j][2][l];						
	//v[i][j][1][l]    = 2 * vBottomWallVel - v[i][j][2][l];
	 v[i][j][nz+2][l] = v[i][j][nz+1][l];						
	//v[i][j][nz+2][l] = 2 * vTopWallVel    - v[i][j][nz+1][l];	

	 //w[1][j][k][l]    = w[2][j][k][l];						
	w[1][j][k][l]    = 2 * wLeftWallVel   - w[2][j][k][l];
 	 w[nx+2][j][k][l] = 2 * wRightWallVel  - w[nx+1][j][k][l];
	 //w[i][1][k][l]    = w[i][2][k][l];						
	w[i][1][k][l]    = 2 * wFrontWallVel  - w[i][2][k][l];
	 //w[i][ny+2][k][l] = w[i][ny+1][k][l];						
	w[i][ny+2][k][l] = 2 * wBackWallVel   - w[i][ny+1][k][l];

	}
	

	//pressure ghost cells
	for  (k=1; k<=nz+2; k++)
	 for (i=1; i<=nx+2; i++)
	  for(j=1; j<=ny+2; j++)
	{
	 pCorr[1][j][k][l]    = 0;
	 pCorr[i][1][k][l]    = pCorr[i][2][k][l];
	 pCorr[i][j][1][l]    = pCorr[i][j][2][l];
	 pCorr[nx+2][j][k][l] = pCorr[nx+1][j][k][l];
	 pCorr[i][ny+2][k][l] = pCorr[i][ny+1][k][l];
	 pCorr[i][j][nz+2][l] = pCorr[i][j][nz+1][l];
	 
	}



}

