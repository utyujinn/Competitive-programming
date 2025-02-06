#include<iostream>
#include<vector>
using namespace std;
int main(void){
    long n,m;
    cin >> n >> m;
    vector<vector<long>> cost(n,vector<long>(n, 1LL<<60));
    vector<vector<long>> time(n,vector<long>(n, 1LL<<60));
    for(int i = 0; i < m; i++){
      long a,b,c,t;
      cin >> a >> b >> c >> t;
			a--;b--;
      cost[a][b] = c;
      time[a][b] = t;
      cost[b][a] = c;
      time[b][a] = t;
    }
    vector dp(1<<n,vector<long>(n,1LL<<60));
    vector dp2(1<<n,vector<long>(n,0));
    dp[0][0] = 0;
    dp2[0][0] = 0;
    for(int i = 1;i < 1<<n; i++){
			for(int j = 0; j < n; j++){
				if(!(i & 1<<j))for(int k = 0; k < n; k++){
					long tmp = dp[i][j];
         	if(dp2[i][j] + cost[k][j] <= time[k][j]){
						dp[i][j] = min(dp[i][j], dp[i ^ (1<<j)][k] + cost[k][j]);
						if(dp[i][j] == dp[i^(1<<j)][k] + cost[k][j]){
							dp2[i][j] ++;
						}
						else if(dp[i][j] < tmp){
							dp2[i][j] = 1;
						}
					}
        }
			}
    }
		cout << (1<<0) << " " << (1<<1) << " " << (1<<2) <<  endl;
		for(int i = 0; i < 1<<n; i++){
			for(int j = 0; j < n; j++){
				cout << dp[i][j] << " " ;
			}
			cout << endl;
		}
    if(dp[(1<<n)-1][0] == 1LL<<60)cout << "INPOSSIBLE" << endl;
    else cout << dp[(1<<n)-1][0] << " " << dp2[(1<<n)-1][0] << endl;

    return 0;
}
