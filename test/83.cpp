#include<iostream>
#include<vector>

using namespace std;

int main(){
	long n,m;
	cin >> n >> m;
	vector<long> p(m);
	vector<long> list(n+1,0);
	for(int i = 0; i < m; i++){
		cin >> p[i];
		if(i > 0){
			if(p[i] > p[i-1]){
				list[p[i-1]]++;
				list[p[i]]--;
			}else{
				list[p[i-1]]--;
				list[p[i]]++;
			}
		}
	}
	long ans = 0;
	long cnt = 0;
	for(int i = 1; i < n; i++){
		cnt += list[i];
		long a,b,c;
		cin >> a >> b >> c;
		ans += a*cnt<b*cnt+c?a*cnt:b*cnt+c;
	}
	cout << ans << endl;
}
