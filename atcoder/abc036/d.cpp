#include<iostream>
#include<vector>
using namespace std;

template<int mod>
struct ModInt{
	int val;
	ModInt():val(0){}
	ModInt(long long x):val(x>=0?x%mod:(mod-(-x)%mod)%mod){}
	ModInt &operator+=(const ModInt &p){
		if((val+=p.val)>=mod){
			val-=mod;
		}
		return *this;
	}
	ModInt &operator-=(const ModInt &p){
		if((val+=mod-p.val)>=mod){
			val-=mod;
		}
		return *this;
	}
	ModInt &operator*=(const ModInt &p){
		val=(int)(1LL*val*p.val%mod);
		return *this;
	}
	ModInt &operator/=(const ModInt &p){
		*this *= p.inverse();
		return *this;
	}
	ModInt operator-() const { return ModInt(-val);}
	ModInt operator+(const ModInt &p) const{return ModInt(*this)+=p;}
	ModInt operator*(const ModInt &p) const{return ModInt(*this)*=p;}
	ModInt operator/(const ModInt &p) const{return ModInt(*this)/=p;}
	bool operator==(const ModInt &p)const{return val==p.val;}
	bool operator!=(const ModInt &p)const{return val!=p.val;}
	ModInt inverse() const{
		int a=val, b=mod, u=1,v=0,t;
		while(b>0){
			t=a/b;
			swap(a-=t*b,b);
			swap(u-=t*v,v);
		}
		return ModInt(u);
	}
	ModInt pow(long long n)const{
		ModInt ret(1), mul(val);
		while(n>0){
			if(n&1)ret*=mul;
			mul*=mul;
			n>>=1;
		}
		return ret;
	}
	friend ostream &operator<<(ostream &os, const ModInt &p) {return os<<p.val;}
	friend istream &operator>>(istream &is, ModInt &a){
		long long t;
		is>>t;
		a=ModInt<mod>(t);
		return (is);
	}
	int get_mod(){return mod;}
};
const int MOD = 1000000007;
using modint = ModInt<MOD>;

bool seen[100000];
pair<modint,modint> dfs(vector<vector<int>>& G, int v){
	seen[v]=true;
	vector<pair<modint, modint>> next;
	for(auto n: G[v]){
		if(!seen[n])next.push_back(dfs(G,n));
	}
	if(next.size()==0){
		return make_pair(modint(1),modint(1));
	}
	else{
		pair<modint, modint> tmp(modint(1), modint(1));
		for(auto n: next){
			tmp.first*=(n.first+n.second);
			tmp.second*=n.first;
		}
		return tmp;
	}
}

int main(){
	int N;
	cin>>N;
	vector<vector<int>> G(N);
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	pair<modint,modint> ans=dfs(G,0);
	cout<<ans.first+ans.second<<endl;
}
