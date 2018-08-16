#include <stdlib.h>
#include <iostream>
#include <float.h>
#include <math.h>

using namespace std;
int main(const int argc, const char* const argv[])
{
	int n = (argc-1);
	if (argc <2)
	{
		cerr << "Error: Unable to compute statistics over data set because there are not sufficient values." << endl;
		return -1;
	}	
	
	float max=atof(argv[1]);
	float min=atof(argv[1]);
	float sum=0;
	float variance=0;
	
	float array[n];
	int num = 1;
	int index =0;

	while ( num < argc)
	{
		array[index] = atof(argv[num]);
		if (array[index] < min )
		{
			min=array[index];
		}

		if (max < array[index])
		{		
			max=array[index];
		}

		sum= (sum + array[index]);
		num++;
		index++; 
	}

	float avg= (sum/index);
	

	for (int i=0; i <n; i++)
	{
	 variance += (array[i]- avg)* (array[i] - avg);
	}
	float pop = sqrt(variance / n);
	float sample = sqrt(variance/(n-1));
	
	

	 cout << "Number of floating-point numbers:" << (argc-1) << endl;
	 cout << "Minimum floating-point number:" << min << endl;
	 cout << "Average floating-point number:" << avg << endl;
	 cout << "Maximum floating-point number:" << max << endl;
	 cout << "Population standard deviation:" << pop << endl;
	 cout << "Sample standard deviaton: " << sample << endl;
 
	
 return 0;
}

