#include <stdlib.h>
#include <iostream> 

using namespace std;

int main(const int argc, const char* const argv[])
{

int n = 1;
float num;
float max=0;
float min=0;
float avg=0;

if (argc <2)
{
	cout << "Unable to compute statistics over data set because there are not sufficient values." << endl;
	}	

num = atof(argv[n]);

	while ( num< argc)
	{
		if (num > min )
		{
		min=num;
		}

		if (min < num && max < num)
		{		
		max=num;
		}

	avg= (avg +num)/n;
	n++;
}

	

 cout << "Number of floating point numbers:" << (argc-1) << endl;
 cout << "Minimum floating point number:" << min << endl;
 cout << "Average floating point number:" << avg << endl;
 cout << "Maximum floating point number:" << max << endl;

	
 return 0;
 
}




