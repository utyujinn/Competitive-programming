#include<iostream>
using namespace std;

int main(){
  int T;cin>>T;
  for(;T--;){
    int R,B;cin>>R>>B;
    int r=0,c=0;
    if(B%2==1){
      if(R%2==0&&R>=2){
        cout<<"Yes"<<endl;
        for(int i=0;i<B/2+1;i++){
          cout<<"B "<<r<<" "<<c<<endl;
          c--;
          r++;
        }c+=2;
        for(int i=0;i<B/2;i++){
          cout<<"B "<<r<<" "<<c<<endl;
          c++;
          r--;
        }
        for(int i=0;i<R/2+1;i++){
          cout<<"R "<<r<<" "<<c<<endl;
          r--;
        }r++;c--;
        for(int i=0;i<R/2-1;i++){
          cout<<"R "<<r<<" "<<c<<endl;
          r++;
        }
      }else{
        cout<<"No"<<endl;
      }
    }else if(B%2==0){
      if(R%2==0){
        cout<<"Yes"<<endl;
        for(int i=0;i<B/2;i++){
          cout<<"B "<<r<<" "<<c<<endl;
          r++;
          c--;
        }if(B>0)c+=2;
        for(int i=0;i<B/2;i++){
          cout<<"B "<<r<<" "<<c<<endl;
          r--;
          c++;
        }
        if(B>0){
          cout<<"R "<<r<<" "<<c<<endl;
          c--;
        }else{
          cout<<"R "<<r<<" "<<c<<endl;
        }
        for(int i=0;i<R/2;i++){
          cout<<"R "<<r<<" "<<c<<endl;
          r--;
        }r++;c--;
        for(int i=0;i<R/2-1;i++){
          cout<<"R "<<r<<" "<<c<<endl;
          r++;
        }
      }
      else{
        cout<<"No"<<endl;
      }
    }
  }
}
