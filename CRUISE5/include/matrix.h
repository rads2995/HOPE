#ifndef LIBRARY_MATRIX_H
#define LIBRARY_MATRIX_H

#include "constants.h"

// One dimensional and two dimensional arrays of any dimension of type "double"
// Dynamically allocated matrix size and pointer arithmetic
class Matrix {
private:
    // Number of rows
	int num_row;
	// Number of columns
	int num_col;
	// Total number of elements
	int num_elem;
	// Pointer to array
	double *pbody;

public:
	// Default constructors
	Matrix();
	// Overloaded constructor
	Matrix(int row_size,int col_size);
	// Copy constructor
	Matrix(const Matrix& MAT);
	// Deconstructor
	~Matrix();

	// Print Matrix array to console
	void print();

	//Returns absolute value of a vector VEC
	double absolute();

	//Returns the adjoint
	Matrix adjoint();

	//Assigns a value to a matrix element (offset!)
	void assign_loc(const int &r, const int &c, const double &val);

	//Builds a 3x1 vector from three parameters
	Matrix & build_vec3(const double &v1,const double &v2,const double &v3);

	//Builds a 3x3 matrix from nine paramters arranged in rows
	Matrix & build_mat33(const double &v11,const double &v12,const double &v13
						 ,const double &v21,const double &v22,const double &v23
					     ,const double &v31,const double &v32,const double &v33);
	
	//Calculates Cartesian vector from polar coordinates
	// |V1|             | cos(elevation)*cos(azimuth)|
	// |V2| = magnitude*|cos(elevation)*sin(azimuth) |
	// |V3|		        |	  -sin(elevation)        |
	Matrix &cart_from_pol(const double &magnitude,const double &azimuth
						   ,const double &elevation);
						
	//Returns column vector of column # 
	Matrix col_vec(const int &col);

	//Returns the determinant
	double determinant();

	//Returns nxn diagonal matrix  from nx1 vector 
	Matrix diamat_vec();

	//Returns nx1 diagonal vector from nxn matrix
	Matrix diavec_mat();

	//Dimensions a matrix of size row x col
	void dimension(int row,int col);

	//Bi-variate ellipse
	//calculating major and minor semi-axes of ellipse and rotation angle 
	//    from the symmetrical pos semi-definite MAT(2x2) matrix
	//major_semi_axis = ELLIPSE.get_loc(0,0);
	//minor_semi_axis = ELLIPSE.get_loc(1,0);
	//angle      = ELLIPSE.get_loc(2,0);
	//
	Matrix ellipse();

	//Returns the number of columns of matrix MAT
	int get_cols();

	//Returns offset index given row# and col#
	int get_index(const int &row,const int &col);

	//Returns the value at offset-row 'r' offset-col 'c' of MAT
	double get_loc(const int &r,const int &c);

	//Returns the pointer to MAT
	double * get_pbody();

	//Returns the number of rows in the matrix
	int get_rows();

	//Builds a square identity matrix of object 'Matrix MAT'
	Matrix &identity();
	
	//Returns the inverse of a square matrix AMAT
	Matrix inverse();

	//Returns 3x3 matrix row-wise from 9x1 vector
	Matrix mat33_vec9();
	
	//Forms  matrix MAT with all elements '1.' from object MAT(num_row,num_col)
	Matrix & ones();

	//Inequality relational operator, returns true or false
	//returns true if elements differ by more than EPS
	bool operator!=(const Matrix &B);

	//Scalar multiplication operator (scalar element by element multiplication)
	//Note: scalar must be the second operand
	Matrix operator*(const double &b);

	//Multiplication operator, returns matrix product 
	Matrix operator*(const Matrix &B);

	//Scalar multiplication assignment operator (scalar element by element multiplication)
	Matrix & operator*=(const double &b);

	//Multiplication assignment operator 
	Matrix & operator*=(const Matrix &B);

	//Scalar Addition operator (scalar added to each element)
	//Note: scalar must be the second operand
	Matrix operator+(const double &b);

	//Addition operator, returns matrix addition
	//Operands must be conformal
	Matrix operator+(const Matrix &B);

	//Scalar addition assignment operator (scalar added to each element)
	Matrix & operator+=(const double &b);
	
	//Matrix addition assignment operator
	Matrix & operator+=(const Matrix &B);

	//Scalar subtraction operator (scalar element by element substraction)
	//Note: scalar must be the second operand
	Matrix operator-(const double &b);

	//Subtraction operator, returns matrix subtraction
	Matrix operator-(const Matrix &B);

	//Scalar subtraction assignment operator (scalar subtracted from each element)
	Matrix & operator-=(const double &b);

	//Matrix subtraction assignment operator
	Matrix & operator-=(const Matrix &B);

	//Assignment operator (deep copy) 
	Matrix &operator=(const Matrix &B);

	//Equality relational operator, returns true or false
	//returns true if elements differ by less than EPS
	bool operator==(const Matrix &B);

	//Returns the component(i) from vector VEC[i] or assigns a value to component VEC[i]
	double & operator [](const int &r);

	//Scalar product operator (any combination of row or column vectors)  
	double operator^(const Matrix &B);

	//Alternate transpose Aji < Aij
	//(same as 'Matrix trans()') 
	Matrix operator~();

	//Returns polar from cartesian coordinates
	// magnitude = POLAR(0,0) = |V|
	// azimuth   = POLAR(1,0) = atan2(V2,V1)
	// elevation = POLAR(2,0) = atan2(-V3,sqrt(V1^2+V2^2)
	Matrix pol_from_cart();

	//Returns row vector of row # 
	Matrix row_vec(const int &row);

	//Returns the skew-symmetric matrix MAT from a 3-dim vector VEC
	//			| 0 -c  b|		|a|
	//			| c  0 -a| <--	|b|
	//			|-b  a  0|		|c|
	//
	Matrix skew_sym();

	//Returns the sub matrix after 'row'  and 'col' have been ommitted 
	Matrix sub_matrix(const int &row, const int &col);

	//Returns the stranspose of a matrix Aji < Aij
	//(same as 'Matrix operator~()' 
	Matrix trans();

	//Returns unit vector from 3x1 vector
	Matrix univec3();

	//Returns 9x1 vector from 3x3 matrix 
	Matrix vec9_mat33();

	//Forms a zero matrix MAT from object MAT(num_row,num_col)
	Matrix &zero();
};

//Returns the T.M. of the psivg -> thtvg sequence
Matrix mat2tr(const double &psivg,const double &thtvg);

//Returns the Euler T.M. of the psi->tht->phi sequence
Matrix mat3tr(const double &psi,const double &tht,const double &phi);

//Returns the T.M. of geographic wrt earth coordinates
Matrix cadtge(double lon,double lat);

//Returns the T.M. of earth wrt inertial coordinates 
Matrix cadtei(double simulation_time);

//Returns lon, lat, alt from inertial displacement vector
Matrix cadsph(Matrix SBIE);

//Returns the T.M of body wrt velocity coordintates (3 DoF)
//Suitable for 3 DoF bank-to-turn simulations only
Matrix cadtbv(double phi,double alpha);

//Returns inertial coordinates from longitude, latitude and altitude
Matrix cadine(double lon,double lat,double alt,double time);

//Returns the sign of the function
int sign(const double &variable);

//Returns the angle between two 3x1 vectors
double angle(Matrix VEC1,Matrix VEC2);

#endif // LIBRARY_MATRIX_H
