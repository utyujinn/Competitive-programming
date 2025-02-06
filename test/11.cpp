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
    vl k(m);
    vvl s(m);
    rep(i,m){
        cin >> k[i];
        rep(j,k[i]){
            int tmp;
            cin >> tmp;
            tmp--;
            s[i].push_back(tmp);
        }
    }
    vi p(m);
    int ans = 0;
    rep(i,m){
        cin >> p[i];
    }
    rep(i,pow(2,n)){
        vi on(n);
        rep(j,n){
            on[j] = (i>>j)%2; 
        }
        bool flag = true;
        rep(j,m){
            int cnt = 0;
            for(auto a: s[j]){
                cnt += on[a];
            }
            if(cnt%2!=p[j]){
                flag = false;
                break;
            }
        }
        if(flag)ans++;
    }
    cout << ans << endl;
    return 0;
}