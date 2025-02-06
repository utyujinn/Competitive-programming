#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,d;
	cin >> n >> d;
	vector<long> t(n),l(n);
	for(int i = 0;  i < n; i++){
		cin >> t[i] >> l[i] ;
	}
	for(int i = 1; i <= d; i++){
		long m = 0;
		for(int j = 0; j < n; j++){
			m = max(m, t[j]*(l[j]+i));
		}
		cout << m << endl;
	}
}
