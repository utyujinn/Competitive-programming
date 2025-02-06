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
const ll inf=1LL<<60;

ll modpow(ll a, ll n, ll mod){
    ll res = 1;
    while(n>0){
        if(n%2==1)res = res*a%mod;
        a = a*a%mod;
        n>>=1;
    }
    return res;
}

int main(void){
    ll m,n;
    cin >> m >> n;
    ll ans = modpow(m,n,1000000007);
    cout << ans << endl;
    return 0;
}