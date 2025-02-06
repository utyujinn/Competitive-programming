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
    ll D,n,m;
    cin >> D >> n >> m;
    vi d(n+1),k(m);
    d[0]=0;
    d[n] = D;
    for(int i=1; i < n; i++)cin >> d[i];
    sort(d.begin(),d.end());
    rep(i,m)cin >> k[i];
    int ans = 0;
    rep(i,m){
        int it = lower_bound(d.begin(),d.end(),k[i])-d.begin();
        ans += min(d[it]-k[i],k[i]-d[it-1]);
    }
    cout << ans << endl;

    return 0;
}