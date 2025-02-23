#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int X,Y,A,B,C;
	cin>>X>>Y>>A>>B>>C;
	vector<int> p(A),q(B),r(C);
	for(int i=0;i<A;i++){
		cin>>p[i];
	}
	for(int i=0;i<B;i++){
		cin>>q[i];
	}
	for(int i=0;i<C;i++){
		cin>>r[i];
	}
	sort(p.rbegin(),p.rend());
	sort(q.rbegin(),q.rend());
	sort(r.rbegin(),r.rend());
	long ans=0;
	p.resize(X);
	q.resize(Y);
	for(int i=0;i<X;i++){
		ans+=p[i];
	}
	for(int i=0;i<Y;i++){
		ans+=q[i];
	}
	reverse(p.begin(),p.end());
	reverse(q.begin(),q.end());
	int aid=0,bid=0,cid=0;
	while(true){
		if((p[aid]<q[bid] || bid==Y)&&aid!=X){
			if(p[aid]<r[cid]){
				ans-=p[aid++];
				ans+=r[cid++];
			}else{
				break;
			}
		}
		else{
			if(q[bid]<r[cid]){
				ans-=q[bid++];
				ans+=r[cid++];
			}else{
				break;
			}
		}
		if(aid==X&&bid==Y)break;
	}
	cout<<ans<<endl;
}
