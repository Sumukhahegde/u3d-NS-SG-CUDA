//Updates the values of the boundary cells



#include<stdio.h>
#include "../input/variables.H"

void boundaryConditions()
{

	//velocity boundary conditions
       	for  (k=1; k<=nz+2; k++)
	 for (i=1; i<=nx+2; i++)
	  for(j=1; j<=ny+2; j++)
	{
	
	 u[1][j][k][l]    = uLeftWallVel;							//u[1][j][k][l]    = uLeftWallVel;
	 u[nx+1][j][k][l] = uRightWallVel;

	 v[i][1][k][l]    = vFrontWallVel;						//v[i][1][k][l]    = v[i][2][k][l];								
	 v[i][ny+1][k][l] = vBackWallVel;			//v[i][ny+1][k][l] = v[i][ny][k][l];								

	 //w[i][j][1][l]    = wBottomWallVel;					
	w[i][j][1][l]    = w[i][j][2][l];								//
	w[i][j][nz+1][l] = w[i][j][nz][l];	 
	//w[i][j][nz+1][l] = wTopWallVel;					//								//

	}
	

	//pressure boundary conditions
	 for  (k=1; k<=nz+2; k++)
	  for (i=1; i<=nx+2; i++)
	   for(j=1; j<=ny+2; j++)
	  {
	   p[1][j][k][l]  = 0;
	   p[i][1][k][l]  = p[i][2][k][l];
	   p[i][j][1][l]  = p[i][j][2][l];
	   p[nx+2][j][k][l]  = p[nx+1][j][k][l];
	   p[i][ny+2][k][l]  = p[i][ny+1][k][l];
	   p[i][j][nz+2][l]  = p[i][j][nz+1][l];   

	  }


}

