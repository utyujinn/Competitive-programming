template<class T>
T modpow(T A,T N,T M){
  T res=1;
  A%=M;
  while(N){
    if(N&1)res=res*A%M;
    A=A*A%M;
    N>>=1;
  }
  return res;
}

bool MillarRabin(long long N, vector<long long> A){
  int s=0;
  long long d=N-1;
  while(d%2==0){
    s++;
    d/=2;
  }
  for(long long a:A){
    if(N<=a)return true;
    long long x=modpow<__int128_t>(a,d,N);
    if(x==1)continue;
    int t;
    for(t=0;t<s;t++){
      if(x==N-1)break;
      x=__int128_t(x)*x%N;
    }
    if(t==s)return false;
  }
  return true;
}

bool isPrime(long long N){
  if(N==1)return false;
  if(N==2)return true;
  if(N%2==0)return false;
  if(N<4759123141LL){
    return MillarRabin(N,{2,7,61});
  }else{
    return MillarRabin(N,{2,325,9375,28178,450775,9780504,1795265022});
  }
}
