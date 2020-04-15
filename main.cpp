#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
double f(double x){
	return exp(-pow(1/x,2))/(pow(x,2));
}

double g(double x){
	return pow(x,3);
}

double Simpson(double a, double b, double h)
{
	double sum = f(a) + f(b);
	double x;
	int i = 1;
	for(x = a + h; x < b - h; x += h){
		if(i%2 != 0)
			sum += 4*f(x);
		else
			sum += 2*f(x);
		i++;
	}
	return h*sum/3.;
}

double rectangles(double a, double b, double h)
{
	double sum = 0;
	double x;
	for(x = a + h * 0.5; x < b; x += h)
		sum += f(x);
	sum *= h;
	return sum;
}

int main(){
	cout << "Analise" << endl;
	double x;
	int check;
	for( double i = 0.01; i<=1.5; i+=0.1){
		x = i;
		cout << f(x) << " " << g(x);
		if(g(x) >= f(x)){
			cout << "Fine!" << endl;
			check = 1;
		}else{
			cout << endl;
			break;
		}
	}
	double a = pow(0.0004,0.25);
	cout << "A= " << a << endl;
	double b = 1.5; 
    double h = 0.00005;
	double errrect;
		do {
		double rect = rectangles(a, b, h);
		
		h /= 2;
		
		double divrect = rectangles(a, b, h); 
		
		errrect = abs(rect - divrect)/4.;
	} while (errrect > 1e-4);
	ofstream outf;
    outf.open("ans1.dat", ios_base::out);
	outf << "Integral = " << rectangles(a, b, h) << " " <<"Error = " << errrect << "\n";
	outf.close();
	
	do {
		double simp = Simpson(a, b, h);
		
		h /= 2;
		
		double divsimp = Simpson(a, b, h); 
		
		errrect = abs(simp - divsimp)/12.;
	} while (errrect > 1e-5);
	outf.open("ans2.dat", ios_base::out);
	outf << "Integral = " << Simpson(a, b, h) << " " <<"Error = " << errrect << "\n";
    outf.close();
	return 0;
}
