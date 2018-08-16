#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[])

{

double vel;
double dis;
double dea;
double dea1;
double time1;
double time2;
double velf;



vel= atof(argv[1]);
dis= atof(argv[2]);
dea= atof(argv[3]);
dea1= ((vel*vel)/(dis*2));
time1= ((vel)/(dea));
velf=((vel)+ (dea*time1));
time2= ((velf)/(dea1));


cout <<"Enter in digits" << vel<< " "  << dis << " " << dea << " " << endl;

if ((vel*dis) < 0)
{
 cout << "There is no possibility of collision because the car is travelling in opposite direction." << endl;
}

 else if (dis >= dea1)
 {
 	
	 cout << "The minumum required deceleration is " << dea << endl;
	 cout << "The time required for stopping is " << time << endl;
  }
  
  else 
  {
	 cout << "Crash will occur in " <<time2<< " seconds at velocity " <<velf << ";deploying airbags." << endl;
	 
	}
	
 
 return 0;
 
} 
	 
	  

