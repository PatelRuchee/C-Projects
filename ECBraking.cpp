#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <math.h>
using namespace std;
int main (const int argc, const char* const argv[])
{
	int num = argc - 1;
	if (num < 3)
	{
		cerr << "Error: insufficient arguments; expecting 3 arguments ." << endl;
		return -1;
	}
	else if (num > 3)
	{
		cerr << "Warning: Expecting three command-line arguments; recieved " << num << " ; ignoring extraneous arguments." << endl;
	}
	float v;
	float x;
	float maxa;
	float finalv;
	float velocity;
	float distance;
	v = atof(argv[1]);
	x = atof(argv[2]);
	velocity = atof(argv[1]);
	distance = atof(argv[2]);
	maxa = atof(argv[3]);
	if (x<0 && v<0)
	{
		x = x * -1;
		v = v * -1;
	}
	float mina = (v * v / 2 / x);
	float t = (v / mina);
	if (velocity < 0 && distance < 0)
	{
		finalv = (-sqrt(velocity * velocity + 2 * maxa * distance));
	}
	else
	{
		finalv = (sqrt(velocity * velocity - 2 * maxa * distance));
	}
	if (x == 0)
	{
		t = (fabs(fabs(finalv) - fabs(v)) / maxa);
		cerr << "Crash will occur in " << t << " seconds at velocity " << finalv << " m/s; deploying airbags." << endl;
		return -1;
	}
	else if ((x > 0 && v < 0) || (x < 0 && v < 0))
	{
		cerr <<"There is no possibility of collision because the velocity and displacement are in opposite direction" << endl;
		return -1;
	}
	else if (v == 0)
	{
		cout << "There is no possibility of collision because the velocity is zero" << endl;
	}
	else if ((x > 0 && v > 0 ) || (x < 0 && v < 0))
	{
		if (mina > maxa)
		{
			t = (fabs(fabs(finalv) - fabs(v)) / maxa);
			cout << "Crash will occur in " << t << " seconds at velocity " << finalv << " m/s; deploying airbags." << endl;
		}
		if (mina <= maxa)
		{
			cout << "Initial car velocity: " << v << " m/s " << endl;
			cout << "Distance to obstacle: " << x << " m " << endl;
			cout << "Minimum deceleration: " << mina << " m/s/s " << endl;
			cout << "Maximum stopping time: " << t << " s " << endl;
		}
	}
	return 0;
}

