#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<compare>
using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	multiset<int> a;
	vector<int> b;
	int c;
	int ma;
	for(int i = 0; i < n; i++){
		cin >> c;
		a.insert(c);
		ma = min(ma,c);
	}
	for(int j = 0; j < m; j++){
		cin >> c;
		auto it = a.find(c);
		if(it != a.end()){
			a.erase(it);
		}else{
			b.emplace_back(c);
		}
	}
	sort(b.rbegin(), b.rend());
	while(b.size()){
		int tmp = b.back();
		int tmp2 = tmp>>1;
		b.pop_back();
		if(tmp%2==0){
			auto it = a.find(tmp2);
			if(it != a.end()){
				a.erase(it);
			}
			else{
				b.emplace_back(tmp2);
			}
			it = a.find(tmp2);
			if(it != a.end()){
				a.erase(it);
			}
			else{
				b.emplace_back(tmp2);
			}
		}
		else{
			for(int i = 0; i < 2; i++){
				auto it = a.find(tmp2+i);
				if(it != a.end()){
					a.erase(it);
				}
				else{
					b.emplace_back(tmp2+i);
				}
			}
		}
		if(tmp2 < ma){
			cout << "No" << endl;
			return;
		}
		if(b.size()>a.size()){
			cout << "No" << endl;
			return;
		}
	}
	if(b.size()==0 && a.size()== 0){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	cin >> t;
	for(;t--;)solve();
}
