#include<iostream>
#include<vector>
using namespace std;

struct BIT{
        int n;
        vector<long> bit[2];
        BIT(int _n) : n(_n){
                for(int p = 0; p < 2; p++){
                        bit[p].assign(n,0);
                }
        }

        void add_sub(int p, int i, long x){
                i++;
                for(int idx = i; idx <= n; idx += idx&(-idx)){
                        bit[p][idx-1] += x;
                }
        }
        void add(int i, long x){
                add_sub(0, i, x);
        }
        void add_range(int l, int r, long x){
                add_sub(0,l,-x*(l-1));
                add_sub(0,r,x*(r-1));
                add_sub(1,l,x);
                add_sub(1,r,-x);
        }

        long sum_sub(int p, int i){
                long s = 0;
                i++;
                for(int idx = i; idx > 0; idx -= idx&(-idx)){
                        s += bit[p][idx-1];
                }
                return s;
        }
        long sum(int i){
                return sum_sub(0,i) + i * sum_sub(1,i);
        }
        long get(int i){
                return sum(i)-sum(i-1);
        }
};

int main(){
	int Q;
	cin>>Q;
	BIT bit(2<<17);
	int st=0;
	int cnt=0;
	for(;Q--;){
		int q;
		cin>>q;
		if(q==1){
			cnt++;
		}
		else if(q==2){
			int T;
			cin>>T;
			bit.add_range(0,cnt,T);
		}
		else{
			int H;
			cin>>H;
			int ok=cnt,ng=-1;
			while(ok-ng>1){
				int mid=(ok+ng)/2;
				if(bit.get(mid)>=H)ng=mid;
				else ok=mid;
			}
			cout<<ok-st<<endl;
			st=ok;
		}
	}
}
