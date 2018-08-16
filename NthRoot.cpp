#include <stdlib.h>
#include <float.h>
#include <iostream>

using namespace std;

int main( const  int argc, const char* argv[])
{
	int num= argc -1;
	if (num <3)
	{
	cerr << "Error:Unable to compute Nth root because insufficent arguments, need 3 arguments to compile." << endl;
	return -1;
	}
	
	if (num >3)
	{
	cerr << "Warning: need only 3 aruguments, got: " << num << " , will discard extra arguments." << endl;
	return -1;
	}
	
	long double x;
	int s;
	int root;
	float prec;
	float n;
	float p;
	int r;
	r = atoi(argv[2]);
	n = atof(argv[1});
	p = atof(argv[3]);
	
	if (r != 2)
	{
	cerr << "Error: Unable to compute Nth root because the root value needs to be positive" << endl;
	return -1;
	}
	 
	x = n/2;
	
	while( x < n)
		{
			p = 
	

