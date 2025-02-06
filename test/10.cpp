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
    int n;
    cin >> n;
    vi a(n);
    rep(i,n)cin >> a[i];
    int q;
    cin >> q;
    vi m(q);
    rep(i,q)cin >> m[i];
    vi list(2000,0);
    vi bit(n);
    rep(i,1<<n){
        int tmp = 0;
        rep(j,n){
            int div = 1<<j;
            bit[j]=(i/div)%2;
            tmp += a[j]*bit[j];
        }
        list[tmp] = 1;
    }
    rep(i,q){
        if(list[m[i]]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}