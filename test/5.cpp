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

int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1<<29;
    for(int i = 0; i <= min(x,y); i++){
        ans = min(ans,i*2*c+(x-i)*a+(y-i)*b);
    }
    cout << ans << endl;
    return 0;
}
