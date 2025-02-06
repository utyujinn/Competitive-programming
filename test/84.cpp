#include<iostream>
#include<vector>
using namespace std;

int n;
void print(vector<vector<int>> &list){
	for(int i = 1; i <=n+2; i ++){
		for(int j = 1; j<=i+1; j++){
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int m;
	cin >> n >> m;
	vector<vector<int>> list(n+4, vector<int>(n+4,0));
	for(;m--;){
		int a,b,x;
		cin >> a >> b >> x;
		list[a][b]++;
		list[a][b+1]--;
		list[a+x+1][b]--;
		list[a+x+2][b+1]++;
		list[a+x+1][b+x+2]++;
		list[a+x+2][b+x+2]--;
	}
	long ans = 0;
	//print(list);
	for(int i = 1; i <= n+3; i++){
		for(int j = 1; j <= i; j++){
			list[i][j] += list[i][j-1];
		}
	}
	//print(list);
	for(int i = 1; i <= n+3; i++){
		for(int j = 1; i+j <= n+3; j++){
			list[i+j][i] += list[i+j-1][i];
		}
	}
	//print(list);
	for(int i = 1; i <= n+3; i++){
		for(int j = 0; i+j <= n+3; j++){
			list[i+j][j+1] += list[i+j-1][j];
		}
	}
	//print(list);
	for(int i = 1; i <=n; i ++){
		for(int j = 1; j<=i; j++){
			if(list[i][j] != 0)ans++;
		}
	}
	cout << ans << endl;
}
