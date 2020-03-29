#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=100000000000;


int main(){
	ios::sync_with_stdio(0);
	int n,k,m;
	cin>>n>>k>>m;
	string arr1[n];
	ll val[n];
	ll mini[k];
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	for(int i=0;i<n;i++)
		cin>>val[i];
	vector<int> syn[k];
	int ptr[n]; 
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		mini[i]=INF;
		for(int j=0;j<x;j++){
			int y;
			cin>>y;
			y--;
			mini[i]=min(mini[i],val[y]);
			ptr[y]=i;
			syn[i].push_back(y);
		}
	}
	ll ans(0);
	string arr2[m];
	for(int i=0;i<m;i++)	
		cin>>arr2[i];
	for(int i=0;i<m;i++){
		ll ans1;
		for(int j=0;j<n;j++){
			if(arr2[i]==arr1[j]){
				ans1=mini[ptr[j]];
			}	
		}
		ans+=ans1;
	}
	cout<<ans;
		
		
		
		
	return 0;
}
