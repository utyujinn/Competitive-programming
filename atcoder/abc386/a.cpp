#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	set<int> st;
	st.insert(a);
	st.insert(b);
	st.insert(c);
	st.insert(d);
	if(st.size()==2)cout << "Yes" << endl;
	else cout << "No" << endl;

}
