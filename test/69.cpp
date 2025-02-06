#include<iostream>
#include<vector>
using namespace std;

int main(){
	int q;
	cin >> q;
	vector<int> list(100001, 0);
	vector<int> sum(100001, 0);
	vector<int> pl(0);
	list[2] = 1;
	pl.push_back(2);
	int i = 3;
	while(i<=100001){
		int flag = 1;
		for(auto p : pl){
			if(p*p > 100000)break;
			if(i%p==0){
				flag = 0;
				break;
			}
		}
		if(flag){
			pl.push_back(i);
			list[i] = 1;
		}
		i+=2;
	}
	for(int i = 1; i < 100000; i++){
		if(list[i] == 1 && list[(i+1)/2]==1)sum[i] = sum[i-1] + 1;
		else sum[i] = sum[i-1];
	}
	for(int i = 0; i < q; i++){
		int l,r;
		cin >> l >> r;
		cout << sum[r] - sum[l-1] << endl;
	}
}
