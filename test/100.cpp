#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	int tmp = 1;
	int flag = 0;
	while(true){
		if(tmp*(tmp+1)/2 == n){
			flag = 1;
			break;
		}
		else if(tmp*(tmp+1)/2 > n){
			break;
		}
		tmp++;
	}
	if(flag){
		vector s(tmp+1, vector<int>(0));
		cout << "Yes" << endl;
		cout << tmp+1 << endl;
		int cur = tmp;
		int num = 1;
		for(int i = 0; i < tmp+1; i++){
			for(int j = 0; j < cur; j++){
				s[i].push_back(num);
				s[i+j+1].push_back(num);
				num++;
			}
			cur--;
		}
		for(int i = 0; i < tmp+1; i++){
			cout << tmp << " ";
			for(int j = 0; j < tmp; j++){
				cout << s[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << "No" << endl;
	}
}
		
