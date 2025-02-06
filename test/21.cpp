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
    vl h(n),s(n);
    rep(i,n)cin >> h[i] >> s[i];

    ll ans = 0;
    ll l = 0;
    ll r = inf;
    while(abs(r-l)>0){
        ll mid=(l+r)/2;
        bool flag = true;
        vl limit(n,0);
        rep(i,n){
            if(mid<h[i]){
                flag = false;
                break;
            }else{
                limit[min((mid-h[i])/s[i],n-1)]++;
            }
        }
        if(flag){
            int sum = 0;
            rep(i,n){
                sum+= limit[i];
                if(sum>i+1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag)l = mid;
        else r = mid;
    }
    ans = l;
    cout << ans << endl;
    return 0;
}
