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
    ll n;
    cin >> n;
    vector<vector<bool>> list(5001,vector<bool>(5001,0));
    vl x(n),y(n);
    rep(i,n){
        int a,b;
        cin >> a>> b;
        x[i] = a;
        y[i] = b;
        list[a][b]=true;
    }
    ll ans = 0;
    rep(i,n-1){
        for(int j = i+1; j < n; j++){
            int ax = x[j]-x[i],ay = y[j]-y[i];
            int px,py,qx,qy;
            px = x[i]-ay;
            py = y[i]+ax;
            qx = px + ax;
            qy = py + ay;
            if (px >= 0 && px < 5001 && py >= 0 && py < 5001 &&
                    qx >= 0 && qx < 5001 && qy >= 0 && qy < 5001)
                if(list[px][py] && list[qx][qy]){
                    chmax(ans,ax*ax+ay*ay);
                }
            px = x[i]+ay;
            py = y[i]-ax;
            qx = px + ax;
            qy = py + ay;
            if (px >= 0 && px < 5001 && py >= 0 && py < 5001 &&
                    qx >= 0 && qx < 5001 && qy >= 0 && qy < 5001) 
                if(list[px][py] && list[qx][qy]){
                    chmax(ans,ax*ax+ay*ay);
                }
        }
    }
    cout << ans << endl;
    return 0;
}