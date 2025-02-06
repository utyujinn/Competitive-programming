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
    ll nn = n-1;
    vl c(nn);
    rep(i,nn)cin >> c[i];
    ll result;
    cin >> result;

    vvl dp(n,vl(21,0));//the number of equations that equal to j until i
    dp[0][0] = 1;
    rep(i,nn){
        rep(j,21){
            if(j-c[i] >= 0){
                dp[i+1][j]+=dp[i][j-c[i]];
            }
            if(j+c[i] < 21 && i != 0){
                dp[i+1][j]+=dp[i][j+c[i]];
            }
        }
    }
    cout << dp[nn][result] << endl;
    return 0;
}