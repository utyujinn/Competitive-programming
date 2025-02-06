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
    int n,x;
    while(1){
        int ans = 0;
        cin >> n >> x;
        if(n == 0 && x == 0)break;
        for(int i = 1; i < n-1; i++){
            for(int j = i+1; j < n;j++){
                for(int k = j+1; k < n+1; k++){
                    if(i+j+k == x) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}