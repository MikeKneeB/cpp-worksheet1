#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int count = 0;
int w = 15;
ofstream bisect, nrone, nrtwo;

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
	
	bisect << count << "," << (Upper_Bound - Lower_Bound)/2 << "," << (Upper_Bound + Lower_Bound)/2 << endl;

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

double Newton_Raphson(double x, double Precision, ofstream & output){
	
	double result = x - Function(x)/D_Function(x);

	output << count << "," << abs(result - x) << "," << result << endl;

	if (abs(result - x) < Precision){
		return result;
	}
	else {
		count++;
		return Newton_Raphson(result, Precision, output);
	}
}

double Newton_Raphson2(double x, double Precision, ofstream & output){

	int count = 0;

	double result = x - Function(X)/D_Function(x);
	double result_next = result - Function(result)/D_Function(result);
	
	output << count << "," << result << "," << abs(result - x) << endl;  

	do {
		count++;
		output << count << "," << result_next << "," << abs(result_next - result) << endl;
		result = result_next;
		result_next = result - Function(result)/D_Function(result);
	} while (abs(result - result_next) < Precision);

}

int main(){

	bisect.precision(6);
	bisect.open("bisection.csv");
	Bisection(-100, 100, 0.00001);

	count = 0;

	nrone.precision(6);
	nrone.open("newtonraphson2.csv");
	Newton_Raphson(-10, 0.00001, nrone);

	count = 0;

	nrtwo.precision(6);
	nrtwo.open("newtonraphson1.csv");
	Newton_Raphson(10, 0.00001, nrtwo);

	bisect.close();
	nrone.close();
	nrtwo.close();

	return 0;
}
