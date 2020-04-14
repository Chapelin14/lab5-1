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

double simpson(double A, double eps) {
	double a, b;
	a = A;
	b = 1.5;
	double I=eps+1, I1=0;
	for (int N=2; (N<=4) || (fabs(I1-I)>eps); N*=2){
		double h, sum2=0, sum4=0, sum=0;
		h=(b-a)/(2*N);
		for(int i=1; i<=2*N-1;i+=2){
			sum4+=f(a+h*i);
			sum2+=f(a+h*(i+1));
			}
		sum=f(a)+4*sum4+2*sum2-f(b);
		I=I1;
		I1=(h/3)*sum;
		}
	return abs(I1);
}

double pryam(double A) {
	double b = 1.5;
	double a = A;
	cout << "Enter the count of rectangle  >=100): ";
	int n;
	cin >> n;
	double s = (f(a)+f(b))/2;
	double h=(b-a)/n;
	for(int i = 1; i<=n-1; i++){
		s+=f(a+i*h);
	}
	double l=h*s;
	cout<< "I (Rectangles ," << n << ") = " << l <<endl;
	return l;
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
	double A = pow(0.0004,0.25);
	cout << "A= " << A << endl;
	cout << "I (Simpson, e = 0.0001) = " << simpson(A, 0.0001) << endl;
	ofstream fout;
	fout.open("ans1.dat");
	fout << simpson(A, 0.0001);
	fout.close();
	fout.open("ans2.dat");
	fout << pryam(A);
	fout.close();
	return 0;
	}
