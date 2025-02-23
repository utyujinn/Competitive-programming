#include<iostream>
using namespace std;
string C[100];

struct edge{
	int to;
	char c;
}
vector<edge> G[100100];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>C[i];
		for(int j=0;j<N;j++){
			if(C[i][j]!='-'){
				edge tmp;
				tmp.to=j;
				tmp.c=C[i][j];
				G[i].push_back(tmp);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(C[i][j]!='
}
