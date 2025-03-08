#include<iostream>
using namespace std;
int H,W,N;
struct blick{
	int r,c,l;
}
int main(){
	cin>>H>>W>>N;
	vector<blick> list;
	for(int i=0;i<N;i++){
		int r,c,l;
		cin>>r>>c>>l;
		blick tmp={r,c,l};
		list.push_back(tmp);
	}
	sort(list.begin(),list.end(),[](blick a,blick b){
			return tie(a.r,b.c,a.l)>tie(b.r,a.c,b.l);
		});



