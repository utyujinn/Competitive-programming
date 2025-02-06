#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
        int n,w;
        cin >>n>>w;
        vector<vector<pair<int,int>>> list(w);
        for(int i =0; i<n;i++){
                int x,y;
                cin>>x>>y;
                x--,y--;
                list[x].emplace_back(y,i);
        }
        vector<int> time(n,0);
        int msize=1e7;

        for(int i=0;i<w;i++){
                sort(list[i].begin(),list[i].end());
                for(int j=0;j<list[i].size();j++){
                        time[j]=max(time[j],list[i][j].first);
                }
                msize = min(msize,int(list[i].size()));
        }

        vector<int> deltime(n,1e9+1);
        for(int i=0;i<w;i++){
                for(int j=0;j<list[i].size();j++){
                        if(j<msize)
                                deltime[list[i][j].second]=time[j];
                }
        }


        int q;
        cin>>q;
        for(;q--;){
                int t,a;
                cin>>t>>a;
                a--;
                if(deltime[a]<t)cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
        }
}
