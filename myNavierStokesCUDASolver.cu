//my Navier Stokes solution


#include<stdio.h>
#include<assert.h>
#include<time.h>
#include "preProcessing/input/zeroTimeValues.c"
#include "preProcessing/input/input.c"
#include "preProcessing/mesh/boundaryConditions.c"
#include "sourceCode/algorithm/pressureVelocityCoupling/simple.c"
#include "sourceCode/control/solverControls/shift.c"
#include "sourceCode/algorithm/velocity/makeVelocityVectors.c"
#include "sourceCode/control/outputControls/writeOutput.c"
#include "sourceCode/control/outputControls/writeMesh.c"
#include "sourceCode/control/solverControls/incrementTime.c"
#include "sourceCode/control/outputControls/courantNumber.c"


                 
int main()
{

	defaultInput(); 	   	//Inputting the values required

	dynamicAllocate();		//dynamically allocates the arrays

	zeroTimeValues();   	//Gives initial values to all the variables and fields at time 0
	
	writeMesh();	      	//writes internal mesh to mesh.csv 
	
	


	t=1;			//output file starts from 1st time step
	simulationTime=dt;		//time counting starts from dt
	
	assert((start = clock())!=-1);			//starting real time

	
	while(simulationTime<=endTime)         //time loop                                                        
 	{
	  l = 1;
	  maxMassResidual = 100;

	  printf("\n\n\nsimulationTime :%lf seconds\n",simulationTime);
	
	  boundaryConditions();     //updates the values of the boundary cells
	
	  ghostCells();
	
	  simple(); 		    //simple algorithm

	  makeVelocityVectors();    //Interpolation of the velocity vectors back from staggerd cell centers to the pressure cell centers 

	  writeOutput();            //Outputs values to files

	  shift();		    //shifts the values to l=0
	  
	  courantNumber();	    //calculates courant number
	
	  incrementTime();	    //increments time variables

	
	  stop = clock();
	  realTime = (double) (stop-start)/CLOCKS_PER_SEC;
          printf("Run time: %2.2f seconds \n", realTime);				//printing real time
	}
  
return 0;	
}
 










