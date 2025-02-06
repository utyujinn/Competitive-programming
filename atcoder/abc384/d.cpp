#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
	long n,s;
	cin >> n >> s;
	vector<long> a(n); 
	long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 0; i < n; i++){
		a.emplace_back(a[i]);
	}

	if(s > sum)s %= sum;
	int l = 0, r = 0;
	long cur_sum = a[0];
	while(1){
		if(cur_sum == s){
			cout << "Yes" << endl;
			return 0;
		}
		else if(cur_sum < s && r < 2*n-1){
			r++;
			cur_sum += a[r];
		}else{
			cur_sum -= a[l];
			l++;
		}
		if(l == 2*n)break;
	}
	cout << "No" << endl;
}

