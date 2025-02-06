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
/*1
int main(void){
    ll n,q;
    cin >> n;
    vl s(n);
    rep(i,n)cin >> s[i];
    cin >> q;
    vi t(q);
    rep(i,q)cin >> t[i];
    int ans = 0;
    rep(i,q){
        int k = lower_bound(s.begin(),s.end(),t[i])-s.begin();
        if (s[k] == t[i]) ans++;
        /*
        int l = 0,r=n;
        while(l+1<r){
            int m = (l+r)/2;
            if(s[m]<=t[i]) l=m;
            else r=m;
        }
        if(s[l]!=t[i]) continue;
        ans++;
        
    }
    cout << ans << endl;
    return 0;
}
*/

/*2
int main(){
    ll n,q;
    cin >> n;
    vl s(n);
    rep(i,n)cin >> s[i];
    cin >> q;
    vi t(q);
    rep(i,q)cin >> t[i];
    int ans = 0;
    rep(i,q){
        int k = lower_bound(all(s),t[i])-s.begin();
        if(s[k]==t[i])ans++;
    }
    cout << ans << endl;
}
*/

int main(){
    ll n,q;
    cin >> n;
    vl s(n);
    rep(i,n)cin >> s[i];
    cin >> q;
    vi t(q);
    rep(i,q)cin >> t[i];
    int ans = 0;
    rep(i,q){
        int ng = -1;
        int ok = n;
        while(ok-ng>1){
            int m = (ok+ng)/2;
            if(s[m]>=t[i])ok = m;
            else ng = m;
        }
        if(s[ok]==t[i])ans++;
    }
    cout << ans << endl;
}