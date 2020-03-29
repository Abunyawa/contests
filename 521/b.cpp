#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int counter(0);
	for(int i=1;i<n-1;i++){
		if(arr[i-1]==arr[i+1] && arr[i]==0 && arr[i+1]==1){
			counter++;
			arr[i+1]=0;
		}
	}
	cout<<counter;
	return 0;
}
