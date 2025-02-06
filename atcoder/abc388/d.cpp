#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long> a(n+1);
	vector<long> imos(n+1);
	long cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt += imos[i];
		a[i] += cnt;
		long give =  n - i;
		if(a[i] >= give){
			a[i] -= give;
		}else{
			give = a[i];
			a[i] = 0;
		}
		imos[i+1] ++;
		imos[i+give+1] --;
	}
	for(int i = 1; i < n; i++){
		cout << a[i] << " ";
	}
	cout << a[n] << endl;
}
