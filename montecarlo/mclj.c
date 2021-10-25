// Monte Carlo simulation code for LJ particles
// 1) Set the initial parameteres
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "randno.c"
#include "initial.c"
#include "pnew.c"
#include "pold.c"

int main()
{
	//Indes variables
	int i,j,k,n;

	//Number of particles to simulate
	int np;

	np=50;
	//Desired density
	
	double rho,potold,dr,potnew,delv;
	rho=0.6,dr=0.1;

	//Time step for integration
	double dt=0.01;

	//Number of steps
	int nstep=10;

	//Potential energy
	double v=0.0;
	//Kinetic energy

	double ke=0.0;

	//Temperature of the system
	double te=1.0;

	//Number of equilibration steps
	int neq;
	neq=100;

	//Box lenghth of the system
	double bl;
	bl=pow((double)np/rho,1.0/3.0);

	printf("box length=%lf\n",bl);

	//Set data structure to store coordinates
	double **r;
	//r[][0-2] - old positions
	//r[][3-5] - new positions
	
	//Assign memory to the variables
	r=(double**)calloc(np,sizeof(double*));
	for(i=0;i<np;i++)r[i]=(double*)calloc(12,sizeof(double));

	//Initialize velocities and positions before 
	//start of integration
	initial(r, np,bl);

	//Integrate equation of motion for N steps

	for(n=0;n<nstep;n++){

		for(i=0;i<np;i++){

			//Force calculation
			potold=pold(np,r,bl,i);

			//printf("oldpotential = %lf\n",potold);

			r[i][3]=r[i][0] + dr*(randno()-0.5);
			r[i][4]=r[i][1] + dr*(randno()-0.5);
			r[i][5]=r[i][2] + dr*(randno()-0.5);

                        // Apply Minimum Image Convention
                        
                        r[i][3]-=bl*rint(r[i][3]/bl);                      
                        r[i][4]-=bl*rint(r[i][4]/bl);                      
                        r[i][5]-=bl*rint(r[i][5]/bl);                      

			// printf("%lf %lf %lf\n",r[i][3],r[i][4],r[i][5]);

			potnew=pnew(np,r,bl,i);

			//printf("newp=%lf\n",potnew);
                         
                        delv= potnew-potold;

                        printf("oldpotential = %lf newp=%lf DeltaV = %lf\n",potold,potnew,delv);

		}
	}

	return 0;

}


