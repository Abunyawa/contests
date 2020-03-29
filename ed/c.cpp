#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long b[n/2];
	for(int i=0;i<n/2;i++){
		cin>>b[i];
	}
	long long a[n];
	long long k=0;
	for(int i=0;i<n/2;i++){
		if(b[i]-k<=a[n-i]){
			a[i]=k;
			a[n-i-1]=b[i]-k;
		}else if(i==0){
			a[i]=k;
			a[n-i-1]=b[i]-k;
		}else{
			k=b[i]-a[n-i];
			i--;
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
