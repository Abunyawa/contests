#include<iostream>
using namespace std;
int numOfInters(int a1,int a2,int b1, int b2){
	int r = min(a2,b2);
	int l = max(a1,b1);
	if (r>l){
		return r-l+1;
	}else if(r==l){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int n;
	cin>>n;
	int ap=0;
	int bp=0;
	int ans = 1;
	for(int i =0;i<n;i++){
		int a;
		int b;
		cin>>a>>b;
		if(a==ap && b == bp){
			continue;
		}
		if(a==0 || b ==0){
			ap = a;
			bp =b;
			continue;
		}
		if(i==0)
			ans+=numOfInters(ap,a,bp,b)-1;
		else
			ans+=numOfInters(ap,a,bp,b);
		
		ap=a;
		bp=b;
	}
	cout<<ans;
}
