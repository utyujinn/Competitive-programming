#include<iostream>
#include<algorithm>
using namespace std;

int main(){
        int n,m;
        string s,t;
        cin >> n >> m >> s >> t;
        char last = t[m-1];
        sort(t.rbegin(), t.rend());
        int flag = 1;
        int index = 0;
        for(int i = 0; i < m; i++){
                if(index>=n)break;
                if(s[index] < t[i]){
                        if(t[i]==last)flag--;
                        s[index] = t[i];
                }
                else{
                        while(s[index] >= t[i] && index < n){
                                index++;
                        }
                        if(index < n){
                                if(t[i]==last)flag--;
                                s[index] = t[i];
                        }
                }
                index++;
        }
        if(flag)s[n-1] = last;
        cout << s << endl;
}
