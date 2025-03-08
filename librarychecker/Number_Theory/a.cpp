#include<iostream>
#include<vector>
using namespace std;

template<typename T>
vector<pair<T,T>> diviser(T n){
	vector<pair<T,T>> ret;
	T cnt = 0;
	while(n%2==0){
		n/=2;
		cnt++;
	}
	if(cnt)ret.emplace_back(2,cnt);
	for(T i = 3; i*i <= n; i+=2){
		T cnt = 0;
		while(n%i==0){
			n/=i;
			cnt++;
		}
		if(cnt)ret.emplace_back(i,cnt);
	}
	if(n>1)ret.emplace_back(n,1);
	return ret;
}

int solve(){
	long n;
	cin >> n;
	auto div = diviser(n);
	long sum = 0;
	for(auto c: div){
		sum += c.second;
	}
	cout << sum << " ";
	for(auto c: div){
		for(int i = 0; i < c.second; i++){
			cout << c.first << " ";
		}
	}
	cout << endl;
	return 0;
}

int main(){
	int t;
	cin >> t;
	for(;t--;){
		solve();
	}
}
