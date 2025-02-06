#include<iostream>
#include<vector>

using namespace std;

int main(){
	int h,w,x,y;
	cin >> h >> w >> x >> y;
	vector<vector<char>> s(h,vector<char>(w));
	for(int i = 0; i < h; i++)for(int j = 0; j < w; j++)cin >> s[i][j];
	vector<vector<bool>> seen(h,vector<bool>(w, false));
	string t;
	cin >> t;
	x--,y--;
	long ans = 0;
	if (s[x][y] == '@')ans++;
	seen[x][y] = true;
	for(char c: t){
		if(c=='U'){
			if(x-1 >=0)if(s[x-1][y] != '#'){
				x--;
				if (s[x][y] == '@' && !seen[x][y])ans++;
			}
		}
		if(c=='D')if(s[x+1][y] != '#'){
			if(x+1 < h){
				x++;
				if (s[x][y] == '@' && !seen[x][y])ans++;
			}
		}
		if(c=='L')if(s[x][y-1] != '#'){
			if(y-1 >=0){
				y--;
				if (s[x][y] == '@' && !seen[x][y])ans++;
			}
		}
		if(c=='R')if(s[x][y+1] != '#'){
			if(y+1 < w){
				y++;
				if (s[x][y] == '@' && !seen[x][y])ans++;
			}
		}
		seen[x][y] = true;
	}
	cout << ++x << " " << ++y << " " << ans << endl;
}
