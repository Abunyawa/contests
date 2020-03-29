#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long ans=0;
	for(int i=2;i<=n;i++){
		for(int j=2;i*j<=n;j++){
			ans+=4*j;	
		}
	}
	cout<<ans;
	return 0;
}
