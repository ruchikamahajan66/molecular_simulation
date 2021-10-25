//Program to generate random numbers

double randno()
{
    int i;

    double s;

    i=rand();
// Interval between 0 and 1
    s=(double)i/(double)(RAND_MAX-1);
   //Change interval between -1 and 1
    s=2*s-1.0;
    //printf("rand no=%d max=%d rno =%lf\n",i,RAND_MAX,s);

    return  s;
}


