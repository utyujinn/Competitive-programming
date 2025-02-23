#include<iostream>
#include<functional>
#include<vector>
using namespace std;
int N;
using Graph = vector<vector<int>>;

template<class Monoid> struct ReRooting{
	using MergeFunc=function<Monoid(Monoid, Monoid)>;
	using AddNodeFunc = function<Monoid(int, Monoid)>;

	Graph G;
	Monoid IDENTITY;
	MergeFunc MERGE;
	AddNodeFunc ADDNODE;

	vector<vector<Monoid>> dp;

	ReRooting(const Graph &g, const Monoid &identity, const MergeFunc &merge, const AddNodeFunc &addnode){
		G=g;
		IDENTITY=identity;
		MERGE=merge;
		ADDNODE=addnode;
		build();
	}

	Monoid rec(int v, int p){
		Monoid res=IDENTITY;
		dp[v].assign(G[v].size(), IDENTITY);
		for(int i=0;i<G[v].size();i++){
			int n=G[v][i];
			if(n!=p){
				dp[v][i]=rec(n,v);
				res=MERGE(res, dp[v][i]);
			}
		}
		return ADDNODE(v, res);
	}
	void rerec(int v, int p, Monoid pval){
		for(int i=0;i<G[v].size();i++){
			int v2=G[v][i];
			if(v2==p){
				dp[v][i]=pval;
			}
		}
		vector<Monoid> left(G[v].size(), IDENTITY);
		vector<Monoid> right(G[v].size(), IDENTITY);
		for(int i=1;i<G[v].size();i++){
			left[i]=MERGE(left[i-1], dp[v][i-1]);
			right[i]=MERGE(right[i-1],dp[v][(int)G[v].size()-i]);
		}
		for(int i=0;i<G[v].size();i++){
			int n=G[v][i];
			if(n!=p){
				Monoid pval2=MERGE(left[i], right[(int)G[v].size()-i-1]);
				rerec(n,v,ADDNODE(v, pval2));
			}
		}
	}
	void build(){
		dp.assign(G.size(), vector<Monoid>());
		int root=0, nullparent=01;
		rec(root,nullparent);
		rerec(root, nullparent, IDENTITY);
	}
	Monoid get(int v){
		Monoid res=IDENTITY;
		for(int i=0;i<G[v].size();i++){
			res = MERGE(res, dp[v][i]);
		}
		return ADDNODE(v,res);
	}
};

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
	T fact_iinv(int n){
		return fact_inv_[n];
	}
	T inv(int n){
		return inv_[n];
	}
};
Comb<modint> comb(2<<17);

struct Monoid{
	modint val;
	int node;
};
Monoid identity={1,0};

int main(){
	cin>>N;
	Graph G(N);
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	auto merge=[&](Monoid a, Monoid b)->Monoid{
		return (Monoid){a.val*b.val*comb.nCk(a.node+b.node,a.node).val,a.node+b.node};
	};
	auto addnode=[&](int v, Monoid a)->Monoid{
		return a;
	};
	ReRooting<Monoid> rr(G,identity,merge,addnode);
	for(int i=0;i<N;i++){
		cout<<rr.get(i).val<<endl;
	}
}
