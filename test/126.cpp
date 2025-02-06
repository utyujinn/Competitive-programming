#include<iostream>
#include<vector>
using namespace std;
int l=0,r=0;

bool nibu(int c,int cnt,vector<vector<int>> G, vector<int> color){
	cnt ^= 1;
	for(int next: G[c]){
		if(color[next] == -1){
			color[next] = cnt;
			nibu(next,cnt,G,color);
		}else if(color[next] ^ color[c] == 0){
			return false;
		}else {



}


int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	int a,b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> color(n,-1);
	color[0] = 0;
	if(nibu(0,G,color)){
		cout << l*r-m << endl;
	}else{
		

