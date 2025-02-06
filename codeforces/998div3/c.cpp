#include<iostream>
#include<set>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(;t--;){
		int n,k;
		cin >> n >> k;
		multiset<int> list;
		int ans = 0;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			if(list.count(k-tmp)){
				ans++;
				auto it = list.find(k-tmp);
				list.erase(it);
			}else{
				list.insert(tmp);
			}
		}
		cout << ans << endl;
	}
}
