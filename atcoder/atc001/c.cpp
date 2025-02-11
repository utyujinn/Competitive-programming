#include<iostream>
#include<vector>
#include<cmath>
#include<complex>
#include<iomanip>
using namespace std;

vector<complex<double>> FFT(vector<complex<double>> &A,double inv){
  const int N=A.size();
  if(N==1)return A;
  vector<complex<double>> even,odd;
  for(int i=0;i<N;i++){
		if(i%2==0)even.push_back(A[i]);
		else odd.push_back(A[i]);
  }
  even=FFT(even,inv);
  odd=FFT(odd,inv);
	double DN=(double)N;
	complex<double> zeta(cos(inv*2*M_PI/DN), sin(inv*2*M_PI/DN));
	complex<double> now=complex<double>(1,0);
  for(int i=0;i<N;i++){
		A[i]=even[i%(N/2)]+now*odd[i%(N/2)];
		now*=zeta;
  }
  return A;
}

vector<complex<double>> convolution(vector<complex<double>> A,vector<complex<double>> B){
  int IN=A.size()+B.size()+1;
  int a=1;
  while(a<=IN){
    a*=2;
  }
  int N=a;
  A.resize(N);
  B.resize(N);
  vector<complex<double>> FA=FFT(A,1);
  vector<complex<double>> FB=FFT(B,1);
  vector<complex<double>> FC(N);
  for(int i=0;i<N;i++)FC[i]=FA[i]*FB[i];
  vector<complex<double>> C=FFT(FC,-1);
	double DN=(double)N;
  for(int i=0;i<N;i++)C[i]/=DN;
  C.resize(IN);
  return C;
}

int main(){
  int N;
  cin>>N;
  vector<complex<double>> A(N+1),B(N+1);
  for(int i=1;i<=N;i++){
    double s,t;cin>>s>>t;
		A[i]=complex<double>(s,0);
    B[i]=complex<double>(t,0);
  }
  auto C=convolution(A,B);
  for(int i=1;i<=N*2;i++)cout<<((long)round(C[i].real()))%998244353<<endl;
}
