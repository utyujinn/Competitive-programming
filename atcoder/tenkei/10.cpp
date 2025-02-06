#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> f(n+1);
	vector<int> s(n+1);
	int pf = 0, ps = 0;
	for(int i = 1; i <= n; i++){
		int c,p;
		cin >> c >> p;
		if(c==1){
			f[i] = p + pf;
			s[i] = ps;
		}else{
			f[i] = pf;
			s[i] = p+ps;
		}
		pf = f[i], ps = s[i];
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int l,r;
		cin >> l >> r;
		cout << f[r]-f[l-1] << " " << s[r]-s[l-1] << endl;
	}
}
