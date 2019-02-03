#include <iostream>
#include <algorithm>
#include <cmath>

int main();


int main()
{
	std::string input{""};
	
	double numa{0}, numb{0}, inia{0}, inib{0};
	double mema{0};
	double memb{0};
	bool tell{false};
	bool memory{false};


	while(input != "exit")
	{

		std::cout << "input :> ";

		std::cin >> input;

		if(input.compare(0, 5, "enter") == 0){
			std::cin >> numa;
			std::cin >> numb;

			if(numa > numb){
				std::cout << "Error: invalid interval as " << numa << " > " << numb << std::endl;
				if(tell){
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
				}
				else
					std::cout << "--" << std::endl;
			}
			else{
				inia = numa;
				inib = numb;
				tell = true;
				std::cout << "[" << inia << ", " << inib << "]" << std::endl;
			}
		}

		else if(input.compare(0, 6, "negate") == 0){
			if(tell){
				std::cout << "[" << -inib << ", " << -inia << "]" << std::endl;
			}else{
				std::cout << "--" << std::endl;
			}
		}

		else if (input.compare(0, 6, "invert") == 0){
			if (tell){
				if(tell && (( inia>0&&inib>0) || (inia<0&&inib<0))){
					std::cout << "[" << 1 / inib << ", " << 1 / inia << "]" << std::endl;
				}

				if(inia<= 0 && inib >= 0){
					std::cout << "Error: division by zero" << std::endl << "--" << std::endl;
					tell = false;
				}
			}
			else{
				std::cout << "--" << std::endl;}

			}
			else if(input.compare(0, 2, "ms") == 0){
				if(tell){
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					mema=inia;
					memb=inib;
					memory=true;
				}else{
					std::cout << "--" << std::endl;
				}



			}
			else if(input.compare(0, 2, "mr") == 0){
				if(tell && memory){
					std::cout << "[" << mema << ", " << memb << "]" << std::endl;
				}
				else if(tell && !memory){
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;

				}else{
					std::cout << "--" << std::endl;
				}
			}
			else if(input.compare(0, 2, "mc") == 0){
				if(tell && memory){
					inia=mema;
					inib=memb;
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					mema=0;
					memb=0;
					memory = false;

				}else{
					std::cout << "--" << std::endl;
				}
			}

			else if(input.compare(0, 2, "m+") == 0){
				if(tell && memory){

					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					mema+=inia;
					memb+=inib;

				}else if(!tell){
					std::cout << "--" << std::endl;
				}
				else {
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
				}
			}
			else if(input.compare(0, 2, "m-") == 0){
				if(tell && memory){

					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					mema-=inia;
					memb-=inib;

				}else if(!tell){
					std::cout << "--" << std::endl;
				}
				else {
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
				}
			}

			else if(input.compare(0, 10, "scalar_add") == 0){
				double c;
				std::cin >> c;
				if(tell){

					inia+=c;
					inib+=c;
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else if(input.compare(0, 15, "scalar_subtract") == 0){
				double c;
				std::cin >> c;
				if(tell){

					inia-=c;
					inib-=c;
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else if(input.compare(0, 15, "scalar_multiply") == 0){
				double c;
				std::cin >> c;
				if(tell){

					if (c>0)
					{
						inia*=c;
						inib*=c;
						std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					}
					else if (c==0)
					{
						inia*=c;
						inib*=c;
						std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					}
					else
					{
						inia*=c;
						inib*=c;
						std::cout << "[" << inib << ", " << inia << "]" << std::endl;
					}


				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else if(input.compare(0, 17, "scalar_divided_by") == 0){
				double c;
				std::cin >> c;

				if(tell)
				{

					if (inia<=0 && inib>=0)
					{
						std::cout << "Error: division by zero." << std::endl << "--" << std::endl;
						tell = false;
					}

					else if (c>0)
					{
						double x{inia};
						inia = c/inib;
						inib = c/x;
						std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					}
					else if (c==0)
					{
						std::cout << "[" << c/inia << ", " << c/inib << "]" << std::endl;
					}
					else if (c<0)
					{
						inia = c/inia;
						inib = c/inib;
						std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					}


				}
				else {
					std::cout << "--" << std::endl;
				}
			}

			else if(input.compare(0, 13, "scalar_divide") == 0){
				double c;
				std::cin >> c;
				if(tell){

					if (c>0)
					{
						inia/=c;
						inib/=c;
						std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					}
					else if (c==0)
					{
						std::cout << "Error: division by zero" << std::endl << "--" << std::endl;

						tell = false;
					}
					else
					{
						inia/=c;
						inib/=c;
						std::cout << "[" << inib << ", " << inia << "]" << std::endl;
					}


				}
				else {
					std::cout << "--" << std::endl;
				}
			}

			else if(input.compare(0, 12, "interval_add") == 0){
				double c;
				double d;
				std::cin >> c;
				std::cin >> d;

				if(c > d){
					std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
					if (tell){
						std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					}
					else {
						std::cout << "--" << std::endl;
					}

				}
				else if(tell){


					inia+=c;
					inib+=d;
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;

				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else if(input.compare(0, 17, "interval_subtract") == 0){
				double c;
				double d;
				std::cin >> c;
				std::cin >> d;

				if(c > d){
					std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
					if (tell){
						std::cout << "[" << inia << ", " << inib << "]" << std::endl;
					}
					else {
						std::cout << "--" << std::endl;
					}

				}
				else if(tell){


					inia-=d;
					inib-=c;
					std::cout << "[" << inia << ", " << inib << "]" << std::endl;

				}
				else {
					std::cout << "--" << std::endl;
				}
			}

			else if(input.compare(0, 17, "interval_multiply") == 0){
				double c;
				double d; //;
				std::cin >> c;
				std::cin >> d;

				if(c > d)
				{
					std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
						if (tell)
						{
							std::cout << "[" << inia << ", " << inib << "]" << std::endl;
						}
						else
						 {
							std::cout << "--" << std::endl;
							}

				}
				else if(tell)
				{

					double x = inia*c;
					double y = inia*d;
					double z = inib*c;
					double w = inib*d;
					inia = std::min({x, y, z, w});
					inib = std::max({x, y, z, w});

					std::cout << "[" << inia  << ", " << inib << "]" << std::endl;

				}
				else 
				{
					std::cout << "--" << std::endl;
				}
					}
			else if(input.compare(0, 15, "interval_divide") == 0)
			{

				double c;
				double d;
				std::cin >> c;
				std::cin >> d;
					if(c<=0 && d>=0)
						{
							std::cout << "Error: division by zero" << std::endl << "--" << std::endl;
							tell = false;
							}
					if(c > d)
					{
						std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;


			if (tell)
			{
				std::cout << "[" << inia << ", " << inib << "]" << std::endl;
			}
			else 
			{
				std::cout << "--" << std::endl;
				}

				}
			else if(tell)
			{

				double x = inia/c;
				double y = inia/d;
				double z = inib/c;
				double w = inib/d;
				inia = std::min({x, y, z, w});
				inib = std::max({x, y, z, w});

				std::cout << "[" << inia  << ", " << inib << "]" << std::endl;
			}

			else 
			{
				std::cout << "--" << std::endl;
			}
				}
				else if(input.compare(0, 9, "intersect") == 0){
					double c;
					double d;
					std::cin >> c;
					std::cin >> d;

	if(c > d)
	{
		std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;


		if (tell)
		{
			std::cout << "[" << inia << ", " << inib << "]" << std::endl;
		}
			else 
			{
				std::cout << "--" << std::endl;
			}

		}
		else if(tell)
		{

			if ((c>=inia && c<=inib) && (d>=inia && d<=inib))
				{
					inia = c;
					inib = d;
					std::cout << "[" << inia  << ", " << inib << "]" << std::endl;
				}
					else if (c<=inia && (d>=inia && d<=inib))
					{

						inib = d;
						std::cout << "[" << inia  << ", " << inib << "]" << std::endl;
					}
						else if ((c>=inia && c<=inib) && d>=inib){
							inia = c;
							std::cout << "[" << inia  << ", " << inib << "]" << std::endl;
					}

						else if(c<=inia && d>=inib)
						{
							std::cout << "[" << inia  << ", " << inib << "]" << std::endl;
						}
							else 
							{
								tell = false;
								std::cout << "--" << std::endl;
							}


		}
		else 
			{
				std::cout << "--" << std::endl;
			}
		}

			else if(input.compare(0, 8, "integers") == 0)
		{

			if (tell)
			{

				int x = ceil(inia);
				int y = floor(inib);

					for (int i=x; i<=y; i++)
						{
							std::cout << i;

								if (i!=y)
									{
										std::cout << ", ";
									}

						}
				std::cout << std::endl;
				std::cout << "[" << inia  << ", " << inib << "]" << std::endl;

			}
			else 
				{
					std::cout << "--" << std::endl;
				}
			}

		else if(input.compare(0, 18, "cartesian_integers") == 0)
		{
			double c;
			double d;
			std::cin >> c;
			std::cin >> d;

				if(c > d)
				{
					std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
					if (tell)
						{
							std::cout << "[" << inia << ", " << inib << "]" << std::endl;
						}
					else 
					{
						std::cout << "--" << std::endl;
					}

				}
		else if(tell)
		{

			int x = ceil(inia);
			int y = floor(inib);
			int z = ceil(c);
			int w = floor(d);
			if(z<=w)
			{
				for (int i=x; i<=y; i++)
				{
					for (int j=z; j<=w; j++)
					{
						if (i <= j)
						{
							std::cout << "(" << i << "," << j << ")";
						}
							else if (i >= j)
							{
								std::cout << "(" << j << "," << i << ")";
							}
								if (j!=w)
								{
									std::cout << ", ";
								}
					}
				if (i!=y)
				{
					std::cout << ", ";
				}




			}
				std::cout << std::endl;
			}

				std::cout << "[" << inia  << ", " << inib << "]" << std::endl;

		}


	else 
	{
		std::cout << "--" << std::endl;
	}
	}



	else if(!input.compare(0, 4, "exit") == 0)
	{
		std::cout << "Error: illegal input" << std::endl;
	}

	}
		std::cout << "Bye bye: Terminating interval calculator program." << std::endl;
		return 0;
}

