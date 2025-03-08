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
