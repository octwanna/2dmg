//
//  2dmg_metric_analytic.c
//  2dmg
//
//  Created by Marco Ceze on 6/17/15.
//  https://github.com/mceze/2dmg
//

#include "2dmg_metric_analytic.h"

/******************************************************************/
/* function:  mg_metric_uniform */
/* receives array of x,y and returns metric values at each point  */
void mg_metric_uniform(double *x, double *y, int np, double *M)
{
  int ip;
  double xp, yp;
  
  for (ip = 0; ip < np; ip++) {
    xp = x[ip];
    yp = y[ip];
    M[ip*4+0] = 1.0;
    M[ip*4+1] = 0.0;
    M[ip*4+2] = 1.0;
  }
}

/******************************************************************/
/* function:  mg_metric_expx */
/* receives array of x,y and returns metric values at each point  */
void mg_metric_expx(double *x, double *y, int np, double *M)
{
  int ip;
  double xp, yp;
  
  for (ip = 0; ip < np; ip++) {
    xp = x[ip];
    yp = y[ip];
    M[ip*4+0] = 1.0+1000.0*exp(-pow((xp-0.5)/(0.01), 2.0));
    M[ip*4+1] = 0.0;
    M[ip*4+2] = 1.0;
  }
}

/******************************************************************/
/* function:  mg_metric_sqx */
/* receives array of x,y and returns metric values at each point  */
void mg_metric_sqx(double *x, double *y, int np, double *M)
{
  int ip;
  double xp, yp;
  
  for (ip = 0; ip < np; ip++) {
    xp = x[ip];
    yp = y[ip];
    M[ip*4+0] = 1.0+(xp-0.5)*(xp-0.5);
    M[ip*4+1] = 0.0;
    M[ip*4+2] = 1.0;
  }
}

/******************************************************************/
/* function:  mg_metric_linx */
/* receives array of x,y and returns metric values at each point  */
void mg_metric_linx(double *x, double *y, int np, double *M)
{
  int ip;
  double xp, yp;
  
  for (ip = 0; ip < np; ip++) {
    xp = x[ip];
    yp = y[ip];
    M[ip*4+0] = 1.0+1000.*xp;
    M[ip*4+1] = 0.0;
    M[ip*4+2] = 1.0;
  }
}