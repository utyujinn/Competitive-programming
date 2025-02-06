#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,x;
	cin >> n >> x;
	long inf = ~0ULL>>1;
	vector<long> dp1(x+1,inf),dp2(x+1,inf),dp3(x+1,inf);
	dp1[0] = 0;
	dp2[0] = 0;
	dp3[0] = 0;
	for(int i = 0 ; i < n; i++){
		long v,a,c;
		cin >> v >> a >> c;
		if(v==1){
			for(int i = x; i >= 0; i--){
				if(dp1[i] != inf && i+c <= x){
					if(dp1[i+c] == inf)dp1[i+c] = dp1[i] + a;
					else dp1[i+c] = max(dp1[i]+a, dp1[i+c]);
				}
			}
		}
		if(v==2){
			for(int i = x; i >= 0; i--){
				if(dp2[i] != inf && i+c <= x){
					if(dp2[i+c] == inf)dp2[i+c] = dp2[i] + a;
					else dp2[i+c] = max(dp2[i]+a, dp2[i+c]);
				}
			}
		}
		if(v==3){
			for(int i = x; i >= 0; i--){
				if(dp3[i] != inf && i+c <= x){
					if(dp3[i+c] == inf)dp3[i+c] = dp3[i] + a;
					else dp3[i+c] = max(dp3[i]+a, dp3[i+c]);
				}
			}
		}
	}
	long tmp1 = 0, tmp2 = 0, tmp3 = 0;
	for(int i =0; i < x+1; i++){
		if(dp1[i] != inf){
			if(dp1[i] < tmp1)dp1[i] = tmp1;
			tmp1 = max(dp1[i], tmp1);
		}else{
			dp1[i] = tmp1;
		}
		if(dp2[i] != inf){
			if(dp2[i] < tmp2)dp2[i] = tmp2;
			tmp2 = max(tmp2, dp2[i]);
		}else{
			dp2[i] = tmp2;
		}
		if(dp3[i] != inf){
			if(dp3[i] < tmp3)dp3[i] = tmp3;
			tmp3 = max(dp3[i],tmp3);
		}else{
			dp3[i] = tmp3;
		}
	}
	long ok = inf, ng = 0;
	while(ok-ng>1){
		long mid = (ok+ng)/2;
		long sum = 0;
		sum += lower_bound(dp1.begin(), dp1.end(), mid) - dp1.begin();
		sum += lower_bound(dp2.begin(), dp2.end(), mid) - dp2.begin();
		sum += lower_bound(dp3.begin(), dp3.end(), mid) - dp3.begin();
		if(sum > x){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}
	cout << ng << endl;
}
