#include "taylor.h"

/***********************************************************************
 *
 * Code generated by the TAYLOR translator.
 */

main(int argc, char **argv)
{
	 int       i, j, order=20, itmp=0, direction = 1, nsteps = -1;
	 double    ftmp, dstep, tolerance, rtolerance, log10tolerance, log10rtolerance;
	 MY_FLOAT  startT, stopT, nextT;
	 MY_FLOAT  myFloatZero;
	 MY_FLOAT  xx[5], yy[5], zz[5];
	 MY_FLOAT  **jet;
	 InitMyFloat(myFloatZero);
	 InitMyFloat(startT);
	 InitMyFloat(stopT);
	 InitMyFloat(nextT);
	 for(i=0; i<5; i++){InitMyFloat(xx[i]); InitMyFloat(yy[i]);InitMyFloat(zz[i]);}

	 MakeMyFloatA(myFloatZero, 0);

	 /* assign initials */
	 fprintf(stderr,"Enter Initial xx[0]: "); 
	 scanf("%le", &ftmp);	 MakeMyFloatA(xx[0], (double)ftmp );
	 fprintf(stderr,"Enter Initial xx[1]: "); 
	 scanf("%le", &ftmp);	 MakeMyFloatA(xx[1], (double)ftmp );
	 fprintf(stderr,"Enter Initial xx[2]: "); 
	 scanf("%le", &ftmp);	 MakeMyFloatA(xx[2], (double)ftmp );
	 fprintf(stderr,"Enter Initial xx[3]: "); 
	 scanf("%le", &ftmp);	 MakeMyFloatA(xx[3], (double)ftmp );
	 fprintf(stderr,"Enter start time: "); 
	 scanf("%le", &dstep);	 MakeMyFloatA(startT, dstep);
	 fprintf(stderr,"Enter stop time: "); 
	 scanf("%le", &dstep);	 MakeMyFloatA(stopT, dstep);
	 dstep=0.001; /* only nedeed when step_ctrl_method==0 (see manual) */
	 MakeMyFloatA(nextT, (double)dstep);
	 fprintf(stderr,"Enter absolute error tolerance: "); 
	 scanf("%le", &tolerance);
	 fprintf(stderr,"Enter relative error tolerance: "); 
	 scanf("%le", &rtolerance);
	 log10tolerance  = log10(tolerance);
	 log10rtolerance = log10(rtolerance);

	 /* the main loop */

	 if(dstep < (double)0.0) { direction = -1;}
	 do  {
		 printf("%g %g %g %g %g\n",(double)xx[0],(double)xx[1],(double)xx[2],(double)xx[3],(double)startT);

		 itmp = taylor_step_tbp( &startT, xx, direction, 1, log10tolerance, log10rtolerance, &stopT, &nextT, &order);
	     } while(itmp == 0); /* while */ 
	 exit(0); 
 } 
