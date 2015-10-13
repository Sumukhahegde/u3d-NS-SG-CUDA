#include<stdio.h>
#include<time.h>
#include<assert.h>

__global__ void add(float *a, float *b, float *c)
{

int index = threadIdx.x + blockIdx.x * blockDim.x;
c[index] = a[index] + b[index];


}



int main(void)
{





float *a, *b, *c;
float *d_a, *d_b, *d_c,stop,start,realTime;
int i;
int size = 250000*sizeof(float);



cudaMalloc((void **)&d_a, size);
cudaMalloc((void **)&d_b, size);
cudaMalloc((void **)&d_c, size);

a = (float*)malloc(size); 
b = (float*)malloc(size);
c = (float*)malloc(size); 

assert((start = clock())!=-1);			//starting real time



for(i=0;i<250000;i++)
{
	a[i] = 2;
	b[i] = 7;
}


cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

add<<<500,500>>>(d_a, d_b, d_c);


cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);




for(i=0;i<250000;i++)
{
printf("%e\n",c[i]);
printf("%e\n",a[i]);
printf("%e\n",b[i]);	
}

stop = clock();
	  realTime = (double) (stop-start)/CLOCKS_PER_SEC;
          printf("Run time: %2.2f seconds \n", realTime);	

cudaFree(d_a); cudaFree(d_b); cudaFree(d_c); 


free(a);
free(b);
free(c);

return 0;

}

