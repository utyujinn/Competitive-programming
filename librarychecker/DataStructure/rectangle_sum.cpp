#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int x[2<<17],y[2<<17],w[2<<17];
int list[2<<17][2<<17];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin>>N>>Q;
	vector<int> cx,cy;
	for(int i=0;i<N;i++){
		cin>>x[i]>>y[i]>>w[i];
		cx.push_back(x[i]);
		cy.push_back(y[i]);
	}
	cx.erase(unique(cx.begin(),cx.end()),cx.end());
	cy.erase(unique(cy.begin(),cy.end()),cy.end());
	vector<vector<long>> list(cx.size(),vector<long>(cy.size()));
	for(int i=0;i<N;i++){
		x[i]=lower_bound(cx.begin(),cx.end(),x[i])-cx.begin();
		y[i]=lower_bound(cy.begin(),cy.end(),y[i])-cy.begin();
		list[x[i]+1][y[i]+1]+=w[i];
	}
	for(int i=0;i<cx.size()+1;i++){
		for(int j=0;j<cy.size()+1;j++){
			list[i][j]=list[i-1][j]+list[i][j-1]+list[i][j]-list[i-1][j-1];
		}
	}
	for(;Q--;){
		int x0,y0,x1,y1;
		cin>>x0>>y0>>x1>>y1;
		x0=lower_bound(cx.begin(),cx.end(),x0)-cx.begin()+1;
		y0=lower_bound(cy.begin(),cy.end(),y0)-cy.begin()+1;
		x1=lower_bound(cx.begin(),cx.end(),x1+1)-cx.begin()+1;
		y1=lower_bound(cy.begin(),cy.end(),y1+1)-cy.begin()+1;
		cout<<list[x1][y1]+list[x0-1][y0-1]-list[x1][y0-1]-list[x0-1][y1]<<"\n";
	}
}
