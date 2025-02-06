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
    ll n,m,k;
    cin >> n >> m >> k;
    vl a(n);
    rep(i,n)cin >> a[i];
    vl b(n);
    b = a;
    sort(all(b));
    vl c(n,-1);
    ll low_battle = b[n-m];
    ll high_battle = b[n-m-1];

    ll aa = k;
    rep(i,n)aa-=a[i];

    rep(i,n){
        ll pa = lower_bound(all(b),a[i])-b.begin();
        if(n-pa>m){
            ll tmp = (low_battle+aa-a[i]+1)/2;
            if(tmp >= 0 && tmp <= aa)c[i] = tmp;
        }
        else{
            ll tmp = (high_battle+aa-a[i]+1)/2;
            if(tmp >= 0 && tmp <= aa)c[i] = tmp;
        }
    }
    rep(i,n)cout << c[i] << ' ';
    return 0;
}