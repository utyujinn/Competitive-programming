#include<iostream>
#include<vector>

using namespace std;

int main(){
	int h;
	cin >> h;
	while(h != 0){
		vector<vector<int>> list(h,vector<int>(5));
		for(int i = 0; i < h; i++){
			for(int j = 0; j < 5; j++){
				cin >> list[i][j] ;
			}
		}
		int ans = 0;
		while(true){
			int flag = 1;
			for(int i = 0; i < h; i++){
				vector<int> ch(5,0);
				int pp = list[i][0];
				int p = list[i][1];
				for(int j = 2; j < 5; j++){
					if(pp == p && p == list[i][j] && pp != -1){
						ch[j]++,ch[j-1]++,ch[j-2]++;
						flag = 0;
					}
					pp = p;
					p = list[i][j];
				}
				for(int j = 0; j < 5; j++){
					if(ch[j]){
						ans += list[i][j];
						list[i][j] = -1;
					}
				}
			}
			if(flag)break;
			for(int j = 0; j < 5; j++){
				int index = h-1;
				for(int i = h-1; i >= 0; i--){
					if(list[i][j] == -1){
					}
					else{
						list[index][j] = list[i][j];
						index--;
					}
				}
				while(index >= 0){
					list[index][j] = -1;
					index--;
				}
			}
		}
		cout << ans << endl;
		cin >> h;
	}
}



