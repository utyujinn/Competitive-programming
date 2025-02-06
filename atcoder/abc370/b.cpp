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

int main(void){
    ll n;
    cin >> n;
    vvl a(n+1,vl(n+1));
    rep(i,n)rep(j,i+1)cin >> a[i+1][j+1];
    int q = 1;
    rep(i,n){
        if(q>=i+1)
            q = a[q][i+1];
        else
            q = a[i+1][q];
    }
    cout << q << endl;
    return 0;
}