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
    ll n,m;
    cin >> n >> m;
    vvi rel(n,vi(n,0));
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        rel[x][y] = true;
        rel[y][x] = true;
    }
    int ans = 1;
    rep(i,pow(2,n)){
        int cnt = 0;
        vi group(n);
        rep(j,n){
            group[j] = (i>>j)%2;
            cnt += group[j];
        }
        bool flag = true;
        rep(j,n-1){
            for(int k=j+1;k < n;k++){
                if(group[j] && group[k]){
                    if(!rel[j][k]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag)chmax(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}
