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
    ll n;
    cin >> n;
    vl a(n);
    rep(i,n)cin >> a[i];
    a.insert(a.end(),a.begin(),a.end());
    vvl dp(n*2,vl(n*2,-1));
    rep(i,n*2){
        if(i < n)
            dp[i][i] = a[i];
        else
            dp[i][i] = a[i-n];
    }
    for(int l = 2;l <= n; l++){//length
        for(int s = 0; s < 2*n-l+1; s++){
            int e = s+l-1;
            if(l%2==1)
                dp[s][e] = max(dp[s][e-1] + a[e],dp[s+1][e] + a[s]);
            else{
                if(s > 0)if(a[e] > a[s-1])chmax(dp[s][e],dp[s][e-1]);
                if(a[e+1] < a[s])chmax(dp[s][e],dp[s+1][e]);
            }
        }
    }
    ll ans = -1;
    rep(i,n){
        chmax(ans, dp[i][n+i-1]);
        chmax(ans,dp[i][n+i-2]);
    }
    cout << ans << endl;

    return 0;
}