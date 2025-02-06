#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	int a,b,x;
	cin >> a >> b >> x;
	double theta;
	if(x>a*a*b/2.0){
		theta = atan((2.0*b-2.0*x/(a*a))/a);
	}else{
		theta = atan((a*b*b/(2.0*x)));
	}
	cout << fixed << setprecision(11) << (theta/M_PI)*180 << endl;
}

