#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
	long m,n;
	cin >> m;
	vector<long> x(m),y(m);
	for(int i = 0; i < m; i++){
		cin >> x[i] >> y[i];
	}
	cin >> n;
	vector<long> xx(n),yy(n);
	set<pair<long,long>> st;
	for(int i = 0; i < n; i++){
		cin >> xx[i] >> yy[i];
		st.emplace(xx[i],yy[i]);
	}
	for(int i = 0; i < n; i++){
		bool flag = true;
		long dx = xx[i] - x[0], dy = yy[i] - y[0];
		for(int j = 0; j < m; j++){
			if(!st.count({x[j] + dx, y[j] + dy})){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << dx << " " << dy << endl;
			break;
		}
	}
}

