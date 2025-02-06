#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct leaf{
	set<int> left,right;
};

void re(vector<leaf> &G, int c){
	for(int next: G[c].left){
		re(G, next);
	}
	cout << c+1 << " ";
	for(int next: G[c].right){
		re(G,next);
	}
}

void solve(){
	int n;
	cin >> n;
	char c;
	vector<leaf> G(n);
	vector<int> pos(n);
	cin >> c;
	for(int i = 1; i < n; i++){
		cin >> c;
		if(c-'0'){
			G[0].right.insert(i);
			pos[i] = 1 + 0*2;
		}
		else{
			G[0].left.insert(i);
			pos[i] = 0 + 0*2;
		}
	}
	for(int i = 1; i < n; i++){
		int index = pos[i]/2;
		int rl = pos[i]%2;
		for(int j = 0; j < n; j++){
			cin >> c;
			if(j > i && ((rl && (G[index].right.count(j))))){
				if(c-'0'){
					G[i].right.insert(j);
					pos[j] = 1 + i*2;
				}
				else{
					G[i].left.insert(j);
					pos[j] = 0 + i*2;
				}
				G[index].right.erase(j);
			}else if(j > i && ((rl == 0 && G[index].left.count(j)))){
				if(c-'0'){
					G[i].right.insert(j);
					pos[j] = 1 + i*2;
				}
				else{
					G[i].left.insert(j);
					pos[j] = 0 + i*2;
				}
				G[index].left.erase(j);
			}
		}
	}
	re(G,0);
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	for(;t--;)solve();
}
