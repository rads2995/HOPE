#pragma once

//Class 'Datadeck'
//Provides the 'Datadeck' class declaration for table look-ups
class Datadeck
{
private:
	string title; //title of data deck
	int capacity; //total number of tables
	int tbl_counter; //table counter
	Table **table_ptr; //table_ptr is pointer to a pointer array of type 'Table'

public:

	Datadeck(){}
	virtual ~Datadeck(){ delete [] table_ptr;}

	//Allocating memory  for table_ptr array
	void alloc_mem(){table_ptr=new Table *[capacity];}		

	//Setting table deck title
	void set_title(string deck_title){title=deck_title;}

	//Getting table deck title
	string get_title(){return title;}

	//Setting total number of tables
	void set_capacity(int table_numbers){capacity=table_numbers;}

	//Getting total number of tables
	int get_capacity(){return capacity;}

	//Setting table counter
	void set_counter(int count){tbl_counter=count;}

	//Getting table counter
	int get_counter(){return tbl_counter;}

	//Adding a table pointer to the table list
	void add_table(Table &pt)
	{
		if(tbl_counter<capacity){
			table_ptr[tbl_counter]=&pt;
		}
	}
	
    //Overloaded operator [] returns a 'Table' pointer
	Table * operator[](int slot)
	{
		if(slot>=0 && slot<capacity)
			return table_ptr[slot];
		else
		{
			cout<<"*** Bad pointer value of table deck: "<<slot<<'\n';
			return 0;
		}
	}
	
	//Getting table pointer
	Table * get_tbl(int slot){return table_ptr[slot];}

	//Single independent variable look-up
	//constant extrapolation at the upper end, slope extrapolation at the lower end
	double look_up(string name,double value1);

	//Two independent variables look-up
	// Constant extrapolation at the upper end, slope extrapolation at the lower end
	double look_up(string name,double value1,double value2);

	//Three independent variables look-up
	//constant extrapolation at the upper end, slope extrapolation at the lower end
	double look_up(string name,double value1,double value2,double value3);

	//Table index finder
	//This is a binary search method it is O(lgN)
	//* Returns array locater of the discrete_variable just below variable
	//* Keeps max or min array locater if variable is outside those max or min  
	int find_index(int max,double value,double *list);

	//Linear one-dimensional interpolation
	// Constant extrapolation beyond max values of X1
	// Slope extrapolation beyond min values of X1
	double interpolate(int ind,int ind2,int slot,double val);

	//Linear, two-dimensional interpolation
	// Constant extrapolation beyond max values of X1 and X2
	// Slope extrapolation beyond min values of X1 and X2
	double interpolate(int ind10,int ind11,int ind20,int ind21,int slot,double value1,
						double value2);																

	//Linear, three-dimensional interpolation
	//Constant extrapolation beyond max values of X1, X2 and X3
	//Slope extrapolation beyond min values of X1, X2 and X3
	double interpolate(int ind10,int ind11,int ind20,int ind21,int ind30,int ind31,
								 int slot,double value1,double value2,double value3);																					
};
