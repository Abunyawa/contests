#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		long long a,b,k;
		cin>>a>>b>>k;
		int totdif=a-b;
		long long ans=totdif*(k/2)+a*(k%2);
		cout<<ans<<endl;
		;
	}
	
	return 0;
}
