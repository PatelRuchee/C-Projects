

#include <iostream>
#include "Polynomial.h"

#ifndef POLYNOMIAL_H

#define POLYNOMIAL_H

struct poly_t
{
    double *a_coeffs;       // array of coefficients
    unsigned int degree;    // the degree of the polynomial

};

void init_poly( poly_t &p, double const init_coeffs[], unsigned int const init_degree );
void destroy_poly( poly_t &p );
unsigned int poly_degree( poly_t const &p );
double poly_coeff ( poly_t const &p, unsigned int n );
double poly_val( poly_t const &p, double x );
void poly_add( poly_t &p, poly_t const &q );
void poly_subtract( poly_t &p, poly_t const &q );
void poly_multiply( poly_t &p, poly_t const &q );
double poly_divide( poly_t &p, double r );
void poly_diff( poly_t &p );
double poly_approx_int( poly_t const &p, double a, double b, unsigned int n );

#endif



void init_poly( poly_t &p, double const init_coeffs[], unsigned int const init_degree)
{
	delete[]p.a_coeffs;
	p.a_coeffs = nullptr;

	 p.a_coeffs =  new double[init_degree+1];

	 for (int i = 0; i < init_degree+1 ; i++)
	 {
	 	p.a_coeffs[i] = init_coeffs[i];
	 }

	 	p.degree = init_degree;

	 	std::cout << "init_poly degree " <<  init_degree << std::endl;
	 	std::cout << "coeff" << init_coeffs[3] << std::endl;

}

	void destroy_poly (poly_t &p)  //needs to have *
{
		delete [] p.a_coeffs;
		p.a_coeffs = nullptr;


}

	unsigned int poly_degree (poly_t const &p)
{
	unsigned int degree{p.degree};

	if (p.a_coeffs == nullptr)
	{
		throw 0;
	}
	else
	{
		degree;
	}

	std::cout << " degree 2 " << degree << std::endl;
	return degree;
}

	double poly_coeff ( poly_t const &p, unsigned int n )
{
	//unsigned int number{0};
	if (p.a_coeffs == nullptr)                                        //still errors
	{
		throw 0;
	}

	if(n > p.degree)
	{
		return 0;
	}
	else
 	{
 		return p.a_coeffs[n];
 	}

 std::cout << "coeff 2 " << (p.a_coeffs, n) << std::endl;

}


	double poly_val( poly_t const &p, double x )
{
	double result{p.a_coeffs[p.degree]};

	for (unsigned int i= p.degree; i > 0 ; i--)
	{
		result = result*x + p.a_coeffs[i-1];
		
	}
	return result;
	std::cout << "result " << result << std::endl;

}



	void poly_add( poly_t &p, poly_t const &q )
{

	if (p.a_coeffs == nullptr)
	{
		throw 0;

	}
	if (q.a_coeffs == nullptr)
	{
		throw 0;
	}


		poly_t tmp{nullptr, 0};
	{
		if (p.degree > q.degree)
		{
			tmp.degree = p.degree;
		}
		else
		{
			tmp.degree = q.degree;
		}

			tmp.a_coeffs = new double [tmp.degree+1];
			
			for (unsigned int i = 0; i < tmp.degree+1 ; i++)
			{
				tmp.a_coeffs[i] = 0;
			}

			for (unsigned int j = 0; j < p.degree+1; j++)
			{
				tmp.a_coeffs[j] = p.a_coeffs[j];
			}
			for (unsigned int k = 0; k < q.degree+1; k++)
			{
				tmp.a_coeffs[k] = tmp.a_coeffs[k]+ q.a_coeffs[k];
			}
		

		std::cout <<" add " << tmp.a_coeffs << std::endl;
		
		delete []p.a_coeffs;      //[]p.a_coeffs
		p.a_coeffs= tmp.a_coeffs;
		p.degree = tmp.degree;

	}
	
}
	void poly_subtract( poly_t &p, poly_t const &q )
{

	if (p.a_coeffs == nullptr)
	{
		throw 0;

	}
	if (q.a_coeffs == nullptr)
	{
		throw 0;
	}
	else
	{
		poly_t tmp{nullptr, 0};
	
	
	{
		if (p.degree > q.degree)
		{
			tmp.degree = p.degree;
		}
		else
		{
			tmp.degree = q.degree;
		}

			tmp.a_coeffs = new double [tmp.degree+1];
			
			for (unsigned int i = 0; i < tmp.degree+1 ; i++)
			{
				tmp.a_coeffs[i] = 0;
			}

			for (unsigned int j = 0; j < p.degree+1; j++)
			{
				tmp.a_coeffs[j] = p.a_coeffs[j];
			}
			for (unsigned int k = 0; k < q.degree+1; k++)
			{
				tmp.a_coeffs[k] = tmp.a_coeffs[k]- q.a_coeffs[k];
			}


		std::cout << " Subtract " << tmp.a_coeffs << std::endl;

		delete[] p.a_coeffs;
		p.a_coeffs = tmp.a_coeffs;
		p.degree = tmp.degree;

		}
	}
}
	void poly_multiply( poly_t &p, poly_t const &q )
{
	double arr[0];
	poly_t tmp{nullptr, 0};
	if (p.a_coeffs == nullptr)
	{
		throw 0;

	}
	if (q.a_coeffs[p.degree] == 0)
	{
		double array[1]{0};
		delete[]p.a_coeffs;
		p.a_coeffs = array;
	}
	else
	{
		tmp.degree = p.degree + q.degree;
	 	tmp.a_coeffs =  new double [tmp.degree+1];
	 {

		for (unsigned int i = 0; i < tmp.degree+1 ; i++)
		{
			tmp.a_coeffs[i] = 0;
		}
		for (unsigned int j = 0; j < q.degree+1;  j++)
		{
			for (unsigned int k =0; j < q.degree+1; j++)
			{
			
			tmp.a_coeffs[j+k] = tmp.a_coeffs[j] * q.a_coeffs[j] + tmp.a_coeffs[j+k]; 
		}
		}

	}

	std::cout <<" multiply" << tmp.a_coeffs[0] << std::endl; 

	delete[] p.a_coeffs;
	p.a_coeffs = tmp.a_coeffs;
	p.degree = tmp.degree;

}

}
	double poly_divide( poly_t &p, double r )
{

	if (p.a_coeffs == nullptr)
	{
		throw 0;
	}
	else if(p.degree == 0)
	{
		double arr{p.a_coeffs[0]};
		p.a_coeffs[0] = 0.0;

		return arr;

	}


	else{
	poly_t tmp {nullptr, 0};
	tmp.degree = p.degree -1;
	tmp.a_coeffs = new double [tmp.degree +1];
	double a  = p.a_coeffs[p.degree];
	double digit{0};
	for (unsigned int i= p.degree; i >= 1; i--)
	{
		tmp.a_coeffs[i-1] = a;
		digit = a*r;
		a= digit + p.a_coeffs[i-1];
	}

	delete [] p.a_coeffs;
	p.a_coeffs = tmp.a_coeffs;
	p.degree = tmp.degree;

	return a;
}
}
	void poly_diff( poly_t &p )
{
	if (p.a_coeffs == nullptr)
	{
		throw 0;
	}

	poly_t tmp {nullptr, 0};
	tmp.degree = p.degree -1;
	tmp.a_coeffs =  new double [tmp.degree+1];
	double a = p.a_coeffs[p.degree];
	for (unsigned int i = 1; i <= p.degree; i++)
	{
		tmp.a_coeffs[i-1]= p.a_coeffs[i]*i;
	}

	delete [] p.a_coeffs;
	p.a_coeffs = tmp.a_coeffs;
	p.degree = tmp.degree;



}
	double poly_approx_int( poly_t const &p, double a, double b, unsigned int n )
{
	 if (p.a_coeffs == nullptr)
	 {
	 	throw 0;
	 }
	 else
{
	 poly_t tmp{nullptr, 0};
	 double h{(b-a)/n};
	 double arr{0};
	 double sum{0};
	 for (unsigned int i = 1; i <= n-1 ; i++)
	{
		arr += 2* poly_val(p, a+i*h);

	}
	
	double extra{n*h};

	std::cout << "integral " << ((h/2)*poly_val(p,a)) + arr + poly_val(p, a+extra) << std::endl;

	return ((h/2)*poly_val(p, a)) + arr + poly_val(p, a+extra); 
}

}
	

#ifndef MARMOSET_TESTING
 
 int main()
 {

 	poly_t my_poly{nullptr, 0};
 	unsigned int test_degree{4};
 	double a_test[3] {1, 1, 1};
 	poly_t p_test{nullptr, 0};
 	poly_t q_test{nullptr, 0};
 	double test[1] {0};
 	init_poly(p_test, a_test, test_degree);
 	init_poly(q_test, test, 0);
 	poly_degree(p_test);
 	poly_coeff(p_test, test_degree);
 	poly_val( p_test, 5);
 	poly_approx_int(p_test, 1, 1, 99999999);
 	poly_multiply(p_test, q_test );
 	destroy_poly(p_test);

 	return 0;
 }
#endif
