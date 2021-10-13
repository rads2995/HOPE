///////////////////////////////////////////////////////////////////////////////
////////// Table look-up and interpolation function declarations //////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//Class 'Table'
//Stores table data
//
//030710 Created by Peter Zipfel
///////////////////////////////////////////////////////////////////////////////
class Table 
{
private:
	string name;	//table name 										
	int dim;	//table dimension (1,2, or 3)										
	int	var1_dim;	// variable 1 dimension	
	int	var2_dim;	// variable 2 dimension	
	int	var3_dim;	// variable 3 dimension	
public:
	double *var1_values;  //values of variable 1 
	double *var2_values;  //values of variable 2 
	double *var3_values;  //values of variable 3
	double *data; // table data values packaged in one array

	Table(){}
	virtual ~Table()
	{
		delete var1_values;
		delete var2_values;
		delete var3_values;
		delete data;
	}

	//Getting dimension of table
	int get_dim(){return dim;}

	//Getting name of table
	string get_name(){return name;}

	//Getting 1. independent variable dimension
	int get_var1_dim(){return var1_dim;}

	//Getting 2. independent variable dimension
	int get_var2_dim(){return var2_dim;}

	//Getting 3. independent variable dimension
	int get_var3_dim(){return var3_dim;}
	
	//Setting dimension of table
	void set_dim(int table_dim){dim=table_dim;}

	//Setting name of table
	void set_name(string tbl_name){name=tbl_name;}

	//Setting 1. independent variable dimension
	void set_var1_dim(int size){var1_dim=size;}

	//Setting 2. independent variable dimension
	void set_var2_dim(int size){var2_dim=size;}

	//Setting 3. independent variable dimension
	void set_var3_dim(int size){var3_dim=size;}

	//Setting 1. independent variable values
	void set_var1_value(int offset,double value){
		var1_values[offset]=value;	
	}
	
    //Setting 2. independent variable values
	void set_var2_value(int offset,double value){
		var2_values[offset]=value;	
	}
	
    //Setting 3. independent variable values
	void set_var3_value(int offset,double value){
		var3_values[offset]=value;	
	}
	
    //Setting tablular data values
	void set_data(int offset,double value){
		data[offset]=value;	
	}
};
