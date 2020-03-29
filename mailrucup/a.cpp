#include<iostream>
using namespace std;

int main(){
	int x,y,z,t1,t2,t3;
	cin>>x>>y>>z>>t1>>t2>>t3;
	int tot1=max(x-y,y-x)*t1;
	int tot2=max(x-z,z-x)*t2+3*t3+max(x-y,y-x)*t2;
	if(tot1<tot2){
		cout<<"NO";
	}else{
		cout<<"YES";
	}
	return 0;
}
