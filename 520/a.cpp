#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &p){
	for(int i=0;i<p.size();i++){
		cout<<p[i]<<endl;
	}
}

int main(){
	vector<int> ans;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ctr1=0;
	int k=1;
	int p=n-1;
	
	for(int i=1;i<n;i++){
		int ctr=0;
		while(a[i]-a[i-1]==1){
			ans.push_back(a[i-1]);
			i++;
		}
		ans.push_back(a[i-1]);
		ctr=ans.size()-2;
		if(ans[0]==1){
			ctr++;	
		}
		if(ans[ans.size()-1]==1000){
			ctr++;
		}
		if(ctr>ctr1){
			ctr1=ctr;
		}
		ans.clear();
	}
	cout<<ctr1;
	return 0;
}
