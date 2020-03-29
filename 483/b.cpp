#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int s1[]={1,-1,0,0,1,-1,1,-1};
int s2[]={0,0,1,-1,1,-1,-1,1};
char deck[110][110];
int check(int x,int y,int n,int m){
	int counter(0);
	for(int i=0;i<8;i++){
		int xto=x+s1[i];
		int yto=y+s2[i];
		if(xto>=0&&xto<n&&yto>=0&&yto<m&&deck[xto][yto]=='*')
			counter++;
	}
	return counter;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>deck[i][j];
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(deck[i][j]=='.'){
				int ans=check(i,j,n,m);
				if(ans!=0){
					cout<<"NO";
					return 0;
				}
			}
			if(deck[i][j]!='*'&&deck[i][j]!='.'){
				int ans=check(i,j,n,m);
				if(ans!=(int)deck[i][j]-48){
					cout<<"NO";
					return 0;
				}
			}

		}
	cout<<"YES";
	return 0;
}
