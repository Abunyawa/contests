#include<iostream>
#include<vector>
using namespace std;
void inc(vector<int> &a,int l,int r,int vk){
	for(int i=l;i<=r;i++){
		if(a[i]!=-1)
			a[i]+=vk;
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	vector<int> a;
	for(int i=0;i<n;i++){
		char x;
		cin>>x;
		a.push_back((int)x-48);
	}
	mx=1;
	for(int i=0;i<a.size();i++){
		if(a[i]==mx){
			mx++;
			a[i]=-1;
			inc(a);
			
		}
	}
	
}
