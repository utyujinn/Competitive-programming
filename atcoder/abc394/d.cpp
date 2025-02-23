#include<iostream>
#include<stack>
using namespace std;

int main(){
	string s;
	cin>>s;
	stack<char> st;
	for(int i=0;i<s.size();i++){
		if(s[i]==')'){
			if(st.empty()){
				cout<<"No"<<endl;
				return 0;
			}
			if(st.top()=='('){
				st.pop();
			}else{
				st.push(s[i]);
			}
		}else if(s[i]=='>'){
			if(st.empty()){
				cout<<"No"<<endl;
				return 0;
			}
			if(st.top()=='<'){
				st.pop();
			}else{
				st.push(s[i]);
			}
		}else if(s[i]==']'){
			if(st.empty()){
				cout<<"No"<<endl;
				return 0;
			}
			if(st.top()=='['){
				st.pop();
			}else{
				st.push(s[i]);
			}
		}
		else{
			st.push(s[i]);
		}
	}
	if(!st.empty()){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
}
