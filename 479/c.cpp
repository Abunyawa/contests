#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	int n,k;
	cin>>n>>k;
	vector<ll> a;
	ll p;
	for(int i=0;i<n;i++){
		cin>>p;
		a.push_back(p);
	}
	sort(a.begin(),a.end());
	if(a[k-1]==a[k])
		cout<<"-1";
	else
		cout<<a[k-1];
	return 0;
}
