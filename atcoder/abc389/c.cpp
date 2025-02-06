#include<iostream>
#include<vector>
using namespace std;

int main(){
	long q;
	cin >> q;
	vector<long> hebi(q+1,0);
	long front = 1;
	long index = 1;
	long sub = 0;
	long prev = 0;
	for(;q--;){
		long a;
		cin >> a;
		if(a==1){
			long tmp;
			cin >> tmp;
			hebi[index] = tmp + prev;
			prev = hebi[index];
			index++;
		}
		if(a==2){
			sub += hebi[front]-hebi[front-1];
			front++;
		}
		if(a==3){
			int tmp;
			cin >> tmp;
			cout << hebi[front+tmp-2] - sub << endl;
		}
	}
}
