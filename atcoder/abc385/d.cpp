#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	long n,m,sx,sy;
	cin >> n >> m >> sx >> sy;
	vector<long> x(n),y(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	vector<vector<long>> visited(n, vector<long>(n,0));
	vector<long> cx(x.begin(), x.end());
	vector<long> cy(y.begin(), y.end());
	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());
	vector<long> ssx(x.begin(), x.end());
	vector<long> ssy(y.begin(), y.end());
	for(int i = 0; i < n; i++){
		ssx[i] = lower_bound(cx.begin(), cx.end(), x[i])-cx.begin();
		ssy[i] = lower_bound(cy.begin(), cy.end(), x[i])-cy.begin();
	}
	
	long psx = sx;
	long psy = sy;
	long ans = 0;
	for(int i = 0; i < m; i++){
		char d;
		long c;
		cin >> d >> c;
		if(d=='L'){
			sx -= c;
			long ipsx = lower_bound(cx.begin(), cx.end(), psx) - cx.begin();	
			long isx = lower_bound(cx.begin(), cx.end(), sx) - cx.begin();;	
			long isy = lower_bound(cy.begin(), cy.end(), sy) - cy.begin();;	
			for(int i = isx; i < ipsx; i++){
				if(visited[i][isy] == 0){
					ans++;
					visited[i][isy] ++;
				}
			}
		}
		if(d=='R'){
			sx += c;
			long ipsx = lower_bound(cx.begin(), cx.end(), psx) - cx.begin();;	
			long isx = lower_bound(cx.begin(), cx.end(), sx) - cx.begin();;	
			long isy = lower_bound(cy.begin(), cy.end(), sy) - cy.begin();;	
			for(int i = isx-1; i >= ipsx; i--){
				if(visited[i][isy] == 0){
					ans++;
					visited[i][isy] ++;
				}
			}
		}
		if(d=='U'){
			sy += c;
			long ipsy = lower_bound(cy.begin(), cy.end(), psy) - cy.begin();;	
			long isy = lower_bound(cy.begin(), cy.end(), sy) - cy.begin();;	
			long isx = lower_bound(cx.begin(), cx.end(), sx) - cx.begin();;	
			for(int i = isy; i < ipsy; i++){
				if(visited[isx][i] == 0){
					ans++;
					visited[isx][i] ++;
				}
			}
		}
		if(d=='D'){
			sy -= c;
			long ipsy = lower_bound(cy.begin(), cy.end(), psy) - cy.begin();;	
			long isy = lower_bound(cy.begin(), cy.end(), sy) - cy.begin();;	
			long isx = lower_bound(cx.begin(), cx.end(), sx) - cx.begin();;	
			for(int i = isy-1; i >= ipsy; i--){
				if(visited[isx][i] == 0){
					ans++;
					visited[isx][i] ++;
				}
			}
		}
		psx = sx;
		psy = sy;
	}
	cout << sx << " " << sy << " " << ans << endl;
}
