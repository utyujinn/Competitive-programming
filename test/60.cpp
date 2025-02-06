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

struct Edge{
    ll to;
    ll dist;
};

int main(void){
    ll n,e;
    cin >> n >> e;
    
    vvl dist(n,vl(n,inf));
    rep(i,e){
        ll s,t,d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    rep(i,n){
        dist[i][i] = 0;
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(dist[i][k] == inf || dist[k][j] == inf)continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if(dist[i][i]<0){
                    cout << "NEGATIVE CYCLE" << endl;
                    return 0;
                }
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(dist[i][j] == inf) cout << "INF";
            else cout << dist[i][j];
            if(j!=n-1)cout << " ";
        }
        cout << endl;
    }
    return 0;
}