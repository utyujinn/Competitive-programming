#include<iostream>
using namespace std;

int main(){
	long n;
	cin >> n;
	vector<long> a(n);
	vector<bool> isodd(n, false);
	vector<int> div(n,0);

	for(int i =0; i < n; i++){
		cin >> a[i];
		if(a[i]%2){
			isodd[i] = true;
			a[i]--;
			int cnt = 0;
			while(a[i]%2!=0){
				a[i] --;
				a[i] /= 2;
				cnt ++;
			}
			div[i] = cnt;
		}else{
			int cnt = 0;
			while(a[i]%2==0){
				a[i] /= 2;
				cnt ++;
			}
			div[i] = cnt;
		}
	}
}
