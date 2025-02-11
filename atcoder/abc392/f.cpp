#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct BIT{
        int n;
        vector<int> bit[2];
        BIT(int _n) : n(_n){
                for(int p = 0; p < 2; p++){
                        bit[p].assign(n,0);
                }
        }

        void add_sub(int p, int i, int x){
                i++;
                for(int idx = i; idx <= n; idx += idx&(-idx)){
                        bit[p][idx-1] += x;
                }
        }
        void add(int i, int x){
                add_sub(0, i, x);
        }
        void add_range(int l, int r, int x){
                add_sub(0,l,-x*(l-1));
                add_sub(0,r,x*(r-1));
                add_sub(1,l,x);
                add_sub(1,r,-x);
        }

        int sum_sub(int p, int i){
                int s = 0;
                i++;
                for(int idx = i; idx > 0; idx -= idx&(-idx)){
                        s += bit[p][idx-1];
                }
                return s;
        }
        int sum(int i){
                return sum_sub(0,i) + i * sum_sub(1,i);
        }
        int get(int i){
                return sum(i)-sum(i-1);
        }
};

int main(){
	int N;
	cin>>N;
	vector<int> P(N);
	for(int i=0;i<N;i++){
		cin>>P[i];
	}
	BIT bit(N);
	bit.add_range(0,N,1);
	vector<int> ans(N);
	reverse(P.begin(),P.end());
	for(int i=0;i<N;i++){
		int ok=N,ng=-1;
		while(ok-ng>1){
			int mid=(ok+ng)/2;
			if(bit.sum(mid)>=P[i])ok=mid;
			else ng=mid;
		}
		ans[ok]=N-i-1;
		bit.add(ok,-1);
	}
	for(int i=0;i<N;i++){
		cout<<ans[i]+1<<(i==N-1?"\n":" ");
	}
}
