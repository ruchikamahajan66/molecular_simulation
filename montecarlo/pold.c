double pold(int np, double **r, double bl, int i)
{
	int j;

	//Set Lennard Jones cut-off
	double rc2=6.25;

	//Half box length 
	double blb2=bl/2.0;
	double c1,c2,potold,utail;

	//displacements
	double dx,dy,dz,ds2;
	//Variable for force and potential
	//
	double dsi6,vij,fij;

	vij=0.0;

	//Set up a loop over all particles
	c1=pow(1/2.5,9);
	c2=pow(1/2.5,3);

	//Define second particle in the pair

	for(j=i+1;j<np;j++){

		dx=r[j][0]-r[i][0];
		dy=r[j][1]-r[i][1];
		dz=r[j][2]-r[i][2];
		//printf("%lf %lf %lf\n",dx,dy,dz);

		//Apply minimum image convention
		
                /*
		while(dx>blb2){dx-=bl;}
		while(dx<=-blb2){dx+=bl;}
		while(dy>blb2){dy-=bl;}
		while(dy<=-blb2){dy+=bl;}
		while(dz>blb2){dz-=bl;}
		while(dz<=-blb2){dz+=bl;}
                */

		//printf("%lf %lf %lf\n",dx,dy,dz);

		//Square of distance between particles
		ds2=dx*dx+dy*dy+dz*dz;

		//Check for potential cutoff
		if(ds2<=rc2){

			dsi6=1.0/ds2/ds2/ds2;

			vij+=4.0*dsi6*(dsi6-1.0);

			//printf("vij=%lf\n",vij);
			utail=2.67*3.14*0.6*(1/3*(c1)-c2);

			//printf("utail=%f\n",utail);
			potold = vij + utail;
			// printf("newpot=%f\n",potnew);

		}
	}

	return potold;


}
