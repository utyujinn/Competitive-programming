#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
using namespace std;
template<class T, class U>
bool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }
template<class T, class U>
bool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }

int main(void){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <=n;i++){
        int tmp = 0;
        for(int j = 1; j <= n;j++){
            if(i%j==0)tmp++;
        }
        if(tmp == 8 && i%2==1)ans++;
    }
    cout << ans << endl;
    return 0;
}