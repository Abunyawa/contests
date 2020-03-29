#include<iostream>
using namespace std;
char a[]={'a','e','i','o','u'};
int check(char c){
	for(int i = 0;i<5;i++){
		if(c==a[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	string s;
	getline(cin,s);
	string t;
	getline(cin,t);
	if(t.size()!=s.size()){
		cout<<"No";
		return 0;
	}else{
		for(int i = 0; i<s.size();i++){
			if(check(s[i])!=check(t[i])){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
	
	return 0;
}
