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
    ll q;
    cin >> q;
    while(q--){
        string s,t;
        cin >> s >> t;
        vvl dp(s.length()+1,vl(t.length()+1,0));
        rep(i,s.length())rep(j,t.length()){
            dp[i+1][j+1] = max({dp[i+1][j],dp[i][j+1],dp[i][j]});
            if(s[i] == t[j]){
                chmax(dp[i+1][j+1],dp[i][j]+1);
            }
        }
        cout << dp[s.length()][t.length()] << endl;
    }
    return 0;
}