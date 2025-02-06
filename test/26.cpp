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

void dfs(vi& xlist,vi& num,vvi& g,vi& seen,int p,int x){
    x+=xlist[p];
    seen[p]=1;
    for(int np: g[p]){
        dfs(xlist,num,g,seen,np,x);
    }
    num[p] += x;
}

int main(void){
    ll n,q;
    cin >> n >> q;
    vvi g(n+1);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vi num(n+1);
    vi xlist(n+1,0);
    rep(i,q){
        int p,x;
        cin >> p >> x;
        xlist[p]+=x;
    }
    vi seen(n+1,0);
    dfs(xlist,num,g,seen,1,0);
    rep(i,n)cout << num[i+1] << ' ';
    return 0;
}