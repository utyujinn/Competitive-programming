#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> list(n);
	int color = 0;
	int index = 0;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		if(color != tmp){
			list[index]++;
			color ^= 1;
		}
		else{
			if(list[index] == 0)list[index]++;
			else list[++index]++;
		}
	}

	int tmp = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		tmp += list[i];
		if(i >= 3)tmp -= list[i-3];
		ans = ans<tmp?tmp:ans;
	}
	cout << ans << endl;
}

