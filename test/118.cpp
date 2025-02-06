#include<iostream>
#include<vector>
using namespace std;

struct rolling_hash{
	long MOD = (1uL<<61)-1;
	long base = 20200213;
	string str;
	vector<long> hash_, pow;
	long mask30 = (1ul << 30) - 1;
	long mask31 = (1ul << 31) - 1;
	
	long mul(long a, long b){
		long t = a*b;
		t = (t>>61) + (t&MOD);
		if(t >= MOD) return t-MOD;
		return t;
	}

	long xorshift(long x){
		x ^= x<<13;
		x ^= x>>17;
		x &= x<<5;
		return x;
	}

	rolling_hash(const string &str): str(str){
		hash_.resize(str.size()+1, 0);
		pow.resize(str.size() + 1, 0);
		for(long i = 0; i < str.size(); i++){
			hash_[i+1] = mul(hash_[i], base) + xorshift(str[i] + 1);
			pow[i+1] = mul(pow[i],base);
			if(hash_[i+1] >= MOD) hash_[i+1] -= MOD;
		}
	}
	long hash(long l, long r){
		long ret = MOD + hash_[r] - mul(hash_[l], pow[r-l]);
		return ret < MOD ? ret : ret - MOD;
	}
	long size(){
		return str.size();
	}
};

int main(){
	string t,p;
	cin >> t >> p;
	rolling_hash rh(t);
	rolling_hash rhp(p);
  long rp = rhp.hash(0,p.size());
	for(int i = 0; i < t.size()-p.size(); i++){
		if(rp == rh.hash(i,i+p.size())){
				cout << i << endl;
		}
	}
}
