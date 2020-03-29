#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int s,a,b,c;
		cin>>s>>a>>b>>c;
		long long ans;
		ans=s/c;
		ans+=(ans/a)*b;
		cout<<ans<<endl;
	}
	
	return 0;
}
