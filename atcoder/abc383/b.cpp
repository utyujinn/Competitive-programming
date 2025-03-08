#include<iostream>
using namespace std;
string s[10];

int main(){
	int h,w,d;
	cin >> h >> w >> d;
	for(int i=0;i<h;i++){
		cin>>s[i];
	}
	int ans=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<h;k++){
				for(int l=0;l<w;l++){
					if(((k>i)||(l>j))&&(s[i][j]=='.'&&s[k][l]=='.')){
						string t[10];
						int tmp=0;
						for(int i=0;i<h;i++){
							t[i]=s[i];
						}
						for(int m=-d;m<=d;m++){
							for(int n=-(d-abs(m));n<=(d-abs(m));n++){
								if(i+m>=0&&i+m<h&&j+n>=0&&j+n<w){
									if(t[i+m][j+n]=='.'){
										tmp++;
										t[i+m][j+n]='#';
									}
								}
							}
						}
						for(int m=-d;m<=d;m++){
							for(int n=-(d-abs(m));n<=(d-abs(m));n++){
								if(k+m>=0&&k+m<h&&l+n>=0&&l+n<w){
									if(t[k+m][l+n]=='.'){
										tmp++;
										t[k+m][l+n]='#';
									}
								}
							}
						}
						ans=max(ans,tmp);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
