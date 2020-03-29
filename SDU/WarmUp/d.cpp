#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int mx(0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>mx){
			cout<<i+1;
			return 0;
		}else if(arr[i]==mx){
			mx++;
		}
	}
	cout<<-1;
	return 0;
}
