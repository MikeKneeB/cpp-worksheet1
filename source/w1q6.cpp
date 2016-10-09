#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PI 3.141592653589793

double m = 5.5, g = 9.81, k = 850, L = 0.6;
int count = 0;
int w = 15;

double Function(double Input_Value){
	return (tan(Input_Value) - sin(Input_Value) - (m*g)/(k*L));
}

double Bisection(double Lower_Bound, double Upper_Bound, double Precision){
	
	cout << setw(w) << count << setw(w) << Upper_Bound - Lower_Bound << setw(w) << (Upper_Bound + Lower_Bound)/2 << endl;

	if (Upper_Bound - Lower_Bound < Precision){
		return (Upper_Bound + Lower_Bound)/2;
	}
	else {
		double Middle = (Upper_Bound + Lower_Bound)/2;

		if (Function(Middle)*Function(Upper_Bound) < 0){
			count++;
			return Bisection(Middle, Upper_Bound, Precision);
		}
		else {
			count++;
			return Bisection(Lower_Bound, Middle, Precision);
		}
	}

}

int main(int argv, char ** argc){

	cout.precision(6);
	cout << left << setw(w) << "Iteration" << setw(w) << "Precision" << setw(w) << "Theta" << endl;
	Bisection(0, PI/2, 0.00001);
	return 0;

}
