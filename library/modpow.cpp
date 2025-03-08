long modpow(long a, long b, long mod){
	long res = 1;
  while(b){
    if(b%2)res=(res*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
	return res;
}
