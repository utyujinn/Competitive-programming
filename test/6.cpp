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

int main(){
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    rep(i,1000){
        int c[3] = {i/100,i/10%10,i%10};
        int f = 0;
        rep(j,n){
            if(s[j] == ('0'+ c[f])){
                f++;
            }
            if(f==3){
                cnt++;
                break;
            }
        }   
    }
    cout << cnt << endl;
}

/*AC
int main(void){
    ll n;
    string s;
    cin >> n >> s;
    vvl index_list(n,vl(10,-1));
    rep(i,n){
        int cnt = 0;
        for(int j = i+1; j < n; j++){
            if(index_list[i][s[j]-'0']==-1){
                index_list[i][s[j]-'0']=j;
                cnt++;
            }
            if(cnt == 10)break;
        }
    }

    int ans = 0;
    rep(i,10){
        rep(j,n-2){
            if(s[j]-'0'==i){
                rep(k,10){
                    if(index_list[j][k]!=-1){
                        rep(l,10){
                            if(index_list[index_list[j][k]][l]!=-1){
                                ans++;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
*/