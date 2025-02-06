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
    int n,m;
    cin >> n >> m;
    vvl a(n,vl(m));
    rep(i,n)rep(j,m)cin >> a[i][j];
    ll ans=0;
    rep(i,m-1){
        for(int j = i+1; j < m; j++){
            ll tmp = 0;
            rep(k,n){
                tmp += max(a[k][i],a[k][j]);
            }
            ans = max(tmp,ans);
        }
    }
    cout << ans << endl;
    return 0;
}