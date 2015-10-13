//Inputs the custom value that is required for simulation 


#include<stdio.h>
#include "variables.H"
#include "defaultInput.c"

void input()
{

	printf("Do you want to enter custom values[y/n]\n");
	scanf("%c",&check);

	if(check=='y')
	{
	
		printf("Enter the domain length along x,y,z in m\n");
		scanf("%lf %lf %lf",&xDomainLength,&yDomainLength,&zDomainLength);

		printf("Enter the number of cells along x,y,z in m\n");
		scanf("%d %d %d",&xNumberOfCells,&yNumberOfCells,&zNumberOfCells);

		printf("Enter the start time in s\n");
		scanf("%lf",&startTime);
	
		printf("Enter the end time in s\n");
		scanf("%lf",&endTime);

		printf("Enter the time step size in s\n");
		scanf("%d",&nTimeSteps);

		printf("Enter the value of the density in SI\n");
		scanf("%lf",&rho);
	
		printf("Enter the value of the dynamic viscosity in SI\n");
		scanf("%lf",&mu);
	
		printf("Enter the wall velocities of top in m/s\n");
		scanf("%lf %lf %lf",&uTopWallVel,&vTopWallVel,&wTopWallVel);
	
		printf("Enter the wall velocities of bottom in m/s\n");
		scanf("%lf %lf %lf",&uBottomWallVel,&vBottomWallVel,&wBottomWallVel);	

		printf("Enter the wall velocities of left in m/s\n");
		scanf("%lf %lf %lf",&uLeftWallVel,&vLeftWallVel,&wLeftWallVel);

		printf("Enter the wall velocities of right in m/s\n");
		scanf("%lf %lf %lf",&uRightWallVel,&vRightWallVel,&wRightWallVel);

		printf("Enter the wall velocities of front in m/s\n");
		scanf("%lf %lf %lf",&uFrontWallVel,&vFrontWallVel,&wFrontWallVel);

		printf("Enter the wall velocities of back in m/s\n");
		scanf("%lf %lf %lf",&uBackWallVel,&vBackWallVel,&wBackWallVel);

		printf("Enter the value of under relaxation coefficient for pressure \n");
		scanf("%lf",&uRelaxCoeff);

		printf("Enter the value of Gravity along x,y,z in SI\n");
		scanf("%lf %lf %lf",&xGrav,&yGrav,&zGrav);

		printf("Enter the accuracy");
		scanf("%lf",&accuracy);
	}
	
	else	defaultInput();
		
}


                                                                    

