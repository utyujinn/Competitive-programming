#include<iostream>
#include<vector>
using namespace std;

uint64_t pollard_rho(uint64_t n){
	if(n%2==0)return 2;
	const Montgomery m(n);
	constexpr uint64_t C1=1;
	constexpr uint64_t C2=2;
	constexpr uint64_t M=512;

	uint64_t Z1=1;
	uint64_t Z2=2;

retry:
	uint64_t z1 = Z1;

	

void factorize(uint64_t n, vector<uint64_t> &res){
	if(n<=1)return;
	if(isPrime(n)){
		res.push_back(n);
		return;
	}
	uint64_t p=pollard_rho(n);
	factorize(p,res);
	factorize(n/p,res);
}

vector<uint64_t> solve(uint64_t n){
	vector<uint64_t> res;
	factorize(n,res);
	sort(res.begin(),res.end());
	return res;
}

int main(){
	int t;
	cin>>t;
	for(;t--;){
		uint64_t n;
		cin >> n;
		vector<uint64_t> factors=solve(n);
		cout<<factors.size()<<endl[factors.empty()];
		for(int i=0;i<factors.size();i++){
			cout<<factors[i]<<endl[factors.size()==i+1];
		}
	}
	return 0;
}
