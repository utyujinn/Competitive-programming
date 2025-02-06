#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x,y,z,m;
	int ans = 0;
	for(;n--;){
		cin >> x >> y >> z;
		cin >> m;
		int xx,yy,zz;
		int maxx=0,maxy=0,maxz=0;
		int minx=x,miny=y,minz=z;
		for(;m--;){
			cin >> xx >> yy >> zz;
			maxx= max(xx,maxx);
			maxy = max(yy,maxy);
			maxz = max(zz,maxz);
			minx= min(xx,minx);
			miny = min(yy,miny);
			minz = min(zz,minz);
		}
		ans ^= x-maxx-1;
		ans ^= y-maxy-1;
		ans ^= z-maxz-1;
		ans ^= minx;
		ans ^= miny;
		ans ^= minz;
	}
	if(ans == 0)cout << "LOSE" << endl;
	else cout << "WIN" << endl;
}
