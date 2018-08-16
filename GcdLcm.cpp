#include <iostream>
#include <stdlib.h>

using namespace std;

int main( const int argc, const char* const argv[])
{
	int num = argc -1;
	if (num < 2)
	{
		cerr << "Error: Unable to compute GCD and/or LCM because there needs to be at least 2 entries." << endl;
		return -1;
	}
	if (num > 2)
	{
		cerr << "Warning: Expectng two command-line arguments; recieved " << num << "; ignoring extraneous arguments." << endl; 
	
	}
	
	int lcm;
	int gcd;
	int int_min= atoi(argv[1]);
	int int_max= atoi(argv[2]);
	int i;
	int num1;
	int num2;
	int total;
	num1= int_min;
	num2= int_max;
	total=(int_min % int_max); 
	
	if (int_min <= 0 || int_max <= 0)
	{
		cerr << "Error: Unable to compute GCD and/or LCM because the values need to be positive integers." << endl;
		return -1;
	}
	
	
	while( total != 0)
	{
		num1= num2;
		num2 = total;
		total = num1 % num2;
	}
	gcd = num2;
	
	lcm = (int_max/gcd);
	lcm = lcm*int_min;
	
	cout << "GCD(" << int_min << ", " << int_max << ") = " << gcd << endl;
	cout << "LCM(" << int_min << ", " << int_max << ") = " << lcm << endl;
	
	return 0;

}

