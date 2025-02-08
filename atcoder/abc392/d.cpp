#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<vector<long double> > A(N);
	double ans=0;
	for(int i=0;i<N;i++){
		int K;
		cin>>K;
		for(;K--;){
			int a;
			cin>>a;
			A[i].push_back(a);
		}
		sort(A[i].begin(),A[i].end());
		for(int j=0;j<i;j++){
			double tmp=0;
			int a=0,b=0;
			while(true){
				if(A[i][a]<A[j][b]){
					a++;
				}
				else if(A[i][a]>A[j][b]){
					b++;
				}
				else if(A[i][a]==A[j][b]){
					int a2=0,b2=0;
					while(A[i][a+a2]==A[i][a]){
						a2++;
					}
					while(A[j][b+b2]==A[j][b]){
						b2++;
					}
					tmp+=(double)a2*b2*(1/(double(A[i].size())))/(double(A[j].size()));
					a+=a2;
					b+=b2;
				}
				if(a>=A[i].size() || b>=A[j].size())break;
			}
			ans=max(ans,tmp);
		}
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}
