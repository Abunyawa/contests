#include<iostream>
using namespace std;
int howmuch(int *a,int n){
	int ctr=0;
	for(int i=0;i<n;i++){
		if(a[i]>a[n]) ctr++;
	}
	return ctr;
}
int howmuchr(int *a,int n,int p){
	int ctr=0;
	for(int i=n-1;i>p;i--){
		if(a[i]>a[p]) ctr++;
	}
	return ctr;
}

bool is_cor(int *a,int *l,int *r,int n){
	for(int i=0;i<n;i++){
		if(l[i]!=howmuch(a,i)){
			return false;
		}
		if(r[i]!=howmuchr(a,n,i)){
			return false;
		}
	}	
	return true;
}
int main(){
	int n;
	cin>>n;
	int l[n];
	int r[n];
	int mx=0;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]>mx){
			mx=l[i];
		}
	}
	for(int i=0;i<n;i++){
		cin>>r[i];
		if(r[i]>mx){
			mx=r[i];
		}
	}
	int max=n;
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=max-l[i]-r[i];
	}
	if(is_cor(arr,l,r,n)){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			cout<<arr[i]<<' ';
		}
	}else{
		cout<<"NO";
	}
	
	return 0;
}
