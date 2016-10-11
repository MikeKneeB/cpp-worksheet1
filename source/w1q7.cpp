#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int count = 0;
int w = 15;

double Function(double Input_Value){
	return (Input_Value*Input_Value*Input_Value + 
			7*Input_Value*Input_Value -
			6*Input_Value +
			15);
}

double D_Function(double Input_Value){
	return (3*Input_Value*Input_Value +
			14*Input_Value -
			6);
}

double Bisection(double Lower_Bound, double Upper_Bound, double Precision){
	
	cout << setw(w) << count << setw(w) << (Upper_Bound - Lower_Bound)/2 << setw(w) << (Upper_Bound + Lower_Bound)/2 << endl;

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

double Newton_Raphson(double x, double Precision){
	
	double result = x - Function(x)/D_Function(x);

	cout << setw(w) << count << setw(w) << abs(result - x) << setw(w) << x << endl;

	if (abs(result - x) < Precision){
		return result;
	}
	else {
		count++;
		return Newton_Raphson(result, Precision);
	}
}

int main(){

	cout.precision(6);
	cout << "Bisection Method:" << endl;
	cout << left << setw(w) << "Iteration" << setw(w) << "Precision" << setw(w) << "X" << endl;
	Bisection(-100, 100, 0.00001);

	count = 0;

	cout << endl << "Newton-Raphson Method 1:" << endl;
	cout << left << setw(w) << "Iteration" << setw(w) << "Precision" << setw(w) << "X" << endl;
	Newton_Raphson(0, 0.00001);

	count = 0;

	cout << endl << "Newton-Raphson Method 2:" << endl;
	cout << left << setw(w) << "Iteration" << setw(w) << "Precision" << setw(w) << "X" << endl;
	Newton_Raphson(10, 0.00001);

	return 0;
}
