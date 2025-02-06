#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin >> n>>m;
	vector<vector<char>> s(n,vector<char>(n));
	vector<vector<char>> t(m,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>s[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>t[i][j];
		}
	}
	int a,b;
	for(int i=0;i<n-m+1;i++){
		for(int j=0;j<n-m+1;j++){
			int flag = 1;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(s[i+k][j+l]!=t[k][l]){
						flag=0;
						break;
					}
				}
			}
			if(flag==1){
				a=i;
				b=j;
			}
		}
	}
	a++,b++;
	cout << a << " " << b << endl;
}
