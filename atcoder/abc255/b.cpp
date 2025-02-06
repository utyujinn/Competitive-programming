#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

double dist(long a, long b, vector<long> x, vector<long> y){
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main(){
	long n,k;
	cin >> n >> k;
	vector<long> a(k),x(n),y(n);
	vector<long> have(n,0);
	double ans = 0;
	for(long i = 0; i < k; i++){
		cin >> a[i];
		a[i]--;
		have[a[i]] = 1;
	}
	for(long i = 0; i < n; i++)cin >> x[i] >> y[i];

	for(long i = 0; i < n; i++){
		if(have[i])continue;
		double tmp = 1000000;
		for(long j = 0; j < n; j++){
			if(i != j){
				double distance = dist(i,j,x,y);
				if(distance < tmp && have[j])tmp = distance;
			}
		}
		ans = (tmp>ans)?tmp:ans;
	}
	cout << fixed << setprecision(12) << ans << endl;
}


