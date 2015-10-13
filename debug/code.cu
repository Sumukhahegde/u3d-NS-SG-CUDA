#include<stdio.h>
#include<cusparse_v2.h>
#include<stdlib.h>
#include <cuda_runtime.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/sourceCode/solver/prepareAndCompute.cu"
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/sourceCode/solver/create.c"
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/sourceCode/solver/clear.c"



void allocate()
{

	

for(i=0;i<n;i++) 
{
	  if(i== 0 )
	  {
		  lower[i] = -0.0001996805;
		  upper[i]= -0.0001996805;
		  middle[i] = 1.0;
		  c[i] = 0;
	  }
	  if(i== n-1)
	  {
		 lower[i]=	 -0.0001996805 ;
		 upper[i] = -0.0001996805;
		 middle[i]  = 1.0;
		 c[i] = 0.0003993610;
	  }	
	  if(i>0 && i<n-1)
	  {
		  lower[i] =-0.0001996805;
		  middle[i] = 1.0;
		  upper[i] = -0.0001996805;
		  c[i] = 0;
	  }


	
}	
prepareAndCompute();



}




int main()
{
int j;

n=20;
 size = sizeof(float) *n;

create();


for(j=0;j<200;j++)
 allocate();	



clear();


   
return 0;   
}


