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
	static int get_mod(){return mod;}
};
const int MOD = 1000000007;
using modint = ModInt<MOD>;

template<class T>
struct Comb {
	vector<T> fact_, fact_inv_, inv_;
	Comb(int SIZE):fact_(SIZE, 1), fact_inv_(SIZE,1), inv_(SIZE, 1) {init(SIZE);}
	void init(int SIZE){
		fact_.assign(SIZE, 1), fact_inv_.assign(SIZE,1), inv_.assign(SIZE, 1);
		int mod=fact_[0].get_mod();
		for(int i=2;i<SIZE;i++){
			fact_[i]=fact_[i-1]*i;
			inv_[i]=-inv_[mod%i]*(mod/i);
			fact_inv_[i]=fact_inv_[i-1]*inv_[i];
		}
	}
	T nCk(int n, int k){
		return fact_[n]*fact_inv_[k]*fact_inv_[n-k];
	}
	T nHk(int n, int k){
		return nCk(n+k-1,k);
	}
	T fact(int n){
		return fact_[n];
	}
	T fact_inv(int n){
		return fact_inv_[n];
	}
	T inv(int n){
		return inv_[n];
	}
};
Comb<modint> comb(10000);

using Graph = vector<vector<int>>;
vector<bool> seen;

pair<modint, long> dfs(const Graph& G, int v){
	seen[v]=true;
	vector<pair<modint, long>> ch;
	for(auto e:G[v]){
		if(!seen[e]){
			ch.push_back(dfs(G,e));
		}
	}
	pair<modint, long> ret=pair<modint, long>(modint(1),0);
	if(ch.size()!=0){
		for(auto c:ch){
			ret.first*=c.first;
			ret.first*=comb.fact_inv(c.second);
			ret.second += c.second;
		}
		ret.first*=comb.fact(ret.second);
	}
	ret.second+=1;
	return ret;
}

int main(){
	int N;
	cin>>N;
	Graph G(N);
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	modint ans=0;
	for(int r=0;r<N;r++){
		seen.assign(N,false);
		ans+=dfs(G,r).first;
	}
	cout<<ans/2<<endl;
	return 0;
}
	
