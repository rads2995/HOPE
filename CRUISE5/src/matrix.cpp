#include "matrix.h"
#include "constants.h"

#include <cmath>

#include <iostream>

using namespace std;
using namespace constants;

// Default constructor
Matrix::Matrix(){}

// Overloaded constructor
Matrix::Matrix(int num_row,int num_col) {
	
    this->num_row = num_row;
	this->num_col = num_col;

	pbody = nullptr;

	// Memory allocation
	this->num_elem = num_row * num_col;
    
    // TODO: implement a try-catch block
    pbody = new double[num_elem];

	// Initializing array to zero
	for (int i = 0; i < num_elem; i++)
        *(pbody + i) = 0;
}

// Copy constructor
Matrix::Matrix(const Matrix& MAT) {
	
    this->num_row = MAT.num_row;
	this->num_col = MAT.num_col;
	this->num_elem = MAT.num_elem;
	
    // TODO: implement a try-catch block
    pbody = new double[num_elem];

	// Copy matrix components
	for(int i = 0; i < num_elem; i++)
        *(pbody + i) = (*(MAT.pbody + i));
}

//Destructor
Matrix::~Matrix() {
	delete [] pbody;
}	

// Print matrix to console
void Matrix::print()
{
	double *pmem = pbody;

	//outside loop rows, inside loop columns
	for(int i=0;i<num_row;i++){
		for(int j=0;j<num_col;j++){
			cout<<*pbody<<"\t";
			pbody++;
		}
		cout<<'\n';
	}
	//resetting pointer
	pbody=pmem;
	cout<<"\n\n";
}

///////////////////////////////////////////////////////////////////////////////
//Absolute value of vector
//Example: avalue = VEC.absolute();
///////////////////////////////////////////////////////////////////////////////
double Matrix::absolute() 
{
	if(num_row>1&&num_col>1){cerr<<" *** Warning: not a vector 'Matrix::absolute()' *** \n";}
	double ret=0.0;
	
	for(int i=0;i<num_elem;i++) 
		ret+=(*(pbody+i))*(*(pbody+i));
	ret=sqrt(ret);

	return ret;
}

///////////////////////////////////////////////////////////////////////////////
//Adjoint matrix (same as determinant procedure however the matrix element
//is NOT multiplied into each cofactor)
//Example: BMAT = AMAT.adjoint();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::adjoint()
{
	if(!(num_row==num_col))
	{cerr<<" *** Error: matrix not square 'Matrix::adjoint()' *** \n";system("pause");exit(1);}
	if((num_row==1)&&(num_col==1))
	{cerr<<" *** Error: only one element 'Matrix::adjoint()' *** \n";system("pause");exit(1);}

	Matrix RESULT(num_row,num_col);

	for(int i=0;i<num_elem;i++){
		//row #
		int row=i/num_col+1;
		//column #
		int col=i%num_col+1;

		if (((row+col)%2)==0)
			*(RESULT.pbody+i)=sub_matrix(row,col).determinant();
		else
			*(RESULT.pbody+i)=(-1.0)*sub_matrix(row,col).determinant();
	}
	return RESULT.trans();
}

//////////////////////////////////////////////////////////////////////////////
//Assigns a value to a matrix element (offset!)
//Example: MAT.assign_loc(r,c,val); ((r+1)th-row, (c+1)th-col)
///////////////////////////////////////////////////////////////////////////////
void Matrix::assign_loc(const int &r, const int &c, const double &val)
{
	if(r>num_row-1||c>num_col-1)
	{cerr<<" *** Error: location outside array 'Matrix::assign_loc()' *** \n";system("pause");exit(1);}

	//assigning value
	int offset=num_col*(r)+c;
	*(pbody+offset)=val;	
}

///////////////////////////////////////////////////////////////////////////////
//Builds a 3x1 vector from three parameters
//Example: VEC.build_vec3(v1,v2,v3);
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::build_vec3(const double &v1,const double &v2,const double &v3)
{
	num_row=3;
	num_col=1;
	*pbody=v1;
	*(pbody+1)=v2;
	*(pbody+2)=v3;

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Builds a 3x3 matrix from nine paramters arranged in rows
//Example: MAT.build_mat33(v11,v12,v13,v21,v22,v23,v31,v32,v33);
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::build_mat33(const double &v11,const double &v12,const double &v13
						 ,const double &v21,const double &v22,const double &v23
					     ,const double &v31,const double &v32,const double &v33)
{
	num_row=3;
	num_col=3;
	*pbody=v11;    *(pbody+1)=v12;*(pbody+2)=v13;
	*(pbody+3)=v21;*(pbody+4)=v22;*(pbody+5)=v23;
	*(pbody+6)=v31;*(pbody+7)=v32;*(pbody+8)=v33;

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Calculates Cartesian from polar coordinates
//|V1|             | cos(elevation)*cos(azimuth)|
//|V2| = magnitude*|cos(elevation)*sin(azimuth) |
//|V3|		       |	  -sin(elevation)       |
//
//Example: VEC.cart_from_pol(magnitude,azimuth,elevation); 	
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::cart_from_pol(const double &magnitude,const double &azimuth
						   ,const double &elevation)
{
	*pbody=magnitude*(cos(elevation)*cos(azimuth));
	*(pbody+1)=magnitude*(cos(elevation)*sin(azimuth));
	*(pbody+2)=magnitude*(sin(elevation)*(-1.0));

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Returns column vector of column # 
//Example: VEC = MAT.col_vec(2); (2nd column!)
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::col_vec(const int &col)
{
	if(col<=0||col>num_col)
	{cerr<<" *** Error: column outside array 'Matrix::col_vec()' *** \n";system("pause");exit(1);}
	
	Matrix RESULT(num_row,1);

	for(int i=0;i<num_row;i++){
		int offset=i*num_col+col-1;
		*(RESULT.pbody+i)=(*(pbody+offset));
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the determinant		
//Determinant recursive procedure
//Example: det = MAT.determinant();
///////////////////////////////////////////////////////////////////////////////
double Matrix::determinant()
{
	if(!(num_row==num_col))
	{cerr<<" *** Error: matrix not square 'Matrix::determinant()' *** \n";system("pause");exit(1);}
	
	double result=0.0;

	//base case of a single matrix element
	if ((num_col==1)&&(num_row==1))
		return *pbody;

	//second base case of a 2x2 matrix
	else if ((num_col==2)&&(num_row==2))
		return (*pbody)*(*(pbody+3))-(*(pbody+1))*(*(pbody+2));

	else
	{
		for(int j=0;j<num_col;j++)
		{
			//use cofactors and submatricies to finish for nxn
			if ((j%2)==0)
			{
				//odd column (numbered!)
				result+=sub_matrix(1,j+1).determinant()*(*(pbody+j));
			}
				else
			{
				//even column (numbered!)
				result+=(-1.0)*sub_matrix(1,j+1).determinant()*(*(pbody+j));
			}
		}
	}	
	return result;
}

///////////////////////////////////////////////////////////////////////////////
//Returns nxn diagonal matrix  from nx1 vector 
//Example: DIAMAT=VEC.diamat_vec()
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::diamat_vec()
{
	if(num_col!=1)
	{cerr<<" *** Error: not a vector 'Matrix::diagmat_vec()' *** \n";system("pause");exit(1);}

	Matrix RESULT(num_row,num_row);
	for(int i=0;i<num_row;i++){
		int offset=i*num_row+i;
		*(RESULT.pbody+offset)=(*(pbody+i));
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Returns nx1 diagonal vector from nxn matrix
//Example: VEC=MAT.diavec_mat();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::diavec_mat()
{
	if(!(num_row==num_col))
	{cerr<<" *** Error: matrix not square 'Matrix::diavec_mat()' *** \n";system("pause");exit(1);}
	
	Matrix RESULT(num_row,1);
	for(int i=0;i<num_row;i++){
		int offset=i*num_row+i;
		*(RESULT.pbody+i)=(*(pbody+offset));
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Dimensions a matrix of size row x col
//Only used to initialize arrays in class 'Variable'
//Example: MAT.dimension(3,3);
///////////////////////////////////////////////////////////////////////////////
void Matrix::dimension(int row,int col)
{
	num_row=row;
	num_col=col;

	pbody=NULL;

	//allocating memory
	num_elem=row*col;
	try{pbody=new double[num_elem];}
	catch(bad_alloc xa){cerr<<"*** Error: memory allocation failed 'Matrix::dimension()' ***\n";system("pause");exit(1);}

	//initializing array to zero
	for(int i=0;i<num_elem;i++)
		*(pbody+i)=0.;
}
///////////////////////////////////////////////////////////////////////////////
//Bi-variate ellipse
//calculating major and minor semi-axes of ellipse and rotation angle 
//    from the symmetrical pos semi-definite MAT(2x2) matrix
//coordinate axes orientation:
//          ^ 1-axis
//          |
//          |
//          |---> 2-axis
//
//angle is measured from 1st coordinate axis to the right
//
//major_semi_axis = ELLIPSE.get_loc(0,0);
//minor_semi_axis = ELLIPSE.get_loc(1,0);
//angle      = ELLIPSE.get_loc(2,0);
//
//Example: ELLIPSE = MAT.ellipse();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::ellipse()
{
	Matrix ELLIPSE(3,1);
	double dum=0;
	double dum1=0;
	double dum2=0;
	double ama=0;
	double ami=0;
	double phi=0;
	double ak1=0;
	double ak2=0;
	Matrix X1V(2,1); //major principal axes of ellipse 
	Matrix X2V(2,1); //minor principal axes of ellipse 

	double a11=*pbody;
	double a22=*(pbody+3);
	double a12=*(pbody+1);
	double a1122=a11+a22;
	double aq1122=a1122*a1122;
	dum1=aq1122-4.*(a11*a22-a12*a12);
	if(dum1>=0.)dum2=sqrt(dum1);

	//major and minor semi-axes of ellipse
	ama=(a1122+dum2)/2.;
	ami=(a1122-dum2)/2.;
	ELLIPSE.assign_loc(0,0,ama);
	ELLIPSE.assign_loc(1,0,ami);
	if(ama==ami)return ELLIPSE;

	//angle of orientation of major axis wrt first principal axis
	if(a11-ama!=0.){
         dum1=-a12/(a11-ama);
         ak1=sqrt(1./(1.+dum1*dum1));
         X1V.assign_loc(0,0,dum1*ak1);
         X1V.assign_loc(1,0,ak1);
         dum=dum1*ak1;
         if(fabs(dum)>1.) dum=1.*sign(dum);
         phi=acos(dum);
		 ELLIPSE.assign_loc(2,0,phi);
	}
	else{
         dum1=-a12/(a22-ama);
         ak1=sqrt(1./(1.+dum1*dum1));
         X1V.assign_loc(0,0,ak1);
         X1V.assign_loc(1,0,dum1*ak1);
         if(fabs(ak1)>1.) ak1=1.*sign(ak1);
         phi=acos(ak1);
		 ELLIPSE.assign_loc(2,0,phi);
	}
	//second principal axis - not used
	if(a11-ami!=0.){
         dum2=-a12/(a11-ami);
         ak2=sqrt(1./(1.+dum2*dum2));
         X2V.assign_loc(0,0,dum2*ak2);
         X2V.assign_loc(1,0,ak2);
	}
	else{
         dum2=-a12/(a22-ami);
         ak2=sqrt(1./(1.+dum2*dum2));
         X2V.assign_loc(0,0,ak2);
         X2V.assign_loc(1,0,dum2*ak2);
	}
	return ELLIPSE;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the number of columns of matrix MAT
//Example: nc = MAT.get_cols();
///////////////////////////////////////////////////////////////////////////////
int Matrix::get_cols()
{
	return num_col;
}

///////////////////////////////////////////////////////////////////////////////
//Returns offset-index given row# and col#
//Example: i = MAT.get_index(2,3); (2nd row, 3rd column)
//////////////////////////////////////////////////////////////////////////////
int Matrix::get_index(const int &row, const int &col)
{
	int index;
		index=(row-1)*num_col+col-1;
	return index;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the value at offset-row 'r' offset-col 'c' of MAT
//Example: value = MAT.get_loc(2,1); (3rd row, 2nd column)
///////////////////////////////////////////////////////////////////////////////
double Matrix::get_loc(const int &r,const int &c)
{
	if((r<num_row)&&(c<num_col))
	return *(pbody+r*num_col+c);		
	else
	{cout<<"*** Error: invalid matrix location 'Matrix::get_loc()' *** ";system("pause");exit(1);}

}

///////////////////////////////////////////////////////////////////////////////
//Returns the number of rows in the matrix
//Example: nr = MAT.get_rows();
///////////////////////////////////////////////////////////////////////////////
int Matrix::get_rows()
{
	return num_row;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the pointer to MAT
//Example: ptr = MAT.get_pbody();
///////////////////////////////////////////////////////////////////////////////
double * Matrix::get_pbody()
{
	return pbody;
}

///////////////////////////////////////////////////////////////////////////////
//Builds a square identity matrix of object 'Matrix MAT'
//Example:	MAT.identity();
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::identity()
{
	if (num_row==num_col)
	{
		for(int r=0;r<num_row;r++)
			*(pbody+r*num_row+r)=1.;
	}
	else
	{cout<<"*** Error: matrix not square 'Matrix::identiy()'*** ";system("pause");exit(1);}

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the inverse of a square matrix AMAT 
//Inversion  INVERSE =(1/det(A))*Adj(A)
//Example: INVERSE = AMAT.inverse();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::inverse()
{
	if (num_col!=num_row)
	{cerr<<" *** Error: not a square matrix 'Matrix::inverse()' *** \n";system("pause");exit(1);}

	Matrix RESULT(num_row,num_col);
	double d=0.;

	d=determinant();
	if (d==0.)
	{cerr<<" *** Error: singular! 'Matrix::inverse()' *** \n";system("pause");exit(1);}

	d=1./d;
	RESULT=adjoint();
	RESULT=RESULT*d;

	return RESULT;
}
///////////////////////////////////////////////////////////////////////////////
//Returns 3x3 matrix row-wise from 9x1 vector
//Example: MAT=VEC.	mat33_vec9();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::mat33_vec9()
{
	if(!(num_row==9 && num_col==1))
	{cerr<<" *** Error: vector not 9 x 1 'Matrix::mat33_vec9()' *** \n";system("pause");exit(1);}
	
	Matrix RESULT(3,3);
	for(int i=0;i<9;i++){
		*(RESULT.pbody+i)=*(pbody+i);
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Forms  matrix MAT with all elements '1.' from object MAT(num_row,num_col)
//Example: MAT.ones();
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::ones()
{
	for(int r=0;r<num_elem;r++)
		*(pbody+r)=1.;

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Inequality relational operator, returns true or false 
//Returns true if elements differ by more than EPS
//Example: if(AMAT!=BMAT){...};
///////////////////////////////////////////////////////////////////////////////
bool Matrix::operator!=(const Matrix &B)
{
	//check dimensions
	if (num_col!=B.num_col)
			return true;
	else if
		(num_row!=B.num_row)
			return true;

	for (int i=0;i<num_elem;i++){
			//check to see if values differ by more or less than EPS
			if ((*(pbody+i)-(*(B.pbody+i)))>EPS)
				return true;
			else if ((*(pbody+i)-(*(B.pbody+i)))<(-1.*EPS))
				return true;
		}
	return false;
}

///////////////////////////////////////////////////////////////////////////////
//Scalar multiplication operator
//Note: scalar must be the second operand
//Example: CMAT = AMAT * b;
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::operator*(const double &b)
{
	Matrix RESULT(num_row,num_col);

	for (int i=0;i<num_elem;i++)
		*(RESULT.pbody+i)=*(pbody+i)*b;

	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Multiplication operator, return matrix product
// associative but not commutative
//Example: CMAT = AMAT * BMAT;
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::operator*(const Matrix &B)
{
	//create resultant matrix
	Matrix RESULT(num_row,B.num_col);
	int r=0; int c=0;

	//check for proper dimensions
	if (num_col!=B.num_row)
	{cout<<"*** Error: incompatible dimensions 'Matrix::operator*()' *** ";system("pause");exit(1);}

	for(int i=0;i<RESULT.num_elem;i++){
		r=i/B.num_col;
		c=i%B.num_col;
		for (int k=0; k<num_col;k++){
			*(RESULT.pbody+i)+= *(pbody+k+num_col*r)*(*(B.pbody+k*B.num_col+c));
		}
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Scalar multiplication assignment operator (scalar element by element multiplication)
//Example: AMAT *= b; meaning: AMAT = AMAT * b
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator*=(const double &b)
{
	for (int i=0;i<num_elem;i++)
		*(pbody+i)=*(pbody+i)*b;

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Matrix multiplication assignment operator
//matrix B in argument must be square
//Example: AMAT *= BMAT; meaning: AMAT = AMAT * BMAT; 
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator*=(const Matrix &B)
{
	//create resultant matrix
	Matrix RESULT(num_row,B.num_col);

	//check for proper dimensions
	if (num_col!=B.num_row)
	{cout<<"*** Error: incompatible dimensions 'Matrix::operator*=()' *** ";system("pause");exit(1);}

	//check for squareness of B
	if (B.num_col!=B.num_row)
	{cout<<"*** Error: Second matrix is not square 'Matrix::operator*=()' *** ";system("pause");exit(1);}

	int i;
	for(i=0;i<RESULT.num_elem;i++){
		int r=i/B.num_col;
		int c=i%B.num_col;
		for (int k=0; k<num_col;k++){
			*(RESULT.pbody+i)+= *(pbody+k+num_col*r)*(*(B.pbody+k*B.num_col+c));
		}
	}
	num_col=RESULT.num_col;
	num_row=RESULT.num_row;
	num_elem=num_row*num_col;
	for (i=0;i<num_elem;i++)
		*(pbody+i)=*(RESULT.pbody+i);

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Scalar Addition operator (scalar added to each element)
//Note: scalar must be the second operand
//Example: CMAT = AMAT + b; 
///////////////////////////////////////////////////////////////////////////////
Matrix  Matrix::operator+(const double &b)
{
	Matrix RESULT(num_row,num_col);

	for (int i=0;i<num_elem;i++)
		*(RESULT.pbody+i)=*(pbody+i)+b;

	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Addition operator, returns matrix addition
//Operands must be conformal
//Example: CMAT = AMAT + BMAT;
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::operator+(const Matrix &B)
{
	Matrix RESULT(num_row,num_col);

	if ((num_col!=B.num_col)||(num_row!=B.num_row))
	{cout<<"*** Error: matrices have different dimensions 'Matrix::operator +' *** ";system("pause");exit(1);}

	for (int i=0;i<num_elem;i++)
		*(RESULT.pbody+i)=*(pbody+i)+(*(B.pbody+i));

	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Scalar addition assignment operator (scalar added to each element)
//Example: AMAT += b; meaning: AMAT = AMAT + b 
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator+=(const double &b)
{
	for (int i=0;i<num_elem;i++)
		*(pbody+i)=*(pbody+i)+b;

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Matrix addition assignment operator
//Example: AMAT += BMAT; meaning: AMAT = AMAT + BMAT;
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator+=(const Matrix &B)
{
	if ((num_col!=B.num_col)||(num_row!=B.num_row))
	{cout<<"*** Error: matrices have different dimensions 'Matrix::operator +=' *** ";system("pause");exit(1);}

	for (int i=0;i<num_elem;i++)
		*(pbody+i)=*(pbody+i)+(*(B.pbody+i));

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Scalar subtraction operator (scalar subtracted from each element)
//Note: scalar must be the second operand
//Example: CMAT = AMAT - b;
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::operator-(const double &b)
{
	Matrix RESULT(num_row,num_col);
	for (int i=0;i<num_elem;i++)
		*(RESULT.pbody+i)=*(pbody+i)-b;

	return RESULT;
}
///////////////////////////////////////////////////////////////////////////////
//Subtraction operator, returns matrix subtraction
//Example: CMAT = AMAT - BMAT;
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::operator-(const Matrix &B)
{
	Matrix RESULT(num_row,num_col);

	if ((num_col!=B.num_col)||(num_row!=B.num_row))
	{cout<<"*** Error: matrices have different dimensions 'Matrix::operator -' *** ";system("pause");exit(1);}
	for (int i=0;i<num_elem;i++)
		*(RESULT.pbody+i)=*(pbody+i)-*(B.pbody+i);
	
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Scalar subtraction assignment operator (scalar subtracted from each element)
//Example: AMAT -= b; meaning: AMAT = AMAT - b
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator-=(const double &b)
{
	for (int i=0;i<num_elem;i++)
		*(pbody+i)=*(pbody+i)-b;

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Matrix subtraction assignment operator
//Example: AMAT -= BMAT; meaning: AMAT = AMAT - BMAT;
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator-=(const Matrix &B)
{
	if ((num_col!=B.num_col)||(num_row!=B.num_row))
	{cout<<"*** Error: matrices have different dimensions 'Matrix::operator +=' *** ";system("pause");exit(1);}

	for (int i=0;i<num_elem;i++)
		*(pbody+i)=*(pbody+i)-(*(B.pbody+i));

	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//Assignment operator (deep copy)
//Example: AMAT = BMAT; also: AMAT = BMAT = CMAT;
//Actually: AMAT.operator=(BMAT); also: AMAT.operator=(BMAT.operator=(CMAT));
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator=(const Matrix &B)
{
	if((num_row != B.num_row)||(num_col != B.num_col))
	{cerr<<" *** Error: incompatible dimensions 'Matrix::operator=()' *** \n";system("pause");exit(1);}

	delete [] pbody;
	num_elem=B.num_elem;
	num_row=B.num_row;
	num_col=B.num_col;
	pbody=new double[num_elem];

	for (int i=0;i<num_elem;i++)
		*(pbody+i)=(*(B.pbody+i));

	return *this;
}
///////////////////////////////////////////////////////////////////////////////
//Equality relational operator
//returns true if elements differ by less than EPS
//Example: if(AMAT==BMAT){...};
///////////////////////////////////////////////////////////////////////////////
bool Matrix::operator==(const Matrix &B)
{
	//check dimensions
	if (num_col!=B.num_col)
			return false;
	else if
		(num_row!=B.num_row)
			return false;

	for (int i=0;i<num_elem;i++){
			//check to see if values differ by more or less than EPS
			if ((*(pbody+i)-(*(B.pbody+i)))>EPS)
				return false;
			else if ((*(pbody+i)-(*(B.pbody+i)))<(-1.*EPS))
				return false;
		}
	return true;
}
///////////////////////////////////////////////////////////////////////////////
//Extracting components from vector with offset operator []
//returns the component(i) from vector VEC[i] or assigns a value to component VEC[i]
//Examples: comp_i=VEC[i]; VEC[i]=comp_i;
///////////////////////////////////////////////////////////////////////////////
double & Matrix::operator[](const int &r)
{
	if((r<num_row)&&(num_col=1))
		return *(pbody+r);		
	else
	{
		{cout<<"*** Error: invalid matrix location,'Matrix::operator[]' *** ";system("pause");exit(1);}
	}
}
///////////////////////////////////////////////////////////////////////////////
//Scalar product operator (any combination of row or column vectors)  
//Example: value = AMAT ^ BMAT;  
///////////////////////////////////////////////////////////////////////////////
double Matrix::operator^(const Matrix &B)
{
	//initialize the result
	double result=0.0;

	//check dimensions
	bool one=false;
	bool dim=false;
	//true if both arrays have dimension '1'
	if((num_row==1||num_col==1)&&(B.num_row==1||B.num_col==1))one=true;
	//true if both arrays have at least one equal dimension
	if((num_row==B.num_row||num_row==B.num_col)&&(num_col==B.num_col||num_col==B.num_row))dim=true;
	if(!one||!dim)
	{cerr<<" *** Error: incompatible dimensions 'Matrix::operator^()' *** \n";system("pause");exit(1);}

	for (int i=0;i<num_row;i++)
			result+=*(pbody+i)*(*(B.pbody+i));
	return result;
}
///////////////////////////////////////////////////////////////////////////////
//Alternate transpose Aji < Aij
//(same as 'Matrix trans()') 
//Example: BMAT = ~AMAT;
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::operator~()
{
	Matrix RESULT(num_col, num_row);
	int i=0; //offset for original matrix
	int j=0; //offset for transposed matrix

	for (int r=0;r<num_row;r++){
		for(int c=0;c<num_col;c++){
			//offset for transposed
			j=c*num_row+r;
			*(RESULT.pbody+j)=*(pbody+i);
			i++;j++;
		}
	}			
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Returns polar from cartesian coordinates
// magnitude = POLAR(0,0) = |V|
// azimuth   = POLAR(1,0) = atan2(V2,V1)
// elevation = POLAR(2,0) = atan2(-V3,sqrt(V1^2+V2^2)
//Example: POLAR = VEC.pol_from_cart();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::pol_from_cart() 
{
	double d=0.0;
	double azimuth=0.0;
	double elevation=0.0;
	double denom;
	Matrix POLAR(3,1);
	
	double v1=(*pbody);
	double v2=(*(pbody+1));
	double v3=(*(pbody+2));

	d=sqrt(v1*v1+v2*v2+v3*v3);
	azimuth=atan2(v2,v1);

	denom=sqrt(v1*v1+v2*v2);
	if(denom>0.)
		elevation=atan2(-v3,denom);
	else{
		if(v3>0) elevation=-PI/2.;
		if(v3<0) elevation=PI/2.;
		if(v3==0) elevation=0.;
	}
	
	*POLAR.pbody=d;
	*(POLAR.pbody+1)=azimuth;
	*(POLAR.pbody+2)=elevation;

	return POLAR;
}

///////////////////////////////////////////////////////////////////////////////
//Returns row vector of row # 
//Example: VEC = MAT.row_vec(2); (2nd row!)
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::row_vec(const int &row)
{
	if(row<=0||row>num_row)
	{cerr<<" *** Error: row outside array 'Matrix::row_vec()' *** \n";system("pause");exit(1);}
	
	Matrix RESULT(1,num_col);

	for(int i=0;i<num_col;i++){
		int offset=(row-1)*num_col+i;
		*(RESULT.pbody+i)=(*(pbody+offset));
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the skew-symmetric matrix from a 3-dim vector VEC
//			| 0 -c  b|		|a|
//			| c  0 -a| <--	|b|
//			|-b  a  0|		|c|
//
//Example: MAT = VEC.skew_sym();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::skew_sym()
{
	Matrix RESULT(3,3);
	//check for proper dimensions
	if (num_col!=1||num_row!=3)
	{cout<<"*** Error: not a 3x1 column vector 'Matrix::skew_sym()' *** ";system("pause");exit(1);}
	
	*(RESULT.pbody+5)=-(*pbody);
	*(RESULT.pbody+7)=(*pbody);
	*(RESULT.pbody+2)=(*(pbody+1));
	*(RESULT.pbody+6)=-(*(pbody+1));
	*(RESULT.pbody+1)=-(*(pbody+2));
	*(RESULT.pbody+3)=(*(pbody+2));

	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the sub matrix after 'row'  and 'col' have been ommitted 
//Example: BMAT = AMAT.sub_matrix(1,3); (deleting first row and third column!) 
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::sub_matrix(const int &row, const int &col)
{ 
	if((row>num_row)||(col>num_col))
	{cerr<<" *** Error: row or column outside array 'Matrix::sub_matrix()' *** \n";system("pause");exit(1);}
	if(row==0||col==0)
	{cerr<<" *** Error: row/col are numbered not offset 'Matrix::sub_matrix()' *** \n";system("pause");exit(1);}

	//create return matrix
	Matrix RESULT(num_row-1,num_col-1);
	//start and stop of skipping matrix elements 
	int skip_start=(row-1)*num_col;
	int skip_end=skip_start+num_col;

	//initialize RESULT offset j
	int j=0;

	for (int i=0;i<num_elem;i++){
		//skip elements of row to be removed
		if((i<skip_start)||(i>=skip_end)){
			//offset of column element to be removed
			int offset_col=(col-1)+(i/num_col)*num_col;
			//skip elements of col to be removed
			if(i!=offset_col){
				*(RESULT.pbody+j)=*(pbody+i);
				j++;
			}
		}
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Transpose Aji < Aij
//(same as 'Matrix operator~()' 
//Example: BMAT = AMAT.trans();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::trans()
{
	Matrix RESULT(num_col, num_row);
	int i=0; //offset for original matrix
	int j=0; //offset for transposed matrix

	for (int r=0;r<num_row;r++){
		for(int c=0;c<num_col;c++){
			//offset for transposed
			j=c*num_row+r;
			*(RESULT.pbody+j)=*(pbody+i);
			i++;j++;
		}
	}			
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Returns unit vector from 3x1 vector
//Example: UVEC=VEC.univec3();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::univec3()
{
	Matrix RESULT(3,1);
	//check for proper dimensions
	if (num_col!=1||num_row!=3)
	{cout<<" *** Error: not a 3x1 column vector in 'Matrix::univec()' *** \n";system("pause");exit(1);}

	double v1=(*pbody);
	double v2=(*(pbody+1));
	double v3=(*(pbody+2));
	double d=sqrt(v1*v1+v2*v2+v3*v3);

	//if VEC is zero than the unit vector is also a zero vector
	if(d==0){		
		*RESULT.pbody=0;
		*(RESULT.pbody+1)=0;
		*(RESULT.pbody+2)=0;
	}
	else{
		*RESULT.pbody=v1/d;
		*(RESULT.pbody+1)=v2/d;
		*(RESULT.pbody+2)=v3/d;
	}	
	return RESULT;
}
///////////////////////////////////////////////////////////////////////////////
//Returns 9x1 vector from 3x3 matrix 
//Example: VEC=MAT.vec9_mat33();
///////////////////////////////////////////////////////////////////////////////
Matrix Matrix::vec9_mat33()
{
	if(!(num_row==3 && num_col==3))
	{cerr<<" *** Error: matrix not 3 x 3 'Matrix::vec9_mat33()' *** \n";system("pause");exit(1);}
	
	Matrix RESULT(9,1);
	for(int i=0;i<9;i++){
		*(RESULT.pbody+i)=*(pbody+i);
	}
	return RESULT;
}

///////////////////////////////////////////////////////////////////////////////
//Forms a zero matrix MAT from object MAT(num_row,num_col)
//Example: MAT.zero();
///////////////////////////////////////////////////////////////////////////////
Matrix & Matrix::zero()
{
	for(int i=0;i<num_elem;i++)
		*(pbody+i)=0.0;

	return *this;
}
///////////////////////////////////////////////////////////////////////////////
////////////////// Module utility functions ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//Returns the T.M. of the psivg -> thtvg sequence
//
//010628 Created by Peter H Zipfel
////////////////////////////////////////////////////////////////////////////////

Matrix mat2tr(const double &psivg,const double &thtvg)
{
	Matrix AMAT(3,3);
	AMAT.assign_loc(0,2,-sin(thtvg));
	AMAT.assign_loc(1,0,-sin(psivg));
	AMAT.assign_loc(1,1,cos(psivg));
	AMAT.assign_loc(2,2,cos(thtvg));
	AMAT.assign_loc(0,0,(AMAT.get_loc(2,2) * AMAT.get_loc(1,1)));
	AMAT.assign_loc(0,1,(-AMAT.get_loc(2,2) * AMAT.get_loc(1,0)));
	AMAT.assign_loc(2,0,(-AMAT.get_loc(0,2) * AMAT.get_loc(1,1)));
	AMAT.assign_loc(2,1,(AMAT.get_loc(0,2) * AMAT.get_loc(1,0)));
	AMAT.assign_loc(1,2,0.0);

	return AMAT;
}
////////////////////////////////////////////////////////////////////////////////
//Returns the T.M. of the psi->tht->phi sequence
//Euler angle transformation matrix of flight mechanics
//
//011126 Created by Peter H Zipfel
////////////////////////////////////////////////////////////////////////////////

Matrix mat3tr(const double &psi,const double &tht,const double &phi)
{
	double spsi=sin(psi);
	double cpsi=cos(psi);
	double stht=sin(tht);
	double ctht=cos(tht);
	double sphi=sin(phi);
	double cphi=cos(phi);

	Matrix AMAT(3,3);
	AMAT.assign_loc(0,0,cpsi*ctht);
	AMAT.assign_loc(1,0,cpsi*stht*sphi-spsi*cphi);
	AMAT.assign_loc(2,0,cpsi*stht*cphi+spsi*sphi);
	AMAT.assign_loc(0,1,spsi*ctht);
	AMAT.assign_loc(1,1,spsi*stht*sphi+cpsi*cphi);
	AMAT.assign_loc(2,1,spsi*stht*cphi-cpsi*sphi);
	AMAT.assign_loc(0,2,-stht);
	AMAT.assign_loc(1,2,ctht*sphi);
	AMAT.assign_loc(2,2,ctht*cphi);

	return AMAT;
}
///////////////////////////////////////////////////////////////////////////////
//Returns the sign of the variable
//Example: value_signed=value*sign(variable) 
//010824 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////
int sign(const double &variable)
{
	int sign(0);
	if(variable<0.)sign=-1;
	if(variable>=0.)sign=1;

	return sign;
}

///////////////////////////////////////////////////////////////////////////////
//Returns the T.M. of geographic wrt earth coordinates
//
//000620 Created by Vy Nguyen
///////////////////////////////////////////////////////////////////////////////

Matrix cadtge( double lon, double lat)
{
	Matrix AMAT(3,3);
	double clon(0);
	double slon(0);
	double clat(0);
	double slat(0);
	
	clon = cos(lon);
	slon = sin(lon);
	clat = cos(lat);
	slat = sin(lat);

	AMAT.assign_loc(0,0,(-slat * clon));
	AMAT.assign_loc(0,1,(-slat * slon));
	AMAT.assign_loc(0,2,clat);
	AMAT.assign_loc(1,0,-slon);
	AMAT.assign_loc(1,1,clon);
	AMAT.assign_loc(1,2,0.0);
	AMAT.assign_loc(2,0,(-clat * clon));
	AMAT.assign_loc(2,1,(-clat * slon));
	AMAT.assign_loc(2,2,-slat);

	return AMAT;
}
////////////////////////////////////////////////////////////////////////////////
//Returns the T.M. of earth wrt inertial coordinates 
//
//000620 Created by Vy Nguyen
////////////////////////////////////////////////////////////////////////////////

Matrix cadtei(double simulation_time)
{
	double xi(0);
	double sxi(0);
	double cxi(0);
    Matrix TEI(3,3);

    xi=WEII3*simulation_time;
	sxi=sin(xi);
	cxi=cos(xi);
    
	TEI.identity();
    TEI.assign_loc(0,0, cxi); TEI.assign_loc(0,1, sxi);
	TEI.assign_loc(1,0,-sxi); TEI.assign_loc(1,1, cxi);

	return TEI;
}
////////////////////////////////////////////////////////////////////////////////
//Returns lon, lat, alt from inertial displacement vector
//
//000620 Created by Vy Nguyen
////////////////////////////////////////////////////////////////////////////////

Matrix cadsph(Matrix SBIE)
{
	double dum4(0);
	double alamda(0);
	double x(0),y(0),z(0);
	x=SBIE.get_loc(0,0);
	y=SBIE.get_loc(1,0);
	z=SBIE.get_loc(2,0);
	double dbi;
	double alt;
	double lat;
	double lon;
	Matrix RESULT(3,1);

   	//Latitude  
	dbi=sqrt(x*x+y*y+z*z);
	lat=asin((z)/dbi);

	//Altitude 
	alt=dbi-REARTH;

	//Longitude
	dum4=asin(y/sqrt(x*x+y*y));
	
	//Resolving the multi-valued arcsin function
	if((x>=0)&&(y>=0))
	{
		alamda=dum4;		   //quadrant I
	}
	if((x<0)&&(y>=0))
	{
		alamda=180*RAD-dum4;   //quadrant II
	}
	if((x<0)&&(y<0))
	{
		alamda=180*RAD-dum4;  //quadrant III
	}
	if((x>=0)&&(y<0))
	{
		alamda=360*RAD+dum4;  //quadrant IV
	}
	lon=alamda;
	if(lon>180*RAD)
	{
		lon= -(360*RAD-lon);  //east positive, west negative
	}
	RESULT.assign_loc(0,0,lon);
	RESULT.assign_loc(1,0,lat);
	RESULT.assign_loc(2,0,alt);

	return RESULT;
}
////////////////////////////////////////////////////////////////////////////////
//Returns the T.M of body wrt velocity coordintates (3 DoF)
//Suitable for 3 DoF bank-to-turn simulations only
//
//010129 Created by Peter H Zipfel
////////////////////////////////////////////////////////////////////////////////

Matrix cadtbv(double phi,double alpha)
{
	Matrix AMAT(3,3);

	double salpha=sin(alpha);
	double calpha=cos(alpha);
	double sphi=sin(phi);
	double cphi=cos(phi);

	AMAT.assign_loc(0,0,calpha);
	AMAT.assign_loc(0,1,sphi*salpha);
	AMAT.assign_loc(0,2,-cphi*salpha);
	AMAT.assign_loc(1,1,cphi);
	AMAT.assign_loc(1,2,sphi);
	AMAT.assign_loc(2,0,salpha);
	AMAT.assign_loc(2,1,-sphi*calpha);
	AMAT.assign_loc(2,2,cphi*calpha);

	return AMAT;
}

////////////////////////////////////////////////////////////////////////////
//Returns inertial coordinates from longitude, latitude and altitude
//
//010405 Created by Peter H Zipfel
////////////////////////////////////////////////////////////////////////////

Matrix cadine(double lon,double lat,double alt,double time)
{
	Matrix VEC(3,1);

	double rad=alt+REARTH;
	double cel_lon=lon+WEII3*time;
	double clat=cos(lat);
	double slat=sin(lat);
	double clon=cos(cel_lon);
	double slon=sin(cel_lon);

	VEC.assign_loc(0,0,rad*clat*clon);
	VEC.assign_loc(1,0,rad*clat*slon);
	VEC.assign_loc(2,0,rad*slat);

	return VEC;
}
////////////////////////////////////////////////////////////////////////////
//Returning the sign of the function
//Example: value_signed=value*sign(variable) 
//
//010824 Created by Peter H Zipfel
////////////////////////////////////////////////////////////////////////////
int sign(double variable)
{
	int sign(0);
	if(variable<0)sign=-1;
	if(variable>=0)sign=1;

	return sign;
}
///////////////////////////////////////////////////////////////////////////////
//Returns the angle between two 3x1 vectors
//Example: theta=angle(VEC1,VEC2);
//010824 Created by Peter H Zipfel
///////////////////////////////////////////////////////////////////////////////
double angle(Matrix VEC1,Matrix VEC2)
{
	double argument(0);
	double scalar=VEC1^VEC2;
	double abs1=VEC1.absolute();
	double abs2=VEC2.absolute();

	double dum=abs1*abs2;
	if(abs1*abs2>EPS)
		argument=scalar/dum;
	else
		argument=1.;
	if(argument>1.) argument=1.;
	if(argument<-1.) argument=-1.;

	return acos(argument);
}
