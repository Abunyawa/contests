#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	int n,s;
	cin>>n>>s;
	int h,m;
	int ans=-1;
	int time=0;
	for(int i=0;i<n;i++){
		cin>>h>>m;
		int inter=(h*60+m)-time;
		if(i==0){
			if(inter>=s+1 && ans==-1){
				ans=0;
			}	
		}
		if(i==n-1&&ans==-1){
			ans=h*60+m+s+1;
		}
		if(inter>=(2*s+1) && ans==-1){
			ans=time+s;
		}
		time=h*60+m+1;
	}
	cout<<ans/60<<' '<<ans%60;
	return 0;
}
