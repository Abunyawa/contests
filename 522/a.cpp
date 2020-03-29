#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int arr[101];
	for(int i=0;i<101;i++){
		arr[i]=0;
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr[x]+=1;
	}
	int nabor=1;
	int mr=0;
	int sum=0;
	for(int i=1;i<101;i++){
		if(arr[i]!=0)
			mr++;
			sum+=arr[i];
		if(arr[i]>k){
			nabor=max((arr[i]+k-1)/k,nabor);
			
		}
	}
	int vsego=nabor*(mr*k);
	int ans=vsego-sum;
	cout<<ans;
	return 0;
}
