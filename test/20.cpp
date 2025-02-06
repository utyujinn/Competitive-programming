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
    vl a(n),b(n),c(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = 0;
    rep(i,n){
        ll ida = lower_bound(all(a),b[i])-a.begin();
        ll idc = upper_bound(all(c),b[i])-c.begin();
        ans += ida*(n-idc);
    }
    cout << ans << endl;
    return 0;
}