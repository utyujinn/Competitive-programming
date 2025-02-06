#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long> a(n);
	vector<long> d(30);
	for(int i =0; i< n; i++)
		cin >> a[i];

	for(int k = 0; k < 30; k++){
		long div = 1 << k;
		vector<int> mp(div,0);//cnt
		vector<long> mp2(div,0);//sum
		for(long i = 0; i < n; i++){
			mp[(div-a[i]%div)%div] += 1;
			mp2[(div-a[i]%div)%div] += a[i];
			d[k] += mp[a[i]%div] * a[i] + mp2[a[i]%div];
		}
		if(d[k] == 0)break;
	}

	long ans = 0;
	for(int k = 0; k < 29; k++){
		ans += (d[k] - d[k+1]) / (1<<k);
		//cout << d[k] << endl;
	}
	cout << ans << endl;
}
