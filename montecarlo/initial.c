//

void initial(double **r, int n , double bl)
{
    int i,j,k;

    //Length of lattice
    int l;

    //Lenth of the lattice

    l=(int)round(pow((double)n,1.0/3.0));

    //printf(" lattice length=%d \n",l);
    //Assign coordinates to all particles
    //First coordiate
     r[0][0]=0.0;
     r[0][1]=0.0;
     r[0][2]=0.0;

     //points in a plane
     k=l*l;

    //printf(" points in a plane=%d \n",k);

    //Fill the lattice
    for(i=1;i<n;i++){
        //Incrementing the lines  to fill a plane
        //printf("%d\n",i);
        if(i%k==0){
            //printf("\n");
            printf("%d\n",i);
            r[i][0]=r[i-k][0];
            r[i][1]=r[i-k][1];
            r[i][2]=r[i-k][2]+1.0;
            //printf("%lf %lf %lf\n",r[i][0],r[i][1],r[i][2] );
        }else {
            if(i%l==0){
                //Incrementing the planes  to fill a volume
                //printf("\n");
                r[i][0]=r[i-l][0];
                r[i][1]=r[i-l][1]+1.0;
                r[i][2]=r[i-l][2];
                //printf("%lf %lf %lf\n",r[i][0],r[i][1],r[i][2] );

            }else{
                //Fill along a line
                r[i][0]=r[i-1][0]+1.0;
                r[i][1]=r[i-1][1];
                r[i][2]=r[i-1][2];
                //printf("%lf %lf %lf\n",r[i][0],r[i][1],r[i][2] );
            }
        }
    }
//Scaling factor
    double sc;
    sc=(bl-1.0)/((double)l-1.0);
    for(i=0;i<n;i++){
        r[i][0]=r[i][0]*sc;
        r[i][1]=r[i][1]*sc;
        r[i][2]=r[i][2]*sc;
       // printf("%lf %lf %lf\n",r[i][0],r[i][1],r[i][2] );   
 }
	//v=flj(np,r, bl);

  //Initialize the velocities

  //Center of mass velocity
  double vs[3],dv[3];

    return;
}
