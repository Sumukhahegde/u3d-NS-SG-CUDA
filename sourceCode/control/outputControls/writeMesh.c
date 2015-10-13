//writes internal mesh to mesh.csv which can be opened using paraview


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"


void writeMesh()
{

	stepSize();

	fp=fopen("/home/suhas/Desktop/myNavierStokesCUDASolver/postProcessing/mesh/mesh.csv","w");  //opening the mesh file
	
	fprintf(fp,"x Coordinate,y Coordinate,z Coordinate\n");	
	
	for(k=0; k<=nz; k++)
	 for(j=0; j<=ny; j++)
	   for(i=0; i<=nx; i++)
	{	
	  xCoord[i][j][k] = dx * i;
	  yCoord[i][j][k] = dy * j;
	  zCoord[i][j][k] = dz * k;
	
	  fprintf(fp,"%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k],zCoord[i][j][k]);
	}

	fclose(fp);

	printf("Creating mesh\n");
	
}
