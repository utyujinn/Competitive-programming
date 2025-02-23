#include<iostream>
#include<vector>
using namespace std;

int main(){
	string s;cin>>s;
	vector<char> T;
	for(char c:s){
		if(c=='('||c=='<'||c=='[')T.push_back(c);
		else if(c==')'){
			if(!T.empty()&&T.back()=='(')T.pop_back();
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
		else if(c=='>'){
			if(!T.empty()&&T.back()=='<')T.pop_back();
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
		else if(c==']'){
			if(!T.empty()&&T.back()=='[')T.pop_back();
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	if(T.empty()){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
