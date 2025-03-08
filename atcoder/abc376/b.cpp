#include<iostream>
using namespace std;

int main(){
	int N,Q;
	cin>>N>>Q;
	int l=0,r=1;
	long ans=0;
	for(;Q--;){
		char H;
		int T;
		cin>>H>>T;
		T--;
		if(H=='R'){
			int tmp=0;
			int ir=r;
			while(r!=T){
				r++;
				tmp++;
				if(r==N)r=0;
				if(r==l){
					tmp=-1;
					break;
				}
			}
			if(tmp==-1){
				r=ir;
				tmp=0;
				while(r!=T){
					r--;
					tmp++;
					if(r==-1)r=N-1;
				}
			}
			ans+=tmp;
		}else{
			int tmp=0;
			int il=l;
			while(l!=T){
				l++;
				tmp++;
				if(l==N)l=0;
				if(r==l){
					tmp=-1;
					break;
				}
			}
			if(tmp==-1){
				l=il;
				tmp=0;
				while(l!=T){
					l--;
					tmp++;
					if(l==-1)l=N-1;
				}
			}
			ans+=tmp;
		}
	}
	cout<<ans<<endl;
}
