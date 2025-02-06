#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double f(double p, double x){
	return x + p*pow(2,(-x/1.5));
}

int main(){
	double p; 
	cin >> p;
	double a = 0, b = p;
	while(b-a > 0.000000001){
		double c1 = a*2/3 + b/3;
		double c2 = a/3 + b*2/3;
		if(f(p,c1) < f(p,c2))b = c2;
		else a = c1;
	}
	cout << fixed << setprecision(12) << f(p, a) << endl;
}
