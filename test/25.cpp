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

int w,h,cnt;
void dfs(vvi& seen,vvi c,int i,int j){
    seen[i][j] = 1;
    rep(u,3)rep(v,3){
        int ni = i+u-1;
        int nj = j+v-1;
        if((ni>=0 && ni < h && nj >= 0 && nj < w)){
            if(!seen[ni][nj] && c[ni][nj])
                dfs(seen,c,ni,nj);
            seen[ni][nj] = 1;
        }
    }
}

int main(void){
    cin >> w >> h;
    while(!(w==0 && h==0)){
        cnt = 0;
        vvi c(h,vi(w));
        vvi seen(h,vi(w,0));
        rep(i,h)rep(j,w)cin >> c[i][j];
        int ans = 0;
        rep(i,h)rep(j,w){
            if(!seen[i][j] && c[i][j]){
                dfs(seen,c,i,j);
                ans++;
            }
            seen[i][j]=1;
        }
        cout << ans << endl;
        cin >> w >> h;
    }
    return 0;
}