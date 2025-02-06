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
    int n;
    cin >> n;
    vi dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    rep(i,n){
        if(i==0)continue;
        else{
            dp[i+1] = dp[i-1] + dp[i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}