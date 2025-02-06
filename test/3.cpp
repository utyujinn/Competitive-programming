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
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i <= s.size()-1; i++){
        for(int j = i+1; j <= s.size(); j++){
            int tmp = true;
            for(int k = i; k < j; k++){
                if(s[k] != 'A' && s[k] != 'C' && s[k] != 'G' && s[k] != 'T'){
                    tmp = false;
                    break;
                }
            }
            if(tmp)ans = max(ans,j-i);
        }
    }
    cout << ans << endl;
    return 0;
}