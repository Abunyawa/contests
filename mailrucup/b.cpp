#include<iostream>
using namespace std;
int arr[100100];

int fomax(int n){
	int mx=0;
	for(int i=0;i<=n;i++){
		if(arr[i]>mx){
			mx=arr[i];
		}
	}
	
	return mx;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(arr[0]!=0){
		cout<<1;
		return 0;
	}
	int porog=0;
	porog=fomax(1);
	for(int i=0;i<n;i++){
		if(arr[i]>porog+1){
			cout<<i+1;
			return 0;
		}else{
			if(arr[i]>porog){
				porog=arr[i];
			}
		}
	}
	cout<<-1;
	
	return 0;
}
