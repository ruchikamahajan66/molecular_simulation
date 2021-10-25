//Program to calculate the kinetic energy of the system
//scale velocities if necessary

double vscale(int np, double **r, int neq, int stp, double te)
{

    int i;
    //Kinetic energy of the system
    double ke;
    ke=0.0;

    for(i=0;i<np;i++){
        ke+=r[i][1]*r[i][1];
    }

    if(stp>neq);

    //Temperature of the system
    double temp;

    temp=ke/(double)np/3.0;
        //Calculate scaling factor
        //
        double sc;

    sc=sqrt(te/temp);

    for(i=0;i<np;i++){
        r[i][1]*=sc;
        
    }

    printf("scaling factor %lf temperture = %lf\n ",sc,temp);
    return ke/2.0;
}
