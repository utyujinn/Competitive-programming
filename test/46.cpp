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
    vi r(n),c(n);
    rep(i,n)cin >> r[i] >> c[i];
    vvi m(n+1,vi(n+1,1<<30));
    rep(i,n+1)m[i][i]=0;

    for(int l = 2;l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i+l-1;
            for(int k = i; k <= j-1; k++){
                m[i][j] = min(m[i][j],m[i][k]+m[k+1][j]+c[k-1]*c[j-1]*r[i-1]);
            }
        }
    }

    cout << m[1][n] << endl;
    return 0;
}