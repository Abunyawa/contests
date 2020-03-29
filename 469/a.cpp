#include<iostream>
using namespace std;

int main(){
	int l,r,a;
	cin>>l>>r>>a;
	if(l<r){
		if(l+a<=r){
			cout<<2*(l+a);
		}
		else if(l+a>r){
			if(((l+a)-r)%2==0){
				cout<<2*r+((l+a)-r);
			}
			else{
				cout<<2*r+((l+a-1)-r);
			}
		}
	}
	else if(l==r){
		cout<<2*(l+a/2);
	}
	else if(r<l){
		if(r+a<=l){
			cout<<2*(r+a);
		}
		else if(r+a>l){
			if(((r+a)-l)%2==0){
				cout<<2*l+((r+a)-l);
			}
			else{
				cout<<2*l+((r+a-1)-l);
			}
		}
	}
	return 0;
}
