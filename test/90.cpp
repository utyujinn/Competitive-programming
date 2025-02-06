#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
	int n,m;
	double ans = 100000000;
	cin >> n >> m;
	vector<int> x(n),y(n),r(n);
	vector<int> xx(m), yy(m);
	for(int i = 0; i < n; i ++){
		cin >> x[i] >> y[i] >> r[i];
		ans = ans>r[i]?r[i]:ans;
	}
	for(int i = 0; i < m; i++){
		cin >> xx[i] >> yy[i];
		for(int j = 0; j < n; j++){
			double tmp = hypot(xx[i]-x[j],yy[i]-y[j]);
			tmp -= r[j];
			ans = ans>tmp?tmp:ans;
		}
		for(int j = 0; j < i; j++){
			double tmp = hypot(xx[i]-xx[j], yy[i]-yy[j]);
			tmp/=2;
			ans = ans>tmp?tmp:ans;
		}
	}
	cout << fixed << setprecision(12) << ans << endl;
}
	
