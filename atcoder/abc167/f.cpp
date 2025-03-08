#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int A[1<<20],B[1<<20];

int main(){
	int N;cin>>N;
	set<int> gr;
	bool flag2=false;
	for(int i=0;i<N;i++){
		string S;cin>>S;
		vector<int> list(S.size());
		for(int j=0;j<S.size();j++){
			list[j]=S[j]-'(';
		}
		vector<int> st;
		for(int j=0;j<S.size();j++){
			if(list[j]==0)st.push_back(list[j]);
			else if(!st.empty()&&list[j]==1&&st.back()==0)st.pop_back();
			else st.push_back(list[j]);
		}
		auto it=st.begin();
		int a=0,b=0;
		while(*it==1&&it!=st.end()){
			a++;it++;
		}
		while(*it==0&&it!=st.end()){
			b++;it++;
		}
		A[i]=a;
		B[i]=b;
		if(gr.find(b)!=gr.end())flag2=true;
		gr.insert(a);
	}
	sort(A,A+N);
	sort(B,B+N);
	bool flag=true;
	for(int i=0;i<N;i++){
		if(A[i]!=B[i])flag=false;
	}
	if(flag&&flag2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
