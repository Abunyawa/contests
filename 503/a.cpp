#include<iostream>
using namespace std;

int main(){
	long long n,h,a,b;
	int k;
	cin>>n>>h>>a>>b>>k;
	long long fa,ta,fb,tb;
	while(k!=0){
		k--;
		cin>>ta>>fa>>tb>>fb;
		long long ans(0);
		if(ta==tb){
			cout<<max(fa-fb,fb-fa)<<endl;
		}else
		if(ta==tb&&fa==fb){
			cout<<0<<endl;		
		}else
		if(fa>=a&&fa<=b){
			ans+=max(ta-tb,tb-ta);
			ans+=max(fa-fb,fb-fa);
			cout<<ans<<endl;
		}else{
			long long bliz;
			ans+=min(max(fa-a,a-fa),max(fa-b,b-fa));
			if(max(fa-a,a-fa)>max(fa-b,b-fa)){
				bliz=b;
			}else{
				bliz=a;
			}
			ans+=max(ta-tb,tb-ta);
			ans+=max(bliz-fb,fb-bliz);
			cout<<ans<<endl;
		}
	}	
	
	
	return 0;
}
