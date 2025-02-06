#include<iostream>
#include<vector>
using namespace std;
int main(){
	int h,w,k;
	cin >> h >> w >> k;
	vector<vector<char>> charlist(h,vector<char>(w));
	vector<vector<int>> inilist(h,vector<int>(w));
	for(int i = 0; i < h; i++){
		for(int j =0; j < w; j++){
			cin >> charlist[i][j];
			inilist[i][j] = charlist[i][j] - '0';
		}
	}
	int ans = 0;
	
	for(int di = 0; di < h; di++){
		for(int dj = 0; dj < w; dj++){
			vector<vector<int>> list = inilist;
			int tmp = 0;
			int cnt = 0;
			list[di][dj] = -1;
			for(int i = 0; i < w; i++){
				int index = h-1;
				for(int j = h-1; j >= 0; j--){
					if(list[j][i] == -1){
					}
					else{
						list[index][i] = list[j][i];
						index--;
					}
				}
				while(index >= 0){
					list[index][i]=-1;
					index--;
				}
			}
			while(true){
				int flag2 = 1;
				for(int r = 0; r < h; r++){
					vector<int> ch(w,0);
					for(int i = 0; i < w-k+1; i++){
						int flag = 1;
						for(int j = 1; j < k; j++){
							if(list[r][i] != list[r][i+j] || list[r][i] == -1 || list[r][i+j] == -1){
								flag = 0;
								break;
							}
						}
						if(flag){
							for(int j = 0; j < k; j++){
								ch[i+j]++;
								flag2 = 0;
							}
						}
					}
					for(int i = 0; i < w; i++){
						if(ch[i]){
							tmp += list[r][i] * (1<<cnt);
							list[r][i] = -1;
						}
					}
				}
				if(flag2) break;
				for(int i = 0; i < w; i++){
					int index = h-1;
					for(int j = h-1; j >= 0; j--){
						if(list[j][i] == -1){
						}
						else{
							list[index][i] = list[j][i];
							index--;
						}
					}
					while(index >= 0){
						list[index][i]=-1;
						index--;
					}
				}
				cnt++;
			}
			ans = max(tmp,ans);
		}
	}
	cout << ans << endl;
}
