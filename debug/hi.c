#include<stdio.h>
#include<time.h>
#include<assert.h>


void main()
{




float a[250000],b[250000],c[250000],stop,start,realTime;

assert((start = clock())!=-1);			//starting real time



int i;


for(i=0;i<250000;i++)
{
	a[i] = 2;
	b[i] = 7;
}
for(i=0;i<250000;i++)
{
	c[i]=a[i]+b[i];
}


for(i=0;i<250000;i++)
{
printf("%e\n",c[i]);
printf("%e\n",a[i]);
printf("%e\n",b[i]);	
}


stop = clock();
	  realTime = (double) (stop-start)/CLOCKS_PER_SEC;
          printf("Run time: %f seconds \n", realTime);	


}
