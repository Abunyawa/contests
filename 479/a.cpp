#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	int k;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		if(n%10==0)
			n=n/10;
		else
			n--;
	}
	cout<<n;
	
	return 0;
}
