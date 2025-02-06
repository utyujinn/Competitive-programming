#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Square{
	int w,h;
};

void solve(int n, int w, int h){
	vector<Square> list(1,{w,h});
	for(int i = 0; i < n; i++){
		int p,s;
		cin >> p >> s;
		p--;
		s %= (list[p].w+list[p].h);
		//cout << s << endl;
		Square sq;
		if(0 <= s && s <= list[p].w){
			int tmp = list[p].w;
			//list[p].w = min(s, tmp-s);
			sq.w = min(s, tmp-s);
			sq.h = list[p].h;
			list.push_back({max(s,tmp-s), list[p].h});
		}
		else{
			int tmp = list[p].h;
			sq.w = list[p].w;
			sq.h = min(s-list[p].w, tmp-(s-list[p].w));
			//list[p].h = min(s-list[p].w, tmp-(s-list[p].w));
			list.push_back({list[p].w, max(s-list[p].w, tmp-(s-list[p].w))});
		}
		for(;p<i;p++){
			list[p] = list[p+1];
		}
		list[i] = sq;
		//cout <<list[p].w << " " << list[p].h << " " << list[i+1].w << " " << list[i+1].h << endl;
	}
	vector<int> area(n+1);
	for(int i = 0; i < n+1; i++){
		area[i] = list[i].w*list[i].h;
	}
	sort(area.begin(), area.end());
	for(int i = 0; i < n; i++){
		cout << area[i] << " ";
	}
	cout << area[n] << endl;
}

int main(){
	int n,w,h;
	cin >> n >> w >> h;
	while(!(n==0 && w==0 && h==0)){
		solve(n,w,h);
		cin >> n >> w >> h;
	}
}
