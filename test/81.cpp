#include<iostream>
#include<vector>

using namespace std;

int main(){
	long n;
	cin >> n;
	vector<int> list(1000001,0);
	for(int i = 0; i < n; i++){
		long a,b;
		cin >> a >> b;
		list[a]++;
		if(b != 1000001)list[b+1]--;
	}

	long cnt = 0;
	long ans = 0;
	for(int i = 0; i < 1000001; i++){
		cnt += list[i];
		ans = ans<cnt?cnt:ans;
	}
	cout << ans << endl;
}
