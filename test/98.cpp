#include<iostream>
#include<vector>
using namespace std;

int main(){
	long n;
	cin >> n;
	long a;
	vector<long> list(n);
	long ans = 1;
	for(int i = 0; i < n; i++){
		cin >> a;
		list[a]++;
		if((a != 0 && (list[a] > list[a-1])) || list[a] > 3){
			cout << 0 << endl;
			return 0;
		}
		if(list[a] == 1){
			if(a == 0)ans=(3*ans)%1000000007;
			else if(list[a-1] == 3)ans=(3*ans)%1000000007;
			else if(list[a-1] == 2)ans=(2*ans)%1000000007;
		}
		if(list[a] == 2){
			if(a == 0)ans=(2*ans)%1000000007;
			else if(list[a-1] == 3)ans=(2*ans)%1000000007;
		}
		if(list[a] == 3){
		}
	}
	cout << ans << endl;
}
