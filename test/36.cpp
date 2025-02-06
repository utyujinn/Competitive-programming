#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
using namespace std;
template<class T, class U>
bool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }
template<class T, class U>
bool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }

int main(void){
    int n,W;
    cin >> n >> W;
    vi v(n),w(n);
    rep(i,n)cin >> v[i] >> w[i];
    vvi dp(n+1,vi(W+1,0));

    rep(i,n){
        rep(j,W+1){
            if(j>=w[i]){
                dp[i+1][j] = max(dp[i+1][j-w[i]]+v[i],dp[i][j]);
                /*
                int k = 1;
                while(j>=w[i]*k){
                    dp[i+1][j]=max({dp[i][j-w[i]*k]+v[i]*k,dp[i][j],dp[i+1][j]});
                    k++;
                }
                */
            }
            else{
                dp[i+1][j]=dp[i][j];
            }
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}