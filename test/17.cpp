#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(){
	int k;
	cin >> k;
	vector<int> array = {0,1,2,3,4,5,6,7};
	vector<int> x(k),y(k);
	for(int i = 0; i < k; i++)cin >> x[i] >> y[i];

	do{
		int flag0 = 1;
		for(int i = 0; i < k; i++){
			int flag1 = 0;
			for(int j = 0; j < 8; j++){
				if(x[i] == j && y[i] == array[j]){
					flag1 = 1;
					break;
				}
			}
			if(flag1 == 0){
				flag0 = 0;
				break;
			}
		}
		if(flag0 == 0)continue;

		set<int> st0,st1;
		bool flag = true;
		for(int i = 0; i < 8; i++){
			if(st0.count(i-array[i]) == 0 && st1.count(i+array[i]) == 0){
				st0.insert(i - array[i]);
				st1.insert(i + array[i]);
			}else{
				flag = false;
				break;
			}
		}
		if(flag == true)break;
	}while(next_permutation(array.begin(), array.end()));
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(j == array[i])cout << "Q";
			else cout << ".";
		}
		cout << endl;
	}
}


	
