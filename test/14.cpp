#include<iostream>
#include<vector>

using namespace std;

int main(){
	long k,n;
	cin >> n >> k;
	vector<long> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	long ans = 1LL<<60;
	for(int i = 0; i < 1<<n; i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(1<<j & i)cnt++;
		}
		if(cnt != k)continue;

		long prev = -1;
		long tmp = 0;
		for(int j = 0; j < n; j++){
			if(1<<j & i){
				if(a[j] <= prev){
					tmp += prev-a[j]+1;
					prev ++;
				}else{
					prev = a[j];
				}
			}else{
				if(a[j] > prev)prev = a[j];
			}
		}
		ans = ans>tmp?tmp:ans;
	}
	cout << ans << endl;
}

	
