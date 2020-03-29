#include<iostream>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		bool flag=1;
		for(int k=s.size()-1;k>0;k--){
			if(s[0]!=s[k]){
				char tmp=s[0];
				s[0]=s[k];
				s[k]=tmp;
				cout<<s<<endl;
				flag=0;
				break;
			}
		}
		if (flag)	cout<<-1<<endl;
	}
	return 0;
}
