#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		int ans=0;
		cin>>n;
		for(int j=7;j>=2;j--){
			if(n%j!=1){
				ans+=n/j;
				n=n%j;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
