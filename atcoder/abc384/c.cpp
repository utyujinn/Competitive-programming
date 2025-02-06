#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int a[5];
	cin >> a[0] >> a[1]>> a[2] >> a[3] >> a[4];
	vector<pair<int, string>> list(0);
	for(int i = 0; i < 1<<5; i++){
		int sum = 0;
		string s;
		for(int j = 0; j < 5; j++){
			if(i>>j & 1){
				sum += a[j];
				if(j == 0)s.append("A");
				if(j == 1)s.append("B");
				if(j == 2)s.append("C");
				if(j == 3)s.append("D");
				if(j == 4)s.append("E");
			}
		}
		list.push_back(make_pair(-sum, s));
	}
	sort(list.begin(), list.end());
	for(int i = 0; i < 1<<5; i++){
		cout << list[i].second << endl;
	}
}
