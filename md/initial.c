//

void initial(double **r, int n , double bl)
{
    int i,j,k;

    //Length of lattice
    int l;

    //Lenth of the lattice

    l=(int)round(pow((double)n,1.0));

    printf(" lattice length=%d \n",l);
    //Assign coordinates to all particles
    //First coordiate
     r[0][0]=0.0;
     
     //points in a plane
     

    printf(" points in a plane=%d \n",k);

    //Fill the lattice
    for(i=1;i<n;i++){
        //Incrementing the lines  to fill a plane
        //printf("%d\n",i);
      
                //Fill along a line
                r[i][0]=r[i-1][0]+1.0;
               
            }
        
    
//Scaling factor
    double sc;
    sc=(bl-1.0)/((double)l-1.0);
    for(i=0;i<n;i++){
    	
        r[i][0]=r[i][0]*sc;
      
    }

  //Initialize the velocities

  //Center of mass velocity
  double vs[3],dv[3];

  //Assign velocites 
  vs[0]=0.0;
  for(i=0;i<n;i++){

      r[i][1]=randno();
      vs[0]+=r[i][1];
      
  }
  for(i=0;i<n;i++){
      printf("%lf \n",r[i][1] );
  }

  printf("vel sums %lf \n",vs[0]);

  dv[0]=vs[0]/(double)n;
  
  vs[0]=0.0;
  for(i=0;i<n;i++){
      r[i][1]-=dv[0];
      vs[0]+=r[i][1];
     
  }
  printf("vel sums %lf \n",vs[0] );

  return;
}
