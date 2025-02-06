#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;
	string As;
	cin>>N>>As;
	vector<pair<int,int>>A(As.size());
	for(int i=0;i<As.size();i++)
	{
		A[i]=make_pair(As[i]-'0',1);
	}
	vector<int> z,o;
	while(A.size()>=3)
	{
		vector<pair<int,int>>B(A.size()/3);
		for(int i=0;i<B.size();i++)
		{
			z.clear();
			o.clear();
			for(int j=0;j<3;j++)
			{
				auto[x,y]=A[i*3+j];
				(x==0?z:o).push_back(y);
			}
			if(z.size()>=2)
			{//0->1
			 	B[i].first=0;
				sort(z.begin(),z.end());
				B[i].second=z[0];
				if(z.size()==3)B[i].second+=z[1];
			}
			else
			{
			 	B[i].first=1;
				sort(o.begin(),o.end());
				B[i].second=o[0];
				if(z.size()==3)B[i].second+=o[1];
			}
		}
		A=B;
	}
	cout << A[0].second << endl;
}
