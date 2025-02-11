#include<iostream>
#include<vector>
#include<cmath>
#include<complex>
using namespace std;

static const double pi = acos(-1.0);

vector<complex<double>> DFT(vector<long> a){
	int n=a.size();
	vector<complex<double>> ret(n);
	complex<double> zheta=polar(1.0, 2*pi/n);
	//cout<<zheta<<endl;
	for(int i=0;i<n;i++){
		//cout<<a[i]<<" ";
		for(int j=0;j<n;j++){
			//cout<<pow(zheta,i*j)*double(a[j])<<" ";
			ret[i]+=pow(zheta,(i*j)%n)*double(a[j]);
		}
		//cout<<ret[i]<<endl;
	}
	return ret;
}

vector<long> IDFT(vector<complex<double>> a){
	int n=a.size();
	vector<long> ret(n);
	complex<double> zheta=polar(1.0, -2*pi/n);
	for(int i=0;i<n;i++){
		complex<double> tmp=(0,0);
		for(int j=0;j<n;j++){
			tmp+=(pow(zheta,(i*j)%n)*a[j]).real();
		}
		ret[i]=tmp.real()/n;
	}
	return ret;
}

vector<complex<double>> FFT(vector<complex<double>> A){
	const int N=A.size();
	if(N==1)return A;
	vector<complex<double>> even(N/2),odd(N/2);
	for(int i=0;i<N/2;i++){
		even[i]=A[i*2];
		odd[i]=A[i*2+1];
	}
	even=FFT(even);
	odd=FFT(odd);
	for(int i=0;i<N/2;i++){
		odd[i]*=polar(1.0, 2*M_PI*i/N);
		A[i]=even[i]+odd[i];
		A[N/2+i]=even[i]-odd[i];
	}
	return A;
}

vector<complex<double>> IFFT(vector<complex<double>> A){
	const int N=A.size();
	if(N==1)return A;
	vector<complex<double>> even(N/2),odd(N/2);
	for(int i=0;i<N/2;i++){
		even[i]=A[i*2];
		odd[i]=A[i*2+1];
	}
	even=IFFT(even);
	odd=IFFT(odd);
	for(int i=0;i<N/2;i++){
		odd[i]*=polar(1.0, -2*M_PI*i/N);
		A[i]=even[i]+odd[i];
		A[N/2+i]=even[i]-odd[i];
	}
	return A;
}

vector<complex<double>> convolution(vector<complex<double>> A,vector<complex<double>> B){
	int N=A.size()+B.size()+1;
	int a=1;
	while(a<=N){
		a*=2;
	}
	N=a;
	A.resize(N);
	B.resize(N);
	vector<complex<double>> FA=FFT(A);
	vector<complex<double>> FB=FFT(B);
	vector<complex<double>> FC(N);
	for(int i=0;i<N;i++)FC[i]=FA[i]*FB[i];
	vector<complex<double>> C=IFFT(FC);
	for(int i=0;i<N;i++)C[i]/=N;
	return C;
}


int main(){
	int N,M;
	cin>>N>>M;
	vector<complex<double>> A(N+M-1),B(N+M-1);
	for(int i=0;i<N;i++){
		double s;cin>>s;A[i]=complex<double>(s,0);
	}
	for(int i=0;i<M;i++){
		double s;cin>>s;B[i]=complex<double>(s,0);
	}
	auto C=convolution(A,B);
	for(int i=0;i<N+M-1;i++)cout<<((long)C[i].real())%998244353<<(i==N+M-2?"\n":" ");
}
