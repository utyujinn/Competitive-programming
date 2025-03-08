#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int mex[1<<17];

vector<int> divisor(int n){
	vector<int> ret;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(i*i==n)ret.push_back(i);
			else {
				ret.push_back(i);
				ret.push_back(n/i);
			}
		}
	}
	sort(ret.begin(),ret.end());
	return ret;
}

void create_mex(){
	for(int i=2;i<1<<17;i++){
		vector<int> list=divisor(i);
		set<int> st;
		for(int j=0;j<list.size()-1;j++){
			st.insert(mex[list[j]]);
		}
		auto it=st.begin();
		int cnt=0;
		while(*it==cnt&&it!=st.end()){
			it++,cnt++;
		}
		mex[i]=cnt;
	}
}

int main(){
	int N;
	cin>>N;
	int ans=0;
	create_mex();
	for(int i=0;i<N;i++){
		int a;cin>>a;
		ans^=mex[a];
	}
	if(ans!=0){
		cout<<"Anna"<<endl;
	}
	else{
		cout<<"Bruno"<<endl;
	}
}
