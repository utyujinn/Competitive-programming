#include<iostream>
using namespace std;

long p[200000],I[200000],Iinv[200000];
long R[200000],L[200000];

bool solve(int pl, int pr, int il, int ir){
	long sep = Iinv[p[pl]] - il;
	cout << sep << endl;
	if(pr-pl==0){
		return true;
	}
	if(pr-pl==1){
		if(p[pl] == I[il])return true;
	}
	if(!solve(pl+1,pl+1+sep,il,il+sep)){
		return false;
	}
	if(!solve(pl+2+sep,pr,il+sep+1,ir)){
		return false;
	}
}

int main(){
	long n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i] >> I[i];
		p[i]--,I[i]--;
		Iinv[I[i]] = i;
	}
	if(!solve(0,n,0,n)){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		cout << L[i] << " " << R[i] << endl;
	}
}
