//creates arrays for solver


#include<stdio.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H" 

void create()
{

	lower= (float*) malloc(size);
   middle= (float*) malloc(size);
   upper= (float*) malloc(size);
   c= (float*) malloc(size);





	cudaMalloc((void**)&d_lower,size);
  cudaMalloc((void**)&d_upper,size);
  cudaMalloc((void**)&d_middle,size);
  cudaMalloc((void**)&d_c,size);

} 
