// utility_header.hpp: Declares the classes 'Matrix', 'Table','Datadeck',    
#pragma once

#include <iostream>
#include <cmath>
#include "global_constants.hpp"

// Integration of scalar state variable
// Modified Euler Midpoint method 
// Example first order lag:
//			phid_new=(phic-phi)/tphi;
//			phi=integrate(phid_new,phid,phi,int_step);
//			phid=phid_new;
double integrate(const double &dydx_new,const double &dydx,const double &y,const double &int_step);

// Integration of Matrix MAT(r,c) 
Matrix integrate(Matrix &DYDX_NEW,Matrix &DYDX,Matrix &Y,const double int_step);

// Calculates the atmospheric properties density pressure and temperature 
// up to 85 km.
void atmosphere76(double &rho,double &press,double &tempk, const double balt);
