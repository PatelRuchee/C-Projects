#include <stdlib.h>
#include <iostream> 

using namespace std;

int main(const int argc, const char* const argv[])
{

int n=1;
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

	

 cout <<  "Sample " << "Value " << "Minimum" << "Maximim"<< endl;
 cout << "1" << " " << argv << " " <<min <<" " << agv<< " " << max << endl;
 cout << "2" << " " << argv << " " << min << " " << " " << (avg/2)<< " " << max <<endl;
 

	
 return 0;
 
}

