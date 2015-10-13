//prepares GPU and solve the matrix


#include<stdio.h>
#include<cusparse_v2.h>
#include<stdlib.h>
#include <cuda_runtime.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"

 
void prepareAndCompute()
{


 	 /* Initialize cuSPARSE library */
  	cusparseStatus_t status;
  	cusparseHandle_t handle=0;
  	status= cusparseCreate(&handle);


   /* Copy data into device from host for TDMA/ another process*/
  cudaMemcpy(d_upper,upper,size,cudaMemcpyHostToDevice);
  cudaMemcpy(d_middle,middle,size,cudaMemcpyHostToDevice);
  cudaMemcpy(d_lower,lower,size,cudaMemcpyHostToDevice);
  cudaMemcpy(d_c,c,size,cudaMemcpyHostToDevice);
 
   /*TDMA solver using the cuSPARSE library*/
   status = cusparseSgtsv(handle, n, 1,d_lower, d_middle, d_upper, d_c, n) ;
   if (status != CUSPARSE_STATUS_SUCCESS)
	{													// vimp step for using status and for debugging!!!
        printf("CUSPARSE Library initialization failed");
    
    }
  cudaMemcpy(c,d_c,size,cudaMemcpyDeviceToHost);	   // copy back results as the output is returned in R_d vector

													  // which is also the RHS of AX=R . 

  
   
}


