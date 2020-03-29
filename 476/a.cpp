#include<iostream>
using namespace std;

int main(){
	int k,n,s,p;
	cin>>k>>n>>s>>p;
	
	long long ans=(n+s-1)/s;
	ans=ans*k;
	ans=(ans+p-1)/p;
	cout<<ans;
	return 0;
}
