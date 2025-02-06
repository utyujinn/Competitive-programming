#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(;t--;){
		int n,m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int i = 0;  i< n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		vector<int> up(n/2+2);
		vector<int> down(m/2+2);
		for(int i = 1; i < n/2+1; i++){
			up[i] = a[n-i] - a[i-1] + up[i-1];
		}
		for(int i = 1; i < m/2+1; i++){
			down[i] = b[m-i] - b[i-1] + down[i-1];
		}

		int k = 0;
		if(n*2 < m)k = n;
		else if(m*2 < n)k = m;
		else k = (n+m)/3;
		cout << k << endl;
		for(int i = 1; i <= k; i++){
			int tmp = 0;
			for(int j = 0; j < k; j++){
				if(j*2+(i-j)<=n && j+(i-j)*2<=m){
					tmp = max(tmp, up[j] + down[i-j]);
				}
			}
			cout << tmp << " ";
		}
		cout << endl;
	}
}
