#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int k(1);
	long long a,b;
	bool lol(false);
	int zab=n/2;
	for(int k=1;k<=zab;k++){
		cout<<"? "<<k<<endl;
		cin>>a;
		cout<<flush;
		cout<<"? "<<k+n/2<<endl;
		cin>>b;
		cout<<flush;
		if(a==b){
			cout<<"! "<<k;
			lol=true;
			break;
		}
		if((a-b)%2!=0) {
			cout<<"! -1"<<endl;
			lol=true;
			break;
		}
		if(max(a-b,b-a)>2) {
			k+=(max(a-b,b-a)-2)/2;
		}
		
	}
	if(lol==false){
		cout<<"! -1";
	}
	return 0;
}
