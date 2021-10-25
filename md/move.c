// Integrate the equation of motion using velocity Verlet algorithm
//
void move(int np,double **r,double dt)
{
    int i;
    double dt2b2;
    dt2b2=dt*dt/2.0;

   
    for(i=0;i<np;i++){

        //Update on velocities
        r[i][1]+=0.5*(r[i][2]+r[i][3])*dt;
        

        //Update on position
        r[i][0]+=r[i][1]*dt+r[i][2]*dt2b2;
       

        //replace old force array by new forces
        r[i][3]=r[i][2];
        

    } 
    
}
