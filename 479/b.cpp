#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	string s;
	int n;
	cin>>n;
	char a,b;
	int kolvo[26][26];
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++){
			kolvo[i][j]=0;
		}
	cin>>s;
	for(int i=0;i<n-1;i++){
		int a=s[i]-'A';
		int b=s[i+1]-'A';
		kolvo[a][b]+=1;
	}
	int mx=0;
	int x,y;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++){
			if(kolvo[i][j]>mx){
				mx=kolvo[i][j];
				x=i;
				y=j;
			}
		}
	char ans1,ans2;
	ans1=x+'A';
	ans2=y+'A';
	cout<<ans1<<ans2;
	return 0;
}
