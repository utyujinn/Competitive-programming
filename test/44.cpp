#include<iostream>
#include<vector>
using namespace std;
int main(){
	int m = 1000001;
	vector<bool> boloc(m, false);
	vector<int> dp1(m, 1<<30);
	vector<int> dp2(m, 1<<30);
	for(int i = 0; i*(i+1)*(i+2)/6 < m; i++){
		boloc[i*(i+1)*(i+2)/6] = true;
	}
	dp1[0] = 0; dp2[0] = 0;
	for(int i = 0; i < m; i++){
		if(boloc[i]){
			for(int j = 0; j < m; j++){
				if(j-i >= 0){
					dp1[j] = min(dp1[j], dp1[j-i]+1);
					if(i%2 == 1){
						dp2[j] = min(dp2[j], dp2[j-i]+1);
					}
				}
			}
		}
	}
	int n;
	cin >> n;
	while(n!=0){
		cout << dp1[n] << " " << dp2[n] << endl;
		cin >> n;
	}
}	
