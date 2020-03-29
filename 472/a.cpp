#include<iostream>
#include<vector>
using namespace std;
char a[110];
int main(){
	int n;
	vector<int> ptr;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]=='?'){
			ptr.push_back(i);
		}
	}
	bool ans(false);
	if(a[0]=='?'||a[n-1]=='?')
		ans=1;
	for(int i=1;i<n-1;i++){
		if(a[i]=='?'){
			int s(1);
			while(a[i+s]=='?'){
				s++;
			}
			if(a[i-1]==a[i+s]){
				ans=1;
				
			}
			i+=s-1;
		}else{
			if((a[i]==a[i-1]&&a[i]!='?')||(a[i]==a[i+1]&&a[i]!='?')){
				cout<<"No";
				return 0;
			}
		}
		
	}
	if(ans==1)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
