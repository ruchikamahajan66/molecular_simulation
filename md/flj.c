//Program to calculated L-J forces from the 
//truncated potential

double flj(int np, double **r, double bl)
{
    int i,j;

    //Set Lennard Jones cut-off
   double rc2=6.25;

   //Half box length 
   double blb2=bl/2.0;

   //Calculate force using N(N+1)/2 operations
   //
   // Set new forces to zero
   for(i=0;i<np;i++){
       r[i][2]=0.0;
       
   }

   //displacements
   double dx,dy,dz,ds2;
   //Variable for force and potential
   //
   double dsi6,vij,fij;

   vij=0.0;

   //Set up a loop over all particles

   for(i=0;i<np;i++){

       //Define second particle in the pair

       for(j=i+1;j<np;j++){

           dx=r[j][0]-r[i][0];
           
           //printf("%lf %lf %lf\n",dx,dy,dz);

           //Apply minimum image convention
           //
           while(dx>blb2){dx-=bl;}
           while(dx<=-blb2){dx+=bl;}
           
           //square of distance between particle
           ds2=dx*dx;

           //Check for potential cutoff
           if(ds2<rc2){
               dsi6=1.0/ds2/ds2/ds2;
               vij+=4.0*dsi6*(dsi6-1.0);
               fij=(48.0*dsi6-24.0)*dx*dx;

               //printf("ds2=%lf vij= %lf fij=%lf\n",ds2,vij,fij);
               //Add forces on each pair according Newton's third law 
               r[i][2]-=fij*dx;
              
               r[j][2]+=fij*dx;
         
           }
       }
   }
   //printf("boxlength %lf hboxlength %lf \n",bl,blb2);

   return vij;


}
