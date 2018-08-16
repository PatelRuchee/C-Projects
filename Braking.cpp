#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[])
{

	float acc;
	double vel;
	double dis;
	double time;
  
   
   if (vel=0)
   {
   		cerr << "Error: will not compile." << endl;
		return -1;
   }
   
   if (vel<0)
   {
   		cerr << "Error: will not compile." << endl;
		return -1;
   }
   
   if (dis<0)
   {
   		cerr << "Error: will not compile." << endl;
		return -1;
   }
  
	vel= atof(argv[1]);
    dis= atof(argv[2]);
    acc= (( vel*vel) / (2*dis));
    time=((vel)/(acc));
   
	cout << "Initial car velocity: " << vel << "m/s" << endl;
	cout << "Distance to obsticle: " << dis << "m" << endl;
	cout << "Minimum deceleration: " << acc << "m/s/s" << endl;
	cout << "Maximum stopping time: " << time << "s" << endl;

	return 0;

}

