///////////////////////////////////////////////////////////////////////////////
// FILE 'utility_functions.cpp'
//
//'Matrix' class member functions
//Module utility functions:
//	mat2tr
//	mat3tr
//	cadtge
//	cadtei
//	cadsph
//	cadtbv
//	cadine
//	sign
//	angle
//Table look-up,'Table' and 'Datadeck' class member functions
//Integration
//US76 Atmosphere
//
//010628 Created by Peter H Zipfel
//020829 Dynamically dimensioned utilities, PZi
//030319 Aded US76 atmosphere, PZi
//030424 General matrix integration, PZi
//030519 Overloaded operator [] for vector, PZi
//060510 Updated from F16C for CRUISE, PZi
///////////////////////////////////////////////////////////////////////////////

#include "utility_header.hpp"
#include "global_header.hpp"

///////////////////////////////////////////////////////////////////////////////
//////////////// Table look-up and interpolation functions ////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//Single independent variable look-up
//Constant extrapolation at the upper end, slope extrapolation at the lower end
//
//030717 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////

double Datadeck::look_up(string name,double value1)
{
	//finding slot of table in table pointer array (Table **table_ptr) 
	int slot(-1);
	string tbl_name;
	do{
		slot++;
		tbl_name=get_tbl(slot)->get_name();
	}while(name!=tbl_name);

		//getting table index locater of discrete value just below of variable value
	int var1_dim=get_tbl(slot)->get_var1_dim();
	int loc1=find_index(var1_dim-1,value1,get_tbl(slot)->var1_values);

	//using max discrete value if value is outside table
	if (loc1==(var1_dim-1)) return get_tbl(slot)->data[loc1];
		
	return interpolate(loc1,loc1+1,slot,value1);
}

///////////////////////////////////////////////////////////////////////////////
//Two independent variables look-up
//constant extrapolation at the upper end, slope extrapolation at the lower end
//
//030717 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////
double Datadeck::look_up(string name,double value1,double value2)
{
	//finding slot of table in table pointer array (Table **table_ptr) 
	int slot(-1);
	string tbl_name;
	do{
		slot++;
		tbl_name=get_tbl(slot)->get_name();
	}while(name!=tbl_name);

	
	//getting table index (off-set) locater of discrete value just below or equal of the variable value
	int var1_dim=get_tbl(slot)->get_var1_dim();
	int loc1=find_index(var1_dim-1,value1,get_tbl(slot)->var1_values);

	int var2_dim=get_tbl(slot)->get_var2_dim();
	int loc2=find_index(var2_dim-1,value2,get_tbl(slot)->var2_values);
		
	return interpolate(loc1,loc1+1,loc2,loc2+1,slot,value1,value2);
}

///////////////////////////////////////////////////////////////////////////////
//Three independent variables look-up
//constant extrapolation at the upper end, slope extrapolation at the lower end
//
//030723 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////
double Datadeck::look_up(string name,double value1,double value2,double value3)
{
	//finding slot of table in table pointer array (Table **table_ptr) 
	int slot(-1);
	string tbl_name;
	do{
		slot++;
		tbl_name=get_tbl(slot)->get_name();
	}while(name!=tbl_name);

	
	//getting table index locater of discrete value just below of variable value
	int var1_dim=get_tbl(slot)->get_var1_dim();
	int loc1=find_index(var1_dim-1,value1,get_tbl(slot)->var1_values);

	int var2_dim=get_tbl(slot)->get_var2_dim();
	int loc2=find_index(var2_dim-1,value2,get_tbl(slot)->var2_values);
		
	int var3_dim=get_tbl(slot)->get_var3_dim();
	int loc3=find_index(var3_dim-1,value3,get_tbl(slot)->var3_values);
		
	return interpolate(loc1,loc1+1,loc2,loc2+1,loc3,loc3+1,slot,value1,value2,value3);
}
///////////////////////////////////////////////////////////////////////////////
//Table index finder
//This is a binary search method it is O(lgN)
// Returns array locater (offset index) of the discrete_variable just below variable
// Keeps max or min array locater if variable is outside those max or min  
//
//030717 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////

int Datadeck::find_index(int max,double value,double *list)
{
	if(value>=list[max])
		return max;
	else if (value<=list[0]){
		return 0;
	}
	else{
		int index=0;
		int mid;
		while(index<=max){
			mid=(index+max)/2;		//integer division
			if(value<list[mid])
				max=mid-1;
			else if(value>list[mid])
				index=mid+1;
			else
				return mid;
		}
		return max;
	}
}

///////////////////////////////////////////////////////////////////////////////
//Linear one-dimensional interpolation
//Data deck must contain table in the following format:
//
// X1       Table Values(X1)
//
// X11		Y11
// X12		Y12
// X13		Y13
//           
// Constant extrapolation beyond max values of X1
// Slope extrapolation beyond min values of X1
//
//030717 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////

double Datadeck::interpolate(int ind1,int ind2,int slot,double val)
{
	double dx(0),dy(0);
	double dumx(0);

	double diff=val-get_tbl(slot)->var1_values[ind1];
	dx=get_tbl(slot)->var1_values[ind2]-get_tbl(slot)->var1_values[ind1];
	dy=get_tbl(slot)->data[ind2]-get_tbl(slot)->data[ind1];

	if(dx>EPS) dumx=diff/dx;
	dy=dumx*dy;

	return get_tbl(slot)->data[ind1]+dy;
}
///////////////////////////////////////////////////////////////////////////////
//Linear, two-dimensional interpolation
//File must contain table in the following form:
//
//  X1  X2  //Table Values(X1-row, X2-column)
//            ---------------
//  X11 X21   |Y11  Y12  Y13| 
//  X12 X22   |Y21  Y22  Y23|    <- data
//  X13 X23   |Y31  Y32  Y33| 
//  X14       |Y41  Y42  Y43| 
//            ---------------
//Constant extrapolation beyond max values of X1 and X2
//Slope extrapolation beyond min values of X1 and X2
//
//030718 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////

double Datadeck::interpolate(int ind10,int ind11,int ind20,int ind21,int slot,double value1,
					double value2)																
{
	double dx1(0),dx2(0);
	double dumx1(0),dumx2(0);

	int var1_dim=get_tbl(slot)->get_var1_dim();
	int var2_dim=get_tbl(slot)->get_var2_dim();

	double diff1=value1-get_tbl(slot)->var1_values[ind10];;
	double diff2=value2-get_tbl(slot)->var2_values[ind20];

	if(ind10==(var1_dim-1)) //Assures constant upper extrapolation of first variable
		ind11=ind10;
	else
		dx1=get_tbl(slot)->var1_values[ind11]-get_tbl(slot)->var1_values[ind10];

	if(ind20==(var2_dim-1)) //Assures constant upper extrapolation of second variable
		ind21=ind20;
	else
		dx2=get_tbl(slot)->var2_values[ind21]-get_tbl(slot)->var2_values[ind20];

	if(dx1>EPS) dumx1=diff1/dx1;		
	if(dx2>EPS) dumx2=diff2/dx2;
		
	double y11=get_tbl(slot)->data[ind10*var2_dim+ind20];
	double y12=get_tbl(slot)->data[ind10*var2_dim+ind21];
	double y21=get_tbl(slot)->data[ind11*var2_dim+ind20];
	double y22=get_tbl(slot)->data[ind11*var2_dim+ind21];
	double y1=dumx1*(y21-y11)+y11;
	double y2=dumx1*(y22-y12)+y12;

	return dumx2*(y2-y1)+y1;
}
///////////////////////////////////////////////////////////////////////////////
//Linear, three-dimensional interpolation
//File must contain table in the following form:
//
//  X1  X2  X3    Table Values(X1-row, X2-block, X3-column) <- don't type (illustration only)
//
//                (X1 x X3) (X1 x X3) (X1 x X3) (X1 x X3)	<- don't type 
//				   for X21   for X22   for X23   for X24	<- don't type 
//               -----------------------------------------
//  X11 X21 X31  |Y111 Y112|Y121 Y122|Y131 Y132|Y141 Y142|  
//  X12 X22 X32  |Y211 Y212|Y221 Y222|Y231 Y232|Y241 Y242|  <- data; don't type: '|'
//  X13 X23      |Y311 Y312|Y321 Y322|Y331 Y332|Y341 Y342| 
//      X24      ----------------------------------------- 
//               
//Constant extrapolation beyond max values of X1, X2 and X3
//Slope extrapolation beyond min values of X1, X2 and X3
//
//030723 Created and corrected by Peter Zipfel
///////////////////////////////////////////////////////////////////////////////
double Datadeck::interpolate(int ind10,int ind11,int ind20,int ind21,int ind30,int ind31,
							 int slot,double value1,double value2,double value3)
{
	double dx1(0),dx2(0),dx3(0);
	double dumx1(0),dumx2(0),dumx3(0);

	int var1_dim=get_tbl(slot)->get_var1_dim();
	int var2_dim=get_tbl(slot)->get_var2_dim();
	int var3_dim=get_tbl(slot)->get_var3_dim();

	double diff1=value1-get_tbl(slot)->var1_values[ind10];;
	double diff2=value2-get_tbl(slot)->var2_values[ind20];
	double diff3=value3-get_tbl(slot)->var3_values[ind30];

	if(ind10==(var1_dim-1)) //Assures constant upper extrapolation of first variable
		ind11=ind10;
	else
		dx1=get_tbl(slot)->var1_values[ind11]-get_tbl(slot)->var1_values[ind10];

	if(ind20==(var2_dim-1)) //Assures constant upper extrapolation of second variable
		ind21=ind20;
	else
		dx2=get_tbl(slot)->var2_values[ind21]-get_tbl(slot)->var2_values[ind20];

	if(ind30==(var3_dim-1)) //Assures constant upper extrapolation of third variable
		ind31=ind30;
	else
		dx3=get_tbl(slot)->var3_values[ind31]-get_tbl(slot)->var3_values[ind30];

	if(dx1>EPS) dumx1=diff1/dx1;		
	if(dx2>EPS) dumx2=diff2/dx2;
	if(dx3>EPS) dumx3=diff3/dx3;
	//int ind10,int ind11,int ind20,int ind21,int ind30,int ind31
	//      i        i+1        j         j+1       k        k+1
	// Use innner x1 and outer variable x3 for 2DIM interpolation, middle variable x2 is parameter
	// For parameter ind20
	double y11=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind20*var3_dim+ind30];
	double y12=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind20*var3_dim+ind30+var2_dim*var3_dim];
	double y31=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind20*var3_dim+ind31];
	double y32=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind20*var3_dim+ind31+var2_dim*var3_dim];
	//2DIM interpolation
	double y1=dumx1*(y12-y11)+y11;
	double y3=dumx1*(y32-y31)+y31;
	double y21=dumx3*(y3-y1)+y1;

	// For parameter ind21
	y11=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind21*var3_dim+ind30];
	y12=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind21*var3_dim+ind30+var2_dim*var3_dim];
	y31=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind21*var3_dim+ind31];
	y32=get_tbl(slot)->data[ind10*var2_dim*var3_dim+ind21*var3_dim+ind31+var2_dim*var3_dim];
	//2DIM interpolation
	y1=dumx1*(y12-y11)+y11;
	y3=dumx1*(y32-y31)+y31;
	double y22=dumx3*(y3-y1)+y1;

	//1DIM interpolation between the middle variable 
	return dumx2*(y22-y21)+y21;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////  Integration functions  //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//Integration of scalar state variable
//Modified Euler Midpoint method
//Example first order lag:
//			phid_new=(phic-phi)/tphi;
//			phi=integrate(phid_new,phid,phi,int_step);
//			phid=phid_new;
//050203 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////
double integrate(const double &dydx_new,const double &dydx,const double &y,const double &int_step)
{
	return y+(dydx_new+dydx)*int_step/2;
}

///////////////////////////////////////////////////////////////////////////////
//Integration of Matrix MAT(r,c) 
//
//030424 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////

Matrix integrate(Matrix &DYDX_NEW,Matrix &DYDX,Matrix &Y,const double int_step)
{
	int nrow=Y.get_rows();int nrow1=DYDX_NEW.get_rows();int nrow2=DYDX.get_rows();
	int ncol=Y.get_cols();int ncol1=DYDX_NEW.get_cols();int ncol2=DYDX.get_cols();

	if(nrow!=nrow1||nrow!=nrow2)
		{cerr<<" *** Error: incompatible row-dimensions 'integrate()' *** \n";system("pause");exit(1);}
	if(ncol!=ncol1||ncol!=ncol2)
		{cerr<<" *** Error: incompatible column-dimensions 'integrate()' *** \n";system("pause");exit(1);}

	Matrix RESULT(nrow,ncol);
	for(int r=0;r<nrow;r++)
		for(int c=0;c<ncol;c++)
			RESULT.assign_loc(r,c,integrate(DYDX_NEW.get_loc(r,c)
			,DYDX.get_loc(r,c),Y.get_loc(r,c),int_step));

	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
// US Standard Atmosphere 1976
// Calculates the atmospheric properties density pressure and temperature 
//	up to 85 km.
// Extrapolation above 71 km and beyond 85 km is carried out from 71 km altitude 
// Ref: Public Domain Aeronautical Software (see Web) Fortran Code
//
// Argument Output:
//					rho=Air density - kg/m^3
//					press= Air static pressure - Pa
//					tempk= Air temperature - degKelvin
// Argument Input:
//					balt= Geometrical altitude above S.L. - m
//
// 030318 Created by Peter Zipfel
///////////////////////////////////////////////////////////////////////////////

void atmosphere76(double &rho,double &press,double &tempk, const double balt)
{
	double rearth(6369.0); //radius of the earth - km
	double gmr(34.163195); //gas constant
	double rhosl(1.22500); //sea level density - kg/m^3
	double pressl(101325); //sea level pressure - Pa
	double tempksl(288.15); //sea level temperature - dK

	double htab[8]={0.0, 11.0, 20.0, 32.0, 47.0, 51.0, 71.0, 84.852}; //altitude
	double ttab[8]={288.15, 216.65, 216.65, 228.65, 270.65, 270.65, 214.65, 186.946}; //temperture
	double ptab[8]={1.0, 2.233611e-1, 5.403295e-2, 8.5666784e-3, 1.0945601e-3,
					6.6063531e-4, 3.9046834e-5, 3.68501e-6};  //pressure
	double gtab[8]={-6.5, 0.0, 1.0, 2.8, 0.0, -2.8, -2.0, 0.0};   //temperture gradient

	double delta(0);

	//convert geometric (m) to geopotential altitude (km)
	double alt=balt/1000; 
	double h=alt*rearth/(alt+rearth);

	//binary search determines altitude table entry i below actual altitude 
	int i(0); //offset of first value in table
	int j(7); //offset of last value in table
	for( ; ; ){
	  int k=(i+j)/2;     //integer division
	  if(h<htab[k])
	    j=k;
	  else
	    i=k;
	  if(j<=(i+1))break;
	}

	//normalized temperature 'theta' from table look-up and gradient interpolation
	double tgrad=gtab[i];
	double tbase=ttab[i];
	double deltah=h-htab[i];
	double tlocal=tbase+tgrad*deltah;
	double theta=tlocal/ttab[0]; 
	
	//normalized pressure from hydrostatic equations 
	if(tgrad==0)
	  delta=ptab[i]*exp(-gmr*deltah/tbase);
	else
	  delta=ptab[i]*pow((tbase/tlocal),(gmr/tgrad));

	//normalized density
	double sigma=delta/theta;

	//output
	rho=rhosl*sigma;
	press=pressl*delta;
	tempk=tempksl*theta;
}

