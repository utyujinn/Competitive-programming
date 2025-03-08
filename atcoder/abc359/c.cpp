#include<iostream>
using namespace std;
long SX,SY,TX,TY;
long ans;

int main(){
	cin>>SX>>SY>>TX>>TY;
	ans+=abs(TY-SY);
	if(((SX+SY)%2==0&&TX>SX)||((SX+SY)%2==1&&TX<SX)){
		if(abs(TY-SY)>=abs(SX-TX)+1){
		}else{
			ans+=(abs(SX-TX)-1-abs(TY-SY)+1)/2;
		}
	}else{
		if(abs(TY-SY)>=abs(SX-TX)){
		}else{
			ans+=(abs(SX-TX)-abs(TY-SY)+1)/2;
		}
	}
	cout<<ans<<endl;
}
