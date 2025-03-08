#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool isprime[2<<20]={true};

int main(){
	long N;
	cin>>N;
	for(long i=0;i*i*4<=N;i++){
		isprime[i]=true;
	}
	set<int> pr;
	for(long i=2;i*i*4<=N;i++){
		if(isprime[i]){
			pr.insert(i);
			for(long j=i+i;j*j*4<=N;j+=i){
				isprime[j]=false;
			}
		}
	}
	vector<long> list;
	int ans=0;
	for(int a:pr){
		list.push_back(a);
	}
	for(int i=0;i<list.size();i++){
		long cnt=1;
		bool flag=true;
		for(int j=0;j<8;j++){
			cnt*=list[i];
			if(cnt>N){
				flag=false;
			}
		}
		if(flag)ans++;
		for(int j=i+1;j<list.size();j++){
			long cnt=1;
			bool flag=true;
			for(int k=0;k<2;k++){
				cnt*=list[i];
				if(cnt>N)flag=false;
				cnt*=list[j];
				if(cnt>N)flag=false;
			}
			if(flag)ans++;
			else{
				break;
			}
		}
	}
	cout<<ans<<endl;
}
