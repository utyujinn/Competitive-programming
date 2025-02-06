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
    ll n,k;
    cin >> n >> k;
    vector<vvl> dp(n+1,vvl(3,vl(2,0)));// date,kind,continuous value:number of probable
    vl c(n,-1);
    rep(i,k){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        c[a] = b;
    }
    rep(i,n){
        if(i == 0){
            if(c[i] != -1)
                dp[1][c[i]][0] = 1;
            else
                rep(j,3)
                    dp[1][j][0] = 1;
        }
        else if(c[i]!=-1){
            int num = 0;
            rep(u,3)rep(v,2){
                if(u != c[i])
                    num += dp[i][u][v]%10000;
            }
            rep(k,3){
                if(k >= 1)dp[i+1][c[i]][k] = dp[i][c[i]][k-1]%10000;
                else dp[i+1][c[i]][k] = num%10000;
            }
        }
        else{
            int num0 =0, num1=0, num2 = 0;
            rep(u,3)rep(v,2){
                if(u == 0){
                    num1 += dp[i][u][v]%10000;
                    num2 += dp[i][u][v]%10000;
                }
                if(u == 1){
                    num0 += dp[i][u][v]%10000;
                    num2 += dp[i][u][v]%10000;
                }
                if(u == 2){
                    num0 += dp[i][u][v]%10000;
                    num1 += dp[i][u][v]%10000;
                }
            }
            rep(j,3)rep(k,2){
                if(k >= 1)dp[i+1][j][k] = dp[i][j][k-1]%10000;
                else {
                    int num;
                    if(j == 0)
                        num = num0%10000;
                    else if(j == 1)
                        num = num1%10000;
                    else
                        num = num2%10000;
                    dp[i+1][j][k] = num%10000;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,3)rep(j,2){
        ans += dp[n][i][j]%10000;
    }
    cout << ans%10000 << endl;
    return 0;
}