#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> list(n);
	int a;
	int x1=-1,x2 = -1, x3 = -1, x1i = 1e7, x2i = 1e7, x3i = 1e7,md1 = 1e7, md2 = 1e7, md3 = 1e7;
	int c1,d1,c2,d2,c3,d3;
	for(int i =0; i < n;i++){
		cin >> list[i];
	}
	sort(list.begin(), list.end());
	vector<int> diff(n-1);
	vector<int> x,xi;
	int flag = 4;
	for(int i = n-2; i >= 0; i--){
		diff[i] = list[i+1]-list[i];
		if(diff[i] == 0){
			x.push_back(list[i]);
			xi.push_back(i);
			i--;
		}
	}
	for(int i = n-2; i >= 0; i--){
		for(int j = 0; j < x.size(); j++){
			if(i > xi[j]+1 || i < xi[j]-1){
				if(diff[i] < x[j]*2){
					cout << list[i] << " " << list[i+1] << " " << x[j] << " " << x[j] << endl;
					return;
				}
			}
		}
	}
	for(int i = 0; i < x.size(); i++){
		if(xi[i]+2 < n){
			if((list[xi[i]+2]-list[xi[i]-1]) < x[i]*2){
				cout << list[xi[i]+2] << " " << list[xi[i]-1] <<" " << x[i] << " " << x[i] << endl;
				return ;
			}
		}
	}
	cout << -1 << endl;
}

int main(){
	int t;
	cin >> t;
	for(;t--;)solve();
}
