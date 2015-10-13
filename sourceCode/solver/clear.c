//clears arrays of solver


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H" 

void clear()
{


  //Free the Memory
  cudaFree(d_c);
  cudaFree(d_lower);
  cudaFree(d_upper);
  cudaFree(d_middle);



   free(upper);
   free(middle);
   free(lower);
   free(c);
	
} 
