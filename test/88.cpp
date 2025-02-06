#include<iostream>
#include<vector>
using namespace std;

int n;
void print(vector<int> &c){
	for(int i = 0; i < n; i++){
		cout << c[i] << " ";
	}
	cout << endl;
}

int main(){
	cin >> n;
	vector<int> c(n);
	int index = 0;
	int color = 0; //0:white, 1:black
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		if(!(i%2==1)){//odd
			if(color != a){
				if(c[index] == 0)c[index]++;
				else c[++index]++;
				color^=1;
			}
			else{
				c[index]++;
			}
		}
		else{
			if(color == a){
				c[index]++;
			}
			else{
				if(index == 0){
					c[index]++;
				}
				else{
					c[index-1] += c[index] + 1;
					c[index--] = 0;
				}
				color^=1;
			}
		}
//		print(c);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if((index + color)%2 == 0){//white
			if(i%2==0)ans+=c[i];
		}else{
			if(i%2==1)ans+=c[i];
		}
	}
	cout << ans << endl;
}
