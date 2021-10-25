// MOLECULAR Dynamics simulation code for LJ particles
// 1) Set the initial parameteres
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "randno.c"
#include "initial.c"
#include "flj.c"
#include "move.c"
#include "vscale.c"
#include "rdf.c"

int main()
{
    //Indes variables
    int i,j,k;

    //Number of particles to simulate
    int np;

    np=10;
    //Desired density
    //
    double rho;
    rho=0.6;

    //Time step for integration
    double dt=0.001;

    //Number of steps
    int nstep=500;

    //Potential energy
    double v=0.0;
    //Kinetic energy

    double ke=0.0;

    //Temperature of the system
    double te=0.0;

    //Number of equilibration steps
    int neq;
    neq=500;

    //Box lenghth of the system
    double bl;
    bl=(double)np/rho;

    printf("box length=%lf\n",bl);

    //Set data structure to store coordinates
    double **r;
    //r[][0] - positions
    //r[][1] - velociites
    //r[][2] - new forces
    //r[][3] - old forces
    //3=1 6=2 9=3
    //Assign memory to the variables
    r=(double**)calloc(np,sizeof(double*));
    for(i=0;i<np;i++)r[i]=(double*)calloc(12,sizeof(double));

    //Initialize velocities and positions before 
    //start of integration
    initial(r,np,bl);

 // output file
	FILE *fout;
	fout = fopen("prj5.txt","w");

    //Integrate equation of motion for N steps

    for(i=0;i<nstep;i++){
        //Force calculation
        v=flj(np,r, bl);
        //Integration of equation of motion  
        move(np,r,dt);
        //Set temperature by velocity scaling
        ke=vscale( np,r, neq,i,te);
       // printf("step =%d, pe=%lf ke=%lf E=%lf\n",i,v,ke,ke+v);
        fprintf(fout,"%d\t\t %lf\t\t %lf\t\t %lf\n",i,v,ke,ke+v);
        
        if(i<neq)rdf(rho, np, r, bl);
    }
}
