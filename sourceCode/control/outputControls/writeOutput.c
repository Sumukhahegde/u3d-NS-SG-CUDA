//Outputs values to files


#include<stdio.h>
#include<string.h>
#include "/home/suhas/Desktop/myNavierStokesCUDASolver/preProcessing/input/variables.H"


void writeOutput()
{


	//output file names
	if(t<100)
	{
		f0 = (char)('0'+ (t % 10));
		f1 = (char)('0'+ (t / 10));
		f2 = '0';
		f3 = '0';
		f4 = '0';
		f5 = '0';
		f6 = '0';
		f7 = '0';
	}

	if((t>=100)&&(t<1000))
	{
		f0 = (char)('0'+ (t % 10));
		f1 = (char)('0'+ (t / 10 % 10));
		f2 = (char)('0'+ (t / 100));
		f3 = '0';
		f4 = '0';
		f5 = '0';
		f6 = '0';
		f7 = '0';
	}
	
	if((t>=1000)&&(t<10000))
	{
		f0 = (char)('0'+ (t % 10));
		f1 = (char)('0'+ (t / 10 % 100));
		f2 = (char)('0'+ (t / 100 % 10));
		f3 = (char)('0'+ (t / 1000));
		f4 = '0';
		f5 = '0';
		f6 = '0';
		f7 = '0';
	}

	if((t>=10000)&&(t<100000))
	{
		f0 = (char)('0'+ (t % 10));
		f1 = (char)('0'+ (t / 10 % 1000));
		f2 = (char)('0'+ (t / 100 % 100));
		f3 = (char)('0'+ (t / 1000 % 10));
		f4 = (char)('0'+ (t / 10000));
		f5 = '0';
		f6 = '0';
		f7 = '0';
	}
	
	if((t>=10000)&&(t<100000))
	{
		f0 = (char)('0'+ (t % 10));
		f1 = (char)('0'+ (t / 10 % 10000));
		f2 = (char)('0'+ (t / 100 % 1000));
		f3 = (char)('0'+ (t / 1000 % 100));
		f4 = (char)('0'+ (t / 10000 %10));
		f5 = (char)('0'+ (t / 100000));
		f6 = '0';
		f7 = '0';
	}
	
	if((t>=100000)&&(t<1000000))
	{
		f0 = (char)('0'+ (t % 10));
		f1 = (char)('0'+ (t / 10 % 100000));
		f2 = (char)('0'+ (t / 100 % 10000));
		f3 = (char)('0'+ (t / 1000 % 1000));
		f4 = (char)('0'+ (t / 10000 % 100));
		f5 = (char)('0'+ (t / 100000 % 10));
		f6 = (char)('0'+ (t / 1000000));
		f7 = '0';
	}

	if((t>=1000000)&&(t<10000000))
	{
		f0 = (char)('0'+ (t % 10));
		f1 = (char)('0'+ (t / 10 % 1000000));
		f2 = (char)('0'+ (t / 100 % 100000));
		f3 = (char)('0'+ (t / 1000 % 10000));
		f4 = (char)('0'+ (t / 10000 % 1000));
		f5 = (char)('0'+ (t / 100000 % 100));
		f6 = (char)('0'+ (t / 1000000 % 10));
		f7 = (char)('0'+ (t / 10000000));
	}
	


	strcpy (str,"/home/suhas/Desktop/myNavierStokesCUDASolver/postProcessing/output/output");
	str[73]=f7;
	str[74]=f6;
	str[75]=f5;
	str[76]=f4;
	str[77]=f3;
	str[78]=f2;
	str[79]=f1;
	str[80]=f0;
	str[81]='.';
	str[82]='c';
	str[83]='s';
	str[84]='v';

	
	fp=fopen(str,"w");  //opening the output file

	fprintf(fp,"x Coordinate,y Coordinate,z Coordinate,u Velocity,v Velocity,w Velocity,pressure\n");	

	for  (k=1; k<=nz+2; k++)
	 for (i=1; i<=nx+2; i++)
	  for(j=1; j<=ny+2; j++)
	{
			
		xCoord[i][j][k] = dx * i ;
	  	yCoord[i][j][k] = dy * j ;
	  	zCoord[i][j][k] = dz * k ;
		

		if((i==1)&&(j==1)&&(k==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k]+dy,zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(j==(ny+2))&&(k==(nz+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k],zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==1)&&(j==(ny+2))&&(k==(nz+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k],zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(j==1)&&(k==(nz+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k]+dy,zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(j==(ny+2))&&(k==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k],zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==1)&&(j==1)&&(k==(nz+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k]+dy,zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(j==1)&&(k==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k]+dy,zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==1)&&(j==(ny+2))&&(k==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k],zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);
		
		else if((i==1)&&(j==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k]+dy,zCoord[i][j][k]+dz/2,0.0,0.0,0.0,p[i][j][k][l]);

		else if((k==1)&&(j==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k]+dy,zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==1)&&(k==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k]+dy/2,zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(j==(ny+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k],zCoord[i][j][k]+dz/2,0.0,0.0,0.0,p[i][j][k][l]);

		else if((k==(nz+2))&&(j==(ny+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k],zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(k==(nz+2)))
	        fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k]+dy/2,zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);
		
		else if((i==1)&&(j==(ny+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k],zCoord[i][j][k]+dz/2,0.0,0.0,0.0,p[i][j][k][l]);

		else if((k==1)&&(j==(ny+2)))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k],zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(k==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k]+dy/2,zCoord[i][j][k]+dz,0.0,0.0,0.0,p[i][j][k][l]);

		else if((i==(nx+2))&&(j==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k]+dy,zCoord[i][j][k]+dz/2,0.0,0.0,0.0,p[i][j][k][l]);

		else if((k==(nz+2))&&(j==1))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k]+dy,zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);
		
		else if((i==1)&&(k==(nz+2)))
	        fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k]+dy/2,zCoord[i][j][k],0.0,0.0,0.0,p[i][j][k][l]);		
		




		else if(i==1)
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx,yCoord[i][j][k]+dy/2,zCoord[i][j][k]+dz/2,u[i][j][k][l],(v[i][j][k][l]+v[i+1][j][k][l])/2,(w[i][j][k][l]+w[i+1][j][k][l])/2,p[i][j][k][l]);
		
		else if(j==1)
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k]+dy,zCoord[i][j][k]+dz/2,(u[i][j][k][l]+u[i][j+1][k][l])/2,v[i][j][k][l],(w[i][j][k][l]+w[i][j+1][k][l])/2,p[i][j][k][l]);		

		else if(k==1)
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k]+dy/2,zCoord[i][j][k]+dz,(u[i][j][k][l]+u[i][j][k+1][l])/2,(v[i][j][k][l]+v[i][j][k+1][l])/2,w[i][j][k][l],p[i][j][k][l]);		

		else if(i==(nx+2))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k]+dy/2,zCoord[i][j][k]+dz/2,u[i-1][j][k][l],(v[i][j][k][l]+v[i-1][j][k][l])/2,(w[i][j][k][l]+w[i-1][j][k][l])/2,p[i][j][k][l]);
	
		else if(j==(ny+2))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k],zCoord[i][j][k]+dz/2,(u[i][j][k][l]+u[i][j-1][k][l])/2,v[i][j-1][k][l],(w[i][j][k][l]+w[i][j-1][k][l])/2,p[i][j][k][l]);			

		else if(k==(nz+2))
		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k]+dx/2,yCoord[i][j][k]+dy/2,zCoord[i][j][k],(u[i][j][k][l]+u[i][j][k-1][l])/2,(v[i][j][k][l]+v[i][j][k-1][l])/2,w[i][j][k-1][l],p[i][j][k][l]);

		else
	     {
		xCoord[i][j][k] = dx * i + dx/2;
	  	yCoord[i][j][k] = dy * j + dy/2;
	  	zCoord[i][j][k] = dz * k + dz/2;

		fprintf(fp,"%e,%e,%e,%e,%e,%e,%e\n",xCoord[i][j][k],yCoord[i][j][k],zCoord[i][j][k],finalU[i][j][k][l],finalV[i][j][k][l],finalW[i][j][k][l],p[i][j][k][l]);
	     }
	}
	
	
	fclose(fp);

}
