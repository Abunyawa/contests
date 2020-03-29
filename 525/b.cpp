#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long> a;
int main(){
	int n,k;
	cin>>n>>k;
	long long x;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	long min=0;
	sort(a.begin(),a.end());
	int i=0;
	while(k!=0){
		if(i>=n){
			cout<<0<<endl;
			k--;
		}else if(a[i]-min!=0){
			cout<<a[i]-min<<endl;
			min+=a[i]-min;
			k--;
		}
		
		i++;
	}
	return 0;
}
