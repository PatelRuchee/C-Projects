#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(const int argc, const char* const argv[])
{
	if (argc < 4)
	{
		cerr << "Error: arguments must be given " << endl;
		return -1;
	}
	float max;
	float ewma;
	float min;
	float alpha = atof(argv[1]);
	float age = atof(argv[2]);
	int data = argc - 3;
	int count = 0;
	int max_age = 0;
	int min_age = 0;
	float amt[data];
	if (alpha < 0 || alpha > 1)
	{
		cerr << "Error: Invalid entry for alpha" << endl;
		return -1;
	}
	if (age <= 0)
	{
		cerr << "Error: Invalid entry for age" << endl;
		return -1;
	}
	while (count < data)
	{
		amt[count] = atof(argv[count + 3]);
		count++;
	}
	count = 0;
	cout << "Sample\tValue\tMinimum\tEWMA\tMaximum" << endl;
	while (count < data)
	{
		if (count == 0)
		{
			ewma = amt[count];
			min = amt[count];
			max = amt[count];
		}
		if (max_age == age)
		{
			max = amt[count];
			max_age = 0;
		}
		if (min_age == age)
		{
			min = amt[count];
			min_age = 0;
		}
		ewma = (alpha * amt[count]) + ((1 - alpha) * ewma);
		if (amt[count] > max)
		{
			max = amt[count];
			max_age = 0;
		}
		if (amt[count] < min)
		{
			min = amt[count];
			min_age = 0;
		}
		cout << count + 1 << "\t" << amt[count] << "\t" << min << "\t" << ewma << "\t" << max << endl;
		count++;
		max_age++;
		min_age++;
	}
	return 0;
}

