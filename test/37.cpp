#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using namespace std;
template<class T, class U>
bool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }
template<class T, class U>
bool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }
const ll inf=1LL<<60;

int main(void){
    ll n,m;
    cin >> n >> m;
    vl c(m);
    rep(i,m)cin >> c[i];
    vvl dp(m+1,vl(n+1,inf));
    rep(i,m+1)dp[i][0] = 0;
    rep(i,m){
        rep(j,n+1){
            dp[i+1][j] = dp[i][j];
            if(j-c[i] >= 0){
                dp[i+1][j] = min({dp[i+1][j-c[i]]+1,dp[i][j]});
            }
        }
    }
    cout << dp[m][n] << endl;
}