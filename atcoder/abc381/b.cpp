#include<iostream>
#include<vector>
using namespace std;

int main(){
	string s;
	cin>>s;
	vector<int> list(26);
	int flag = 1;
	if(s.size()%2==1)flag=0;
	for(int i=0;i<s.size();i++){
		list[s[i]-'a'] ++;
		if(s[i]!=s[i+1] && i%2==0)flag=0;
	}
	for(int i=0;i<26;i++){
		if(!(list[i]==2||list[i]==0))flag=0;
	}
	cout<<(flag?"Yes":"No")<<endl;
}
