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

struct Grid{
    int x;
    int y;
};

int h,w,n;
queue<Grid> q;
vvl dist;

int main(void){
    cin >> h >> w >> n;
    vector<vector<char>> c(h,vector<char>(w));
    rep(i,h)rep(j,w)cin >> c[i][j];
    ll ans = 0;
    rep(i,h)rep(j,w){
        if(c[i][j] != 'X'){
            Grid g = {i,j};
            if(c[i][j]-'0' == n | c[i][j] == '.')continue;
            else{
                int o;
                if(c[i][j] == 'S'){
                    q.push(g);
                    o = 1;
                }
                else{
                    q.push(g);
                    o = c[i][j]-'0'+1;
                }        
                dist.assign(h,vl(w,-1));
                dist[i][j] = 0;
                while(!q.empty()){
                    Grid cg = q.front();
                    q.pop();
                    rep(u,3)rep(v,3){
                        if ((u == 0 && v == 1) || (u == 1 && v == 0) || (u == 2 && v == 1) || (u == 1 && v == 2)) {
                            Grid ng = {cg.x+u-1,cg.y+v-1};
                            if(ng.x < h && ng.x >=0 && ng.y < w && ng.y >= 0){
                                if(dist[ng.x][ng.y]==-1){
                                    dist[ng.x][ng.y] = dist[cg.x][cg.y]+1;
                                    if(c[ng.x][ng.y]-'0'==o){
                                        ans+=dist[ng.x][ng.y];
                                        break;
                                    }
                                    else if(c[ng.x][ng.y] != 'X'){
                                        q.push(ng);
                                    }
                                    else{
                                        dist[ng.x][ng.y] = inf;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}