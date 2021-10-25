//Program to compute radial distribution function

void rdf(double de, int np, double **r, double bl)
{
    //Variable for indexing

    int i,j;

    //Count of number of times function is called
    //
    static int k=0;

    //Maximum distance upto which g(r) is calculated

    static double hbl;

    //Bin size 
    //
    static double dr;

    //Array for normalization factor and correlations
    static double *gr,*nf;
    //Size of the correlation array
    static int ngr;

    //printf("k=%d, bl=%lf",k,bl);

    if(k==0){

        //Half box length
        hbl=bl/2.0;

        //size of bin
        dr=0.01;

        //Number of bins
        ngr=(int)(hbl/dr);

        //Allocate space for g(r) and normalization factor
        gr=(double*)calloc(ngr,sizeof(double));
        nf=(double*)calloc(ngr,sizeof(double));

        //Volume of the unit sphere;
        double pf=4.0/3.0*atan(1.0)*4.0;

        //limiting radius of spheres
        double ri,rf;

        ri=0.0;
        rf=ri+dr;

        //Compute the volume of each spherical shell

        for(i=0;i<ngr;i++){
            //Volume of the shell
            nf[i]=pf*(rf*rf*rf-ri*ri*ri)*de;
            ri=rf;
            rf=ri+dr;
            printf("pf=%lf nf[%d]= %lf\n", pf,i,nf[i]);
        }

    }

    k++;

    //Distance variables;
    double dx,dy,dz,ds2,ds;

    //index of the bin
    int ibn;

    //Loop over all particles
    //
    //
    for(i=0;i<np;i++){

        //Loop over pairs
        for(j=i+1;j<np;j++){

            //Calculate distances               
            dx=r[j][0]-r[i][0];

            //printf("%lf %lf %lf\n",dx,dy,dz);

            //Apply minimum image convention
            //
            while(dx>hbl){dx-=bl;}
            while(dx<=-hbl){dx+=bl;}

            //printf("%lf %lf %lf\n",dx,dy,dz);
            //
            //Distance square
            ds2=dx*dx;

            //Distance
            ds=sqrt(ds2);

            //Index of the bin to be updated
            ibn=(int)(ds/dr);

            //printf("%lf %d\n",ds,ibn);

            if(ibn<ngr){
                gr[ibn]+=2.0;
            }//Endif 
        }


    }

    //Write out the g(r)
    if(k%10==0){
        FILE *fp=fopen("rdf.dat","w");

        for(i=0;i<ngr;i++){

            fprintf(fp,"%lf %lf\n",(double)i*dr+dr/2.0,gr[i]/nf[i]/(double)k/(double)np);
        }

        fclose(fp);
    }
}

