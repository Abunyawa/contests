#include<iostream>
using namespace std;
int p[1010];
bool ans[1010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>p[i];
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			ans[i]=false;
		}
		int k=j;
	    while(ans[k]==false){
	    	ans[k]=true;
			k=p[k]-1;
		}
		cout<<k+1<<' ';	
	}
	return 0;
}
