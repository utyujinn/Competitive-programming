#include<iostream>
using namespace std;
int N,M,K;

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
const int MOD = 998244353;
using modint = ModInt<MOD>;

int main(){
	cin>>N>>M>>K;
	modint cnt=M;
	modint ans=0;
	for(int i=1;i<N;i++){
		cnt*=(M-1);
	}
	ans+=cnt;
	int i=0;
	while(K--){
		cnt/=(M-1);
		cnt*=N-1-i;
		i++;
		ans+=cnt;
	}
	cout<<ans<<endl;
}
