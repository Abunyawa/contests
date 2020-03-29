#include<iostream>
using namespace std;
int arr[30];
int main(){
	int n, a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	int i=0;
	int sum(0);
	if(n==1){
		if(arr[0]==2){
			cout<<min(a,b);
			return 0;
		}else{
			return 0;
		}
	}
	int l=0,r(n-1);
	while(l<=r){
		while(arr[l]==arr[r]&&arr[l]!=2){\
			l++;r--;
		}
		if(l>r){
			break;
		}
		if(l==r){
			if(l==2){
				sum+=min(a,b);
			}
			break;
		}else{
			if(arr[l]==2){
				if(arr[r]==1)
					sum+=b;
				if(arr[r]==0)
					sum+=a;
				if(arr[r]==2)
					sum+=2*min(a,b);	
			}
			if(arr[l]==1){
				if(arr[r]==0){
					cout<<-1;
					return 0;
				}
				if(arr[r]==2)
					sum+=b;	
			}
			if(arr[l]==0){
				if(arr[r]==1){
					cout<<-1;
					return 0;
				}
				if(arr[r]==2)
					sum+=a;	
			}
		}
		l++;r--;
	}
	cout<<sum;
	return 0;
}
